import random
import threading

def merge(arr, left, mid, right):
    left_part = arr[left:mid]
    right_part = arr[mid:right]

    i = j = k = 0

    while i < len(left_part) and j < len(right_part):
        if left_part[i] < right_part[j]:
            arr[left + k] = left_part[i]
            i += 1
        else:
            arr[left + k] = right_part[j]
            j += 1
        k += 1

    while i < len(left_part):
        arr[left + k] = left_part[i]
        i += 1
        k += 1

    while j < len(right_part):
        arr[left + k] = right_part[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    if right - left > 1:
        mid = (left + right) // 2

        left_thread = threading.Thread(target=merge_sort, args=(arr, left, mid))
        right_thread = threading.Thread(target=merge_sort, args=(arr, mid, right))

        left_thread.start()
        right_thread.start()

        left_thread.join()
        right_thread.join()

        merge(arr, left, mid, right)

def main():
    arr = [random.randint(1, 100) for _ in range(20)]
    print("Array gerado:", arr)

    merge_sort(arr, 0, len(arr))

    print("Array ordenado:", arr)

if __name__ == "__main__":
    main()
