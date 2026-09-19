#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board,int row,int col, int n){
    //1.check row--horizontal
    for(int i=0; i<n; i++){
        if(board[row][i ]=='Q'){
            return false;
        }
    }
    //check col -- vertical
     for(int i=0; i<row; i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    // left diagonal
     for(int i=row-1,j = col -1; i>=0 && j>=0 ; i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    // right diagonal
    for(int i=row-1,j = col +1; i>=0 && j<n; i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;
}


void nQueens(vector<string>& board,int row, int n,vector<vector<string>>& ans){
     if(row == n){
        ans.push_back(board);
        return;
     }
     // try every col
     for(int j=0; j<n; j++){
        if(isSafe(board,row,j,n)){
            board[row][j] = 'Q';
            // go to next row 
            nQueens(board,row+1,n,ans);
            // backtrack
            board[row][j] = '.';
        }
     }
}

vector<vector<string>> solveNqueens(int n){
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> ans;

    nQueens(board,0,n,ans);

    return ans;
}


int main() {
   int n; 
   cout<<"enter the value of n:";
   cin >> n;

   vector<vector<string>> ans = solveNqueens(n);

   cout<<"total solution : " << ans.size() <<endl;
   for(int i=0; i<ans.size();i++){
      cout<<"Solution " <<i+1 <<": " <<endl;
      for(int j=0; j<n; j++){
        cout<<ans[i][j] <<endl;
      }
   }
    return 0;
}



/*
--------------------------Lab Report----------------------

# Experiment Name

**Write a program to solve the N-Queens problem using backtracking.**

## 1. Objectives

* To understand the backtracking technique for solving constraint satisfaction problems.
* To implement a C++ program that places `N` queens on an `N × N` chessboard such that no two queens attack each other.

## 2. Theory / Illustration

The N-Queens problem requires placing `N` queens on an `N × N` chessboard so that no two queens threaten each other. This means no two queens may share the same row, the same column, or the same diagonal.

Since a brute-force approach checking every possible placement is extremely expensive, the problem is efficiently solved using **backtracking**. In the backtracking approach, queens are placed one per row, starting from row 0. For each row, every column is tried; if placing a queen at that position does not conflict with previously placed queens (i.e., it is "promising"), the algorithm recursively attempts to place a queen in the next row.

If it reaches a row beyond the last row, a valid solution has been found. If no column in the current row works, the algorithm backtracks — it removes the queen placed in the previous row and tries the next available column there. This systematic trial-and-backtrack process explores the solution space efficiently by pruning branches that cannot lead to a valid solution.

* **Time Complexity:** Worst case: **O(N!)**, since backtracking explores row-by-row placements and prunes branches that violate column or diagonal safety; each `isSafe()` check itself takes **O(N)** time.
* **Space Complexity:** **O(N)** for the `col[]` array that records each queen's column, plus **O(N)** recursion stack depth.

## 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Read the value of `n` and initialize an `n × n` chessboard with `.`.
* **Step 3:** Start placing queens from the first row (`row = 0`).
* **Step 4:** For each row, try placing a queen in every column.
* **Step 5:** Check whether the selected position is safe by checking the row, column, left diagonal, and right diagonal.
* **Step 6:** If the position is safe, place a queen (`Q`) in that position.
* **Step 7:** Recursively move to the next row and continue placing queens.
* **Step 8:** If no safe position is available, backtrack by removing the previously placed queen.
* **Step 9:** If `row == n`, all queens are successfully placed; store the solution.
* **Step 10:** Repeat the process until all possible solutions are found.
* **Step 11:** Display the total number of solutions and each valid chessboard configuration.
* **Step 12:** Stop.




*/