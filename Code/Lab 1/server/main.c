#undef UNICODE
#define _WIN32_WINNT 0x0501
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "8080"

int test_tcp_winsocket(clock_t *waiting,
                       int *bytes) {
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    iResult = WSAStartup(MAKEWORD(2, 2),
                         &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo(NULL,
                          DEFAULT_PORT,
                          &hints,
                          &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    ListenSocket = socket(result->ai_family,
                          result->ai_socktype,
                          result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    iResult = bind(ListenSocket,
                   result->ai_addr,
                   (int) result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    closesocket(ListenSocket);
    *bytes = 0;
    clock_t start = clock();
    do {
        iResult = recv(ClientSocket,
                       recvbuf,
                       recvbuflen,
                       0);
        if (iResult > 0) {
            *bytes += iResult;
        } else if (iResult == 0)
            continue;
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

    } while (iResult > 0);

    printf("Bytes received: %d\n", *bytes);
    *waiting = clock() - start;

    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}

int test_udp_winsocket(clock_t *waiting,
                       int *bytes,
                       int number_of_messages) {
    int sockfd;
    WSADATA wsaData;

    sockfd = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (sockfd != 0) {
        printf("WSAStartup failed with error: %d\n", sockfd);
        return 1;
    }

    struct addrinfo hints, *servinfo, *p;
    int rv;
    int numbytes;
    struct sockaddr_storage their_addr;
    char buf[DEFAULT_BUFLEN];
    socklen_t addr_len;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rv = getaddrinfo(NULL,
                          DEFAULT_PORT,
                          &hints,
                          &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        WSACleanup();
        return 1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family,
                             p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("listener: socket");
            continue;
        }
        if (bind(sockfd, p->ai_addr,
                 p->ai_addrlen) == -1) {
            close(sockfd);
            perror("listener: bind");
            continue;
        }
        break;
    }
    if (p == NULL) {
        fprintf(stderr, "listener: failed to bind socket\n");
        WSACleanup();
        return 2;
    }
    *bytes = 0;
    printf("listener: waiting to recvfrom\n");
    addr_len = sizeof their_addr;
    clock_t start = clock();
    for (int i = 0; i < number_of_messages; i++) {
        if ((numbytes = recvfrom(sockfd,
                                 buf,
                                 DEFAULT_BUFLEN,
                                 0,
                                 (struct sockaddr *) &their_addr,
                                         &addr_len)) == -1) {
            perror("recvfrom");
            WSACleanup();
            exit(1);
        }
        *bytes += numbytes;
    }
    printf("listener: packet is %d bytes long\n", *bytes);
    buf[numbytes] = '\0';
    close(sockfd);
    *waiting = clock() - start;
    WSACleanup();
    return 0;
}

int __cdecl main(void) {
    int i = 0;
    clock_t results[10];
    int bytes[10];
    for (; i < 10; i++) {
        int result = test_udp_winsocket(&results[i],
                                        &bytes[i], 100000);
        if (result == 1)
            return result;
        else continue;
    }
    printf("\n\n");

    for (i = 1; i < 11; i++) {
        printf("Iteration %d: time working - %ld, bytes received - %d\n",
               i,
               results[i-1],
               bytes[i-1]);
    }
    sleep(100);
    return 0;
}