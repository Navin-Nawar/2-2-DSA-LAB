#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> &a, int key){
    int st = 0, end = a.size()-1;
    while (st<=end)
    {
        int mid = st + (end -st)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            st = mid+1;
        }
        else{
           end = mid-1;
        }
    }
    return -1;
}
  

int main() {
    int n;
    cout<<"Enter the number of elemnt of an array:";
    cin>>n;
    vector<int>a(n);
    cout<<"Elements of the array: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout<<endl;
    sort(a.begin(),a.end());
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    int key;
    cout<<"enter the search element : ";
    cin >> key;

    int result =  binarySearch(a,key);
    if(result != -1){
        cout<<" Key is found in index : " <<result+1 <<endl;
        cout<< a[result];
    }else{
        cout<<"Key is not found " <<endl;
    }
    
    return 0;
}




/*
------------------------Lab Report--------------------------

# Experiment Name

**Write a program to find an element using the Binary Search algorithm.**

## 1. Objectives

* To understand the working principle of Binary Search.
* To implement Binary Search in C++ to search for an element in a sorted array.
* To analyze the time complexity of Binary Search.

## 2. Theory / Illustration

Binary Search is an efficient searching algorithm that works only on a **sorted array**. It repeatedly divides the search interval in half. At each step, the search key is compared with the middle element of the current interval. If they are equal, the search is successful. If the key is smaller than the middle element, the search continues in the left half; otherwise, it continues in the right half. This process repeats until the element is found or the interval becomes empty.

Because the search space is halved at every step, Binary Search runs in **O(log n)** time in the worst case, which is significantly faster than the **O(n)** time of linear search for large sorted data sets. It requires the array to be sorted beforehand.

* **Time Complexity:**

  * Best case: **O(1)** — key found at the middle on the first comparison.
  * Average case: **O(log n)** — search interval is halved at every step.
  * Worst case: **O(log n)** — search interval is halved until the interval becomes empty.

* **Space Complexity:**

  * **O(1)** for the iterative implementation.
  * **O(log n)** if implemented recursively, due to the recursion call stack.

## 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Read the number of elements `n` and the sorted array `A[0..n-1]`.
* **Step 3:** Read the search element `key`.
* **Step 4:** Set `start = 0` and `end = n - 1`.
* **Step 5:** Repeat Steps 6–9 while `start <= end`.
* **Step 6:** Calculate the middle position: `mid = start + (end - start) / 2`.
* **Step 7:** If `A[mid] == key`, return the index `mid`.
* **Step 8:** If `A[mid] < key`, set `start = mid + 1`; otherwise, set `end = mid - 1`.
* **Step 9:** If `start > end`, return `-1`, indicating that the key is not found.
* **Step 10:** If the result is not `-1`, print that the key is found and display its position.
* **Step 11:** Otherwise, print that the key is not found.
* **Step 12:** Stop.




*/