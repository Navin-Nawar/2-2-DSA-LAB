#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&a,int st,int mid,int end){
    vector<int>temp;
    int i= st,j=mid+1;
    while (i<=mid && j<=end)
    {
        if(a[i]<a[j]){
            temp.push_back(a[i]);
             i++;
        }
        else{
            temp.push_back(a[j]);
           j++;
        }
    }

    while (i<=mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while (j<=end)
    {
        temp.push_back(a[j]);
        j++;
    }
    
    for(int i=0; i<temp.size();i++){
        a[i+st] = temp[i];
    }
    
}

void mergeSort(vector<int>&a,int st,int end){
    if(st>=end) return;
    int mid = st+(end-st)/2;
    
    // left divide
    mergeSort(a,st,mid);
    // right 
    mergeSort(a,mid+1,end);

    merge(a,st,mid,end);
}

int main() {
    int n;
    cout<<"Enter the elemnt of an array:";
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    mergeSort(a,0,n-1);
    cout<<"Sorted Array :" <<endl;
    for(int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    return 0;
}




/*

--------------------------Lab Report------------------------

## Experiment Name:

**Write a program to sort a linear array using the Merge Sort algorithm.**

### 1. Objectives

* To understand the divide-and-conquer strategy used in Merge Sort.
* To implement Merge Sort in C++ to sort a linear array.
* To analyze the time complexity of Merge Sort.

### 2. Theory / Illustration

Merge Sort is a divide-and-conquer sorting algorithm. It divides the input array into two halves, recursively sorts each half, and then merges the two sorted halves into a single sorted array. The key operation is the merge step, which combines two sorted sub-arrays into one sorted array in linear time by comparing the front elements of each sub-array and picking the smaller one at each step. Because the array is always split in half, the recursion has `O(log n)` levels, and each level does `O(n)` work during merging, giving Merge Sort a time complexity of `O(n log n)` in the best, average, and worst cases. It is a stable sorting algorithm, but it requires `O(n)` extra space for the temporary array used during merging.

* **Time Complexity:** Best, average, and worst case: `O(n log n)` — the array is always split into two halves, giving `log n` levels, and each level takes `O(n)` time to merge.
* **Space Complexity:** `O(n)` auxiliary space for the temporary array used while merging, plus `O(log n)` recursion stack space.

### 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Read the number of elements `n` and the array `A[0..n-1]`.
* **Step 3:** Call `MergeSort(A, 0, n-1)` to sort the array.
* **Step 4:** If `start >= end`, return.
* **Step 5:** Calculate the middle position using `mid = start + (end-start)/2`.
* **Step 6:** Recursively divide and sort the left part of the array from `start` to `mid`.
* **Step 7:** Recursively divide and sort the right part of the array from `mid+1` to `end`.
* **Step 8:** Merge the two sorted parts by comparing their elements and placing the smaller element into a temporary array.
* **Step 9:** Copy the elements from the temporary array back into the original array.
* **Step 10:** Repeat the dividing and merging process until the complete array is sorted in ascending order.
* **Step 11:** Print the sorted array `A`.
* **Step 12:** Stop.


*/