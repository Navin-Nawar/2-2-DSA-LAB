#include<bits/stdc++.h>
using namespace std;
 //it will be pivot
int partition(vector<int>&arr,int st,int end){
    int idx = st-1;
    int pivit=arr[end];
    for(int i=st; i<end;i++){
        if(arr[i]<=pivit){
             idx++;
             swap(arr[i],arr[idx]);
        }
    }
    //for pivot in right position
    idx++;
    swap(arr[end],arr[idx]);

    return idx;
}

void quickSort(vector<int>& arr, int st, int end){
    if(st<end){
        int pivitIdx = partition(arr,st,end);

        quickSort(arr,st,pivitIdx-1);//left partition
        quickSort(arr,pivitIdx+1,end);//right partition
    }
}


int main() {
    int n;
    cout<<"Enter the elemnt of an array:";
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    cout<<"Sorted Array :" <<endl;
    for(int i=0; i<n; i++){
        cout << arr[i] <<" ";
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