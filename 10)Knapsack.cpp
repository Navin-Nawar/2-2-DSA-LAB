#include<bits/stdc++.h>
using namespace std;

int profit[] = {15, 25, 13, 23};
int weight[] = {2, 6, 12, 9};

int knapsack01_MemoDP(int W, int n, vector<vector<int>>& dp)
{
    // Base case
    if(n == 0 || W == 0)
        return 0;

    // Already calculated
    if(dp[n][W] != -1)
        return dp[n][W];

    int val = profit[n-1];
    int wt = weight[n-1];

    // If current item can be included
    if(wt <= W)
    {
        int include = val + knapsack01_MemoDP(W-wt, n-1, dp);

        int exclude = knapsack01_MemoDP(W, n-1, dp);

        return dp[n][W] = max(include, exclude);
    }

    // If current item cannot be included
    else
    {
        return dp[n][W] = knapsack01_MemoDP(W, n-1, dp);
    }
}

int main()
{
    int n = 4;
    int W = 20;

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

    int answer = knapsack01_MemoDP(W, n, dp);

    cout << "Maximum Profit = " << answer << endl;

    return 0;
}





/*

-----------------Lab Report------------------

# Experiment Name

**Write a program to solve the 0/1 Knapsack problem using a dynamic programming approach. Profits P = (15, 25, 13, 23), weights W = (2, 6, 12, 9), Knapsack capacity C = 20, number of items n = 4.**

## 1. Objectives

* To understand the dynamic programming approach for solving the 0/1 Knapsack problem.
* To implement a C++ program that computes the maximum achievable profit within a given knapsack capacity.
* To apply the algorithm on `P = (15, 25, 13, 23)`, `W = (2, 6, 12, 9)`, `C = 20`, `n = 4`.

## 2. Theory / Illustration

The **0/1 Knapsack problem** is an optimization problem solved using Dynamic Programming. There are `N` items, each having a weight and a profit. A knapsack has a fixed maximum capacity. For each item, there are only two choices: include or exclude it. An item cannot be partially selected, hence it is called **0/1 Knapsack**.

A DP table is constructed to store the maximum profit for different capacities. If an item's weight exceeds the current capacity, it cannot be included. Otherwise, the maximum of including and excluding the item is considered. The recurrence is based on the maximum profit obtained from these two choices.

For `N` items and capacity `C`, the time complexity is `O(NC)`.

* **Time Complexity:** `O(n × C)`, where `n` is the number of items and `C` is the knapsack capacity. The DP table has `(n+1) × (C+1)` entries.

* **Space Complexity:** `O(n × C)` for the 2-D DP table. This can be reduced to `O(C)` using a single 1-D array if only the maximum profit is required.

## 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Initialize the profit array `P`, weight array `W`, number of items `n`, and knapsack capacity `C`.
* **Step 3:** Create a DP table `dp[n+1][C+1]` and initialize all values with `-1`.
* **Step 4:** Call the Knapsack function with capacity `C` and `n` items.
* **Step 5:** If `n == 0` or `C == 0`, return `0`.
* **Step 6:** If `dp[n][C]` is already calculated, return the stored value.
* **Step 7:** Select the profit and weight of the current item.
* **Step 8:** If the current item's weight is less than or equal to the current capacity, calculate the profit for both **including** and **excluding** the item.
* **Step 9:** Store the maximum of the include and exclude profits in `dp[n][C]`.
* **Step 10:** If the current item's weight is greater than the capacity, exclude the item and calculate the result for the remaining items.
* **Step 11:** Return the maximum profit obtained from the DP table.
* **Step 12:** Display the maximum profit.
* **Step 13:** Stop.


*/