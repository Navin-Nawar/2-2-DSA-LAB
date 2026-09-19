#include<bits/stdc++.h>
using namespace std;

int cnt =0;
void towerOfHanoi(int n, char source,char helper,char destination){
    if(n==1){
        cout<<"Move disk 1 from " <<source <<" to "
        <<destination <<endl;  
        cnt++;
        return;
    }

    // move n-1 disk from source to helper 
    towerOfHanoi(n-1,source,destination,helper);
    // move largest disk from source to destination
    cout<<"Move disk " <<n <<" from "
    <<source <<" to " <<destination <<endl;

    cnt++;

    // move n-1 disk from helper to destination using source as a helper
    towerOfHanoi(n-1,helper,source,destination);
}

int main() {
    int n;
    cout<<"Enter the number of disks: ";
    cin>> n;
    towerOfHanoi(n,'A','B','C');
    cout<<"Total moves : " <<cnt <<endl;
    return 0;
}




/*
---------------------Lab Report---------------------

# Experiment Name

**Write a program to solve the Tower of Hanoi problem for N disks.**

## 1. Objectives

* To understand the recursive approach for solving the Tower of Hanoi problem.
* To implement a C++ program that prints the sequence of moves needed to transfer `N` disks from a source rod to a destination rod using an auxiliary rod.
* To analyze the time complexity of the Tower of Hanoi algorithm.

## 2. Theory / Illustration

Tower of Hanoi is a well-known problem that demonstrates the concept of **recursion**. It consists of three rods: **Source, Auxiliary, and Destination**. There are `N` disks of different sizes initially placed on the Source rod. The main objective is to move all disks from the Source rod to the Destination rod.

The rules are:

* Only one disk can be moved at a time.
* Only the top disk of a rod can be moved.
* A larger disk cannot be placed on a smaller disk.

To move `N` disks, first move `N−1` disks from Source to Auxiliary. Then move the largest disk from Source to Destination. Finally, move the `N−1` disks from Auxiliary to Destination. The problem is solved efficiently using a recursive algorithm.

The minimum number of moves required is `2^N − 1`.

* **Time Complexity:** `O(2^N)`, since the number of moves follows the recurrence `T(N) = 2T(N-1) + 1`, which gives `T(N) = 2^N − 1`.

* **Space Complexity:** `O(N)` for the recursion call stack, corresponding to the maximum recursion depth of `N`.

## 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Read the number of disks `n`.
* **Step 3:** Set three rods: `source = A`, `helper = B`, and `destination = C`.
* **Step 4:** If `n == 1`, move disk 1 from the source rod to the destination rod and count the move.
* **Step 5:** Otherwise, recursively move `n-1` disks from the source rod to the helper rod using the destination rod.
* **Step 6:** Move the largest disk `n` from the source rod to the destination rod and count the move.
* **Step 7:** Recursively move the `n-1` disks from the helper rod to the destination rod using the source rod.
* **Step 8:** Repeat Steps 4–7 until all disks are moved to the destination rod.
* **Step 9:** Display the total number of moves.
* **Step 10:** Stop.


*/