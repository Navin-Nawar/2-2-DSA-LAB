#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pattern,vector<int>& lps){
    int len =0;
    int i =1;

    lps[0] =0;
    while (i<pattern.length())
    {
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len !=0){
                len = lps[len - 1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    
}


void KMP(string text, string pattern){
    int n = text.length();
    int m = pattern.length();

    vector<int>lps(m);

    computeLPS(pattern,lps);
    int i=0;
    int j=0;
    while (i<n)
    {
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"Pattern is found at index : " 
            <<i-j <<endl;

            j = lps[j-1];
        }
        else if(i<n && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    

}

int main() {
    ifstream file("text.txt");

    if(!file){
        cout<<"File could not be opened." <<endl;
        return 0;
    } 
    string text;
    getline(file,text);

    cout<<text <<endl;
    
    file.close();

    string pattern;
    cout<<"Enter pattern: ";
    cin >> pattern;

    KMP(text,pattern);

    return 0;
}




/*

-------------------Lab Report------------------------

# Experiment Name

**Write a program to find a given pattern from text using the Knuth-Morris-Pratt (KMP) pattern matching algorithm.**

## 1. Objectives

* To understand the concept of pattern matching using the KMP algorithm.
* To implement the KMP algorithm in C++ to locate a pattern within a text.
* To analyze the time complexity of the KMP algorithm.

## 2. Theory / Illustration

KMP is an efficient pattern matching algorithm used to search a pattern in a text. It avoids unnecessary comparisons while searching for the pattern.

The algorithm preprocesses the pattern before starting the search. It constructs an array called **LPS (Longest Proper Prefix which is also Suffix)**. The LPS array stores information about previously matched characters. When a mismatch occurs, the LPS value determines the next position to compare. Thus, already matched characters do not need to be checked again.

KMP uses two main steps: **pattern preprocessing** and **pattern searching**. The preprocessing complexity is **O(M)** for a pattern of length M. The searching complexity is **O(N)** for a text of length N. Therefore, the overall complexity is **O(N + M)**. KMP is useful for efficient text and string searching.

* **Time Complexity:**

  * Preprocessing (building the LPS array): **O(m)**
  * Searching phase: **O(n)**
  * Overall time complexity: **O(n + m)**, where `n` = length of text and `m` = length of pattern.

* **Space Complexity:**

  * **O(m)** auxiliary space for storing the LPS array.

## 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Open the file `text.txt` and read the text.
* **Step 3:** Read the pattern to be searched.
* **Step 4:** Compute the **LPS (Longest Proper Prefix which is also Suffix)** array for the pattern.
* **Step 5:** Set `i = 0` for the text and `j = 0` for the pattern.
* **Step 6:** Repeat the following steps while `i < n`.
* **Step 7:** If `text[i] == pattern[j]`, increment both `i` and `j`.
* **Step 8:** If `j == m`, the pattern is found at index `i - j`. Print the index and set `j = lps[j-1]` to continue searching.
* **Step 9:** If the characters do not match and `j != 0`, set `j = lps[j-1]`.
* **Step 10:** If the characters do not match and `j == 0`, increment `i`.
* **Step 11:** Repeat the process until the entire text is checked.
* **Step 12:** Stop.




*/