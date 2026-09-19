#include<bits/stdc++.h>
using namespace std;

vector<int> st;

// Push
void pushElement()
{
    int n, value;

    cout << "How many elements do you want to push: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        st.push_back(value);
    }
}

// Pop
void popElement()
{
    if(st.empty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << st.back() << " removed from stack." << endl;

    st.pop_back();
}

// Peek
void peek()
{
    if(st.empty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Top element: " << st.back() << endl;
}

// Display
void display()
{
    if(st.empty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack: ";

    for(int i = st.size() - 1; i >= 0; i--)
    {
        cout << st[i] << " ";
    }

    cout << endl;
}

// Check Empty
void isEmpty()
{
    if(st.empty())
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;
}


int main()
{
    int choice;

    while(true)
    {
        cout << "\n----- Stack Menu -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                pushElement();
                display();
                break;

            case 2:
                popElement();
                display();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                cout << "Program ended." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}





/*

------------Lab Report---------------

# Experiment Name

**Write a program to implement a Stack data structure along with its typical operations.**

## 1. Objectives

* To understand the concept and working principle of a Stack (**LIFO structure**).
* To implement the basic operations of a Stack — **push, pop, peek/top,** and **isEmpty** — using an array in C++.

## 2. Theory / Illustration

A Stack is a linear data structure that follows the **LIFO (Last In, First Out)** principle. The element inserted last is removed first. Insertion of an element is called **Push**. Removal of an element is called **Pop**. The topmost element can be accessed using the **Peek/Top** operation.

A stack can be implemented using an array or linked list. The **Top** variable is used to keep track of the top element. When a stack is empty and Pop is performed, **Underflow** occurs. When an array stack is full and Push is performed, **Overflow** occurs.

Push, Pop, and Peek operations generally take **O(1)** time. Stacks are used in recursion, function calls, expression evaluation, and backtracking. They are also widely used for checking balanced parentheses.

* **Time Complexity:** Push, Pop, Peek, and isEmpty each run in **O(1)** constant time with the array-based implementation used here.
* **Space Complexity:** **O(n)** to store `n` elements in the stack array; **O(1)** extra auxiliary space beyond the array itself.

## 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Initialize an empty stack `S`.
* **Step 3:** Display the Stack Menu and read the user's choice.
* **Step 4:** If the choice is **Push**, read the number of elements and insert them at the top of the stack.
* **Step 5:** If the choice is **Pop**, check if the stack is empty; otherwise, remove the top element.
* **Step 6:** If the choice is **Peek**, check if the stack is empty; otherwise, display the top element.
* **Step 7:** If the choice is **Display**, check if the stack is empty; otherwise, display all elements from top to bottom.
* **Step 8:** If the choice is **Check Empty**, check whether the stack is empty or not.
* **Step 9:** If the choice is **Exit**, terminate the program.
* **Step 10:** If an invalid choice is entered, display **"Invalid choice."**
* **Step 11:** Display the updated stack after Push or Pop operations.
* **Step 12:** Repeat Steps 3–11 until the user selects **Exit**.
* **Step 13:** Stop.


*/