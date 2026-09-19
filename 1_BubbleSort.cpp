#include<iostream>
using namespace std;
int main(){
    int n;
     cout<<"number of elements in an array: ";
     cin>> n;

     int arr[100];
     for(int i=0; i<n; i++) cin >> arr[i];
     cout<<"before sorting : " ;
     for(int i=0; i<n; i++) cout<<arr[i] <<" " ;
     cout<<endl;
     for(int i=0; i<n-1; i++){
        bool swaped = false;
        for(int j=0; j<n-i-1; j++ ){
            if(arr[j]<arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swaped = true;
            }

        }
       
        cout<<"pass " <<i+1 <<":";
        for(int i=0; i<n; i++) cout<<arr[i] <<" ";
        cout<<endl;
         if(!swaped) break;

     }

     cout<<"sorted array :";
      for(int i=0; i<n; i++) cout<<arr[i] <<" ";
}


/* 
                                  Lab Report

## Experiment Name:

**Write a program to sort a linear array using the Bubble Sort algorithm.**

### 1. Objectives

* To understand the working principle of the Bubble Sort algorithm.
* To implement Bubble Sort in C++ to arrange elements of a linear array in **descending order**.
* To analyze the time complexity of Bubble Sort.

### 2. Theory / Illustration

* Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly compares two adjacent elements of an array. If the elements are in the wrong order, they are swapped. In this program, if the left element is smaller than the right element, they are swapped, so the largest elements move toward the beginning of the array. The process continues until the entire array becomes sorted. For an array of `N` elements, at most `N−1` passes are required. Bubble Sort can be implemented using nested loops. It is easy to understand and implement. Its average and worst-case time complexity is `O(N²)`. Its best-case time complexity can be `O(N)` when optimized using a swap flag. The space complexity is `O(1)` because it sorts in-place. It is suitable for small or nearly sorted datasets.
* **Time Complexity:** Best case (already sorted, with the swap flag): `O(n)`. Average case: `O(n²)`. Worst case (reverse sorted array): `O(n²)`.
* **Space Complexity:** `O(1)` auxiliary space — Bubble Sort is an in-place algorithm and uses only a constant number of extra variables.

### 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Read the number of elements `n` and the array `A[0..n-1]`.
* **Step 3:** For `i = 0` to `n-2`, repeat Step 4.
* **Step 4:** For `j = 0` to `n-2-i`, repeat Step 5.
* **Step 5:** If `A[j] < A[j+1]`, then swap `A[j]` and `A[j+1]`.
* **Step 6:** If no swapping occurs in a pass, stop the sorting process.
* **Step 7:** After all passes, array `A` is sorted in **descending order**.
* **Step 8:** Print the sorted array `A`.
* **Step 9:** Stop.


*/