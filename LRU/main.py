from decoration.colors import *

from LRU import lru_algorithm as lru
from LRU_2 import lru2_algorithm as lru2
from LRFU import lrfu_algorithm as lrfu


def print_table_memory(pages, styles):
    for i in range(4):
        # print(str(2 * i) + " " * 39 + str(2 * i + 1))
        first = " "
        second = " "
        if 2 * i in pages:
            first = styles[2 * i] + "#"
        if 2 * i + 1 in pages:
            second = styles[2 * i + 1] + "#"
        print("-" * 20 + " " * 20 + "-" * 20)
        print("|" + first * 18 + WHITE + "|"
              + " " * 20
              + "|" + second * 18 + WHITE + "|")
        print("-" * 20 + " " * 20 + "-" * 20)


# def colors_print():
#     print(PURPLE + "Hello 1234!@#$-|")
#     print(BLUE + "Hello 1234!@#$-|")
#     print(CYAN + "Hello 1234!@#$-|")
#     print(GREEN + "Hello 1234!@#$-|")
#     print(YELLOW + "Hello 1234!@#$-|")
#     print(RED + "Hello 1234!@#$-|")
#     print(WHITE + "Hello 1234!@#$-|")
#     print(BOLD + "Hello 1234!@#$-|")
#     print(UN_BOLD + "Hello 1234!@#$-|")


def all_to_blue(styles):
    for i in styles.keys():
        styles[i] = BLUE


def simulate(list_of_references):
    pages = []
    styles = {}
    last_usage = {}
    referenced = {}
    for i in range(8):
        referenced[i] = 0
    iteration = 0
    for i in list_of_references:
        all_to_blue(styles)
        if i in pages:
            last_usage[i] = iteration
            referenced[i] += 1
        else:
            print(RED + "Page fault" + WHITE)
            if len(pages) > 3:
                # index_to_delete = lru(pages, last_usage)
                # index_to_delete = lru2(pages, last_usage)
                index_to_delete = lrfu(pages, last_usage, referenced)
                last_usage.pop(pages[index_to_delete])
                styles.pop(pages[index_to_delete])
                referenced[pages[index_to_delete]] = 0
                pages[index_to_delete] = i
            else:
                pages.append(i)
                referenced[i] = 1
            all_to_blue(styles)
            last_usage[i] = iteration
        styles[i] = GREEN
        print_table_memory(pages, styles)
        input("Press enter to continue")
        iteration += 1


if __name__ == '__main__':
    # simulate([7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3])
    # simulate([7, 0, 1, 2, 0, 3, 0, 4, 7, 7, 0, 7, 2, 7])
    simulate([7, 0, 1, 2, 0, 0, 3, 1, 2, 7, 7, 0, 7, 2, 7])
