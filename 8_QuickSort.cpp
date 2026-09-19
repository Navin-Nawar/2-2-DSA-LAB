#include <iostream>
using namespace std;

int partitionArray(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partitionArray(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == key)
            return mid;

        else if (a[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, a[100], key;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    int position = binarySearch(a, n, key);

    if (position != -1)
    {
        cout << "\nElement found at position "
             << position + 1 << endl;
    }
    else
    {
        cout << "\nElement not found in the array." << endl;
    }

    return 0;
}


/*
---------Lab Report-----------

# Experiment Name

**Write a program to find an element using a Quick Sort algorithm.**

## 1. Objectives

* To understand the divide-and-conquer strategy used in Quick Sort.
* To implement Quick Sort in C++ to sort a linear array (and thereby locate any element in the sorted output).
* To analyze the time complexity of Quick Sort.

## 2. Theory / Illustration

Quick Sort is an efficient **divide-and-conquer sorting algorithm**. It selects an element from the array as a **pivot**. The remaining elements are partitioned around the pivot. Elements smaller than the pivot are placed on one side, while elements greater than the pivot are placed on the other side.

The same process is recursively applied to the two subarrays. When the subarrays contain one or zero elements, they are considered sorted. The choice of pivot affects the performance of Quick Sort. Its average-case time complexity is **O(N log N)**. Its worst-case time complexity is **O(N²)** when partitioning is highly unbalanced.

Quick Sort generally requires **O(log N)** auxiliary stack space on average. It is widely used because of its good practical performance.

* **Time Complexity:**

  * Best case: **O(n log n)**
  * Average case: **O(n log n)**
  * Worst case: **O(n²)** — for example, an already sorted array with a poor pivot choice such as always selecting the last element.

* **Space Complexity:**

  * Average case: **O(log n)** auxiliary space for the recursion stack.
  * Worst case: **O(n)** recursion depth.

## 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Read the number of elements `n` and the array `A[0..n-1]`.
* **Step 3:** Call `QuickSort(A, 0, n-1)`.
* **Step 4:** Select the last element as the **pivot**.
* **Step 5:** Partition the array by placing elements smaller than or equal to the pivot on its left side.
* **Step 6:** Place the pivot in its correct position and get its index.
* **Step 7:** Recursively apply Quick Sort to the left partition.
* **Step 8:** Recursively apply Quick Sort to the right partition.
* **Step 9:** Repeat the process until each partition contains zero or one element.
* **Step 10:** Display the sorted array.
* **Step 11:** Stop.



*/