def lrfu_algorithm(pages: list[int], last_used, referenced):
    ranged = []
    for i in last_used.keys():
        ranged.append(last_used[i])
    ranged.sort()
    priority = {}
    for i in range(4):
        for j in last_used.keys():
            if ranged[i] == last_used[j]:
                priority[j] = i + referenced[j]
                break

    page_to_delete = pages[0]
    min_priority = priority[page_to_delete]
    for i in priority.keys():
        if priority[i] < min_priority:
            page_to_delete = i
            min_priority = last_used[i]
    for i in range(4):
        if pages[i] == page_to_delete:
            return i
