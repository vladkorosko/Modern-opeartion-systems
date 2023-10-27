#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0501

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_PORT "8080"

const char* messages[3] = {
     "Hello world",
     "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\n",
     "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore"
     " magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies"
     " mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis"
     " enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec "
     "ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel "
     "pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\n"
     "Malesuada fames ac turpis egestas integer eget. Morbi blandit cursus risus at. Aliquet nec ullamcorper sit amet "
     "risus nullam eget felis. Auctor elit sed vulputate mi sit amet mauris commodo. Nisl pretium fusce id velit ut "
     "tortor pretium. Mauris in aliquam sem fringilla ut. Vulputate eu scelerisque felis imperdiet proin fermentum leo "
     "vel orci. Quis viverra nibh cras pulvinar mattis nunc sed blandit libero. Tellus in hac habitasse platea dictumst"
     " vestibulum. Sed arcu non odio euismod lacinia. Scelerisque mauris pellentesque pulvinar pellentesque habitant "
     "morbi tristique. Ac felis donec et odio pellentesque diam volutpat. Turpis massa sed elementum tempus egestas sed"
     " sed risus. Lorem ipsum dolor sit amet consectetur. Odio ut sem nulla pharetra diam sit amet. Imperdiet nulla "
     "malesuada pellentesque elit. Amet nisl suscipit adipiscing bibendum. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\n Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Non quam lacus suspendisse faucibus interdum posuere. Sit amet aliquam id diam maecenas ultricies mi eget. Vulputate mi sit amet mauris. Vulputate eu scelerisque felis imperdiet. Massa enim nec dui nunc mattis enim ut. Ullamcorper eget nulla facilisi etiam. Nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices. Magna fringilla urna porttitor rhoncus dolor purus. Lectus proin nibh nisl condimentum. Nisl vel pretium lectus quam id. Eget felis eget nunc lobortis mattis aliquam faucibus.\n"
};

int test_tcp_winsocket(char **argv,
                       clock_t *life_time,
                       clock_t *sending,
                       int *bytes,
                       int number_of_messages,
                       int index_m) {
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
            *ptr = NULL,
            hints;

    const char *sendbuf = messages[index_m];
    int iResult;

    clock_t start = clock();

    iResult = WSAStartup(MAKEWORD(2, 2),
                         &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    iResult = getaddrinfo(argv[1],
                          DEFAULT_PORT,
                          &hints,
                          &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        ConnectSocket = socket(ptr->ai_family,
                               ptr->ai_socktype,
                               ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %d\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        iResult = connect(ConnectSocket,
                          ptr->ai_addr,
                          (int) ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }
    *bytes = 0;

    clock_t start_sending = clock();
    for (int i = 0; i < number_of_messages; i++) {
        iResult = send(ConnectSocket,
                       sendbuf,
                       (int) strlen(sendbuf),
                       0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }
        *bytes += iResult;
    }
    printf("Bytes Sent: %d\n", *bytes);

    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    *sending = clock() - start_sending;

    *life_time = clock() - start;
    closesocket(ConnectSocket);
    WSACleanup();
    return 0;
}

int test_udp_winsocket(char **argv,
                       clock_t *life_time,
                       clock_t *sending,
                       int *bytes,
                       int number_of_messages,
                       int index_m) {

    WSADATA wsaData;
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int numbytes;

    const char *sendbuf = messages[index_m];

    // Initialize Winsock
    clock_t birth = clock();
    sockfd = WSAStartup(MAKEWORD(2, 2),
                        &wsaData);
    if (sockfd != 0) {
        printf("WSAStartup failed with error: %d\n", sockfd);
        return 1;
    }
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    if ((rv = getaddrinfo(argv[1],
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
            perror("talker: socket");
            continue;
        }
        break;
    }
    if (p == NULL) {
        fprintf(stderr, "talker: failed to bind socket\n");
        WSACleanup();
        return 2;
    }
    *bytes = 0;
    clock_t start = clock();
    for (int i = 0; i < number_of_messages; i++) {
        if ((numbytes = sendto(sockfd,
                               sendbuf,
                               strlen(sendbuf),
                               0,
                               p->ai_addr,
                               p->ai_addrlen)) == -1) {
            perror("talker: sendto");
            WSACleanup();
            exit(1);
        }
        *bytes += numbytes;
    }
    printf("talker: sent %d bytes to %s\n", *bytes, argv[1]);
    close(sockfd);
    *sending = clock() - start;
    *life_time = clock() - birth;

    WSACleanup();
    return 0;
}

int __cdecl main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: %s server-name\n", argv[0]);
        return 1;
    }

    int i = 0;
    clock_t life[10];
    clock_t sending[10];
    int bytes[10];
    for (; i < 10; i++) {
        int result = test_udp_winsocket(argv,
                                        &life[i],
                                        &sending[i],
                                        &bytes[i],
                                        100000,
                                        2);
        if (result == 1)
            return result;
        else continue;
    }
    printf("\n\n");

    for (i = 0; i < 10; i++) {
        printf("Iteration %d: time working - %ld, bytes send - %d, time sending - %ld\n",
               i+1,
               life[i],
               bytes[i],
               sending[i]);
    }

    sleep(100);
    return 0;
}