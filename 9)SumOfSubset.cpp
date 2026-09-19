#include<bits/stdc++.h>
using namespace std;

int S[] = {5, 10, 12, 13, 15, 18};
int n = 6;
int d = 30;

int solutionCount = 0;

void subsetSum(int index, int sum, vector<int>& subset)
{
    // Target sum found
    if(sum == d)
    {
        solutionCount++;

        cout << "Subset " << solutionCount << " : { ";

        for(int x : subset)
        {
            cout << x << " ";
        }

        cout << "}" << endl;

        return;
    }

    // Stop current branch
    if(index == n || sum > d)
    {
        return;
    }

    // -------- TAKE --------
    subset.push_back(S[index]);

    subsetSum(index + 1,
              sum + S[index],
              subset);

    // -------- BACKTRACK --------,,je elemnt niye desire solution pai ni seta bad dibo jate onno ta diye try kora jay
    subset.pop_back();

    // -------- DON'T TAKE --------
    subsetSum(index + 1,
              sum,
              subset);
}

int main()
{
    vector<int> subset;

    // Print the given set
    cout << "Given Set S = { ";

    for(int i = 0; i < n; i++)
    {
        cout << S[i] << " ";
    }

    cout << "}" << endl;

    // Print target
    cout << "Target Sum d = " << d << endl;

    cout << endl;
    cout << "Subsets whose sum is " << d << ":" << endl;

    // Backtracking -- index,sum,subset
    subsetSum(0, 0, subset);

    cout << endl;
    cout << "Total solutions = " << solutionCount << endl;

    return 0;
}

/*
----------Lab Report------------

# Experiment Name

**Consider a set S = {5, 10, 12, 13, 15, 18} and d = 30. Write a program to solve the Sum of Subset problem.**

## 1. Objectives

* To understand the backtracking approach for solving the Sum of Subset problem.
* To implement a C++ program that finds all subsets of a given set `S` whose elements sum exactly to a given value `d`.
* To apply the algorithm on `S = {5, 10, 12, 13, 15, 18}` with `d = 30`.

## 2. Theory / Illustration

* The **Sum of Subset problem** is a classical backtracking problem. It determines whether a subset of given elements has a specified sum. For this problem, the given set is `S = {5, 10, 12, 13, 15, 18}` and the target sum is `30`. The algorithm considers each element either selected or not selected.

* This creates different possible subsets of the given set. For every choice, the current sum is calculated. If the current sum becomes equal to the target, a solution is found. If the current sum exceeds the target, that branch can be discarded. The algorithm then backtracks to explore other possibilities. This avoids unnecessary exploration of some invalid combinations.

* The worst-case time complexity is generally `O(2^n)`. Backtracking is useful for finding one or all subsets satisfying the required sum.

* **Time Complexity:** Worst case: `O(2^n)`, since every element has two choices: include or exclude. The bound (promising) checks prune many branches in practice, giving better performance for suitable inputs.

* **Space Complexity:** `O(n)` for the recursion stack depth and the subset array used to hold the elements currently included.

## 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Initialize the set `S`, target sum `d`, and an empty subset.
* **Step 3:** Start from `index = 0` with `sum = 0`.
* **Step 4:** If `sum == d`, print the current subset as a solution.
* **Step 5:** If `index == n` or `sum > d`, stop the current branch.
* **Step 6:** **Take** `S[index]` by adding it to the subset and recursively call the function for the next element.
* **Step 7:** **Backtrack** by removing `S[index]` from the subset.
* **Step 8:** **Don't Take** `S[index]` and recursively call the function for the next element.
* **Step 9:** Repeat Steps 6–8 until all possible subsets are checked.
* **Step 10:** Count and display all subsets whose sum is equal to `d`.
* **Step 11:** Stop.


*/