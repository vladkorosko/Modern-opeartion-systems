def lru_algorithm(pages: list[int], last_used):
    page_to_delete = pages[0]
    time_referenced = last_used[page_to_delete]
    for i in last_used.keys():
        if last_used[i] < time_referenced:
            page_to_delete = i
            time_referenced = last_used[i]
    for i in range(4):
        if pages[i] == page_to_delete:
            return i
