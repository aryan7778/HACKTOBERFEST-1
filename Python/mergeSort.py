import random
import time
import argparse

def merge(left, right):
    """
    Function that merges two halves of an array into a new one. While inserted,
    elements are ordered.

    :param left: Left part of the array.
    :param right: Right part of the array.
    :returns: Returns a sorted array which contains the elements of the two halves.
    """
    sorted_arr = []
    i, j = 0, 0

    # Insert elements in an ordered fashion
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_arr.append(left[i])
            i += 1
        else:
            sorted_arr.append(right[j])
            j += 1

    # Add missing elements
    sorted_arr.extend(left[i:])
    sorted_arr.extend(right[j:])

    return sorted_arr


def merge_sort(arr):
    """
    Function that sorts a given input array using the Merge Sort algorithm.
    The given array remains unchanged.

    :param arr: Array to be sorted.
    :returns: Returns a sorted copy of the input array.
    """
    # Base case
    if len(arr) == 1:
        return arr
    else:
        # Split array into two halves and sort them recursively
        mid_idx = len(arr) // 2
        left_arr, right_arr = arr[:mid_idx], arr[mid_idx:]

        return merge(merge_sort(left_arr), merge_sort(right_arr))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Run Merge Sort algorithm on an array filled with random numbers.",
                                     allow_abbrev=False)

    parser.add_argument('-u',
                        '--upper',
                        action='store',
                        type=int,
                        dest='upper_bound',
                        help='Upper bound of the random number generator.',
                        required=True)

    parser.add_argument('-l',
                        '--lower',
                        action='store',
                        type=int,
                        dest='lower_bound',
                        help='Lower bound of the random number generator.',
                        required=True)

    parser.add_argument('-n',
                        '--numbers',
                        action='store',
                        type=int,
                        dest='n',
                        help='Number of random elements that will be generated.',
                        required=True)

    args = parser.parse_args()

    # Set random seed
    random.seed(42)

    arr = [random.randint(args.lower_bound, args.upper_bound) for _ in range(args.n)]

    t1 = time.time()
    sorted_arr = merge_sort(arr)
    t2 = time.time()

    print(f"Sorted array in {t2 - t1} seconds")
    print(f"\nOriginal array:\n{arr}\n")
    print(f"\nSorted array:\n{sorted_arr}")
