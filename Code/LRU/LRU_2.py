def lru2_algorithm(pages: list[int], last_used):
    page_to_delete = [pages[0], pages[1]]
    time_referenced = [last_used[page_to_delete[0]], last_used[page_to_delete[1]]]
    for i in last_used.keys():
        if last_used[i] < max(time_referenced[0], time_referenced[1]) and i not in page_to_delete:
            for j in range(2):
                if time_referenced[j] == max(time_referenced[0], time_referenced[1]):
                    page_to_delete[j] = i
                    time_referenced[j] = last_used[i]
                    break
    for i in range(4):
        if page_to_delete[0] == pages[i]:
            return i
        if page_to_delete[1] == pages[i]:
            return i
