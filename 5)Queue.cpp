#include<bits/stdc++.h>
using namespace std;

vector<int> q;
void display(){
    if(q.empty()){
        cout<<"Queue is empty." <<endl;
        return;
    }
    for(int x: q){
        cout<<x <<" " ;
    }
    cout<<endl;
}

void enqueue(){
    int n, value;

    cout << "How many elements do you want to enqueue: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        q.push_back(value);
    }
}

void dequeue(){
    if(q.empty()){
        cout<<"Queue is empty." <<endl;
        return;
    }
    cout<<q.front()<<"Removed from queue"<<endl;
    q.erase(q.begin());

    display();
}

void peek(){
    if(q.empty()){
        cout<<"Queue is empty." <<endl;
        return;
    }

    cout<<"Front element" <<q.front() <<endl;
}

void isEmpty(){
    if(q.empty()){
        cout<<"Queue is empty." <<endl;
    }
    else{
        cout<<"Queue is not empty." <<endl;
    }
}
int main() {
     int choice;
     int value;

    while(true)
    {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                // cout << "Enter value: ";
                // cin >> value;

                enqueue();
                display();
                break;

            case 2:
                dequeue();
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
                cout << "Program terminated." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}



/*

--------------------Lab Report----------------

# Experiment Name

**Write a program to implement a Queue data structure along with its typical operations.**

## 1. Objectives

* To understand the concept and working principle of a Queue (**FIFO structure**).
* To implement the basic operations of a Queue — **enqueue, dequeue, peek/front, isEmpty,** and **isFull** — using an array in C++.

## 2. Theory / Illustration

A Queue is a linear data structure that follows the **First In First Out (FIFO)** principle, meaning the element inserted first is the element removed first, just like a queue of people waiting in a line.

A queue has two ends: the **rear (or back)**, where new elements are inserted (**enqueue**), and the **front**, from which elements are removed (**dequeue**).

The typical operations on a queue are:

* **Enqueue:** Insert an element at the rear.
* **Dequeue:** Remove an element from the front.
* **Peek/Front:** View the front element without removing it.
* **isEmpty:** Check whether the queue has no elements.
* **isFull:** Check whether the queue has reached its maximum capacity, applicable for array implementations.

All of these operations can be performed in **O(1)** time when implemented using an array with front and rear pointers (often as a circular queue to reuse freed space), or using a linked list.

* **Time Complexity:** Enqueue, Dequeue, Peek, and isEmpty each run in **O(1)** constant time with the array-based implementation used here.
* **Space Complexity:** **O(n)** to store `n` elements in the queue array; **O(1)** extra auxiliary space beyond the array itself.

## 3. Algorithm

* **Step 1:** Start.
* **Step 2:** Initialize an empty queue `Q`.
* **Step 3:** Display the Queue Menu containing **Enqueue, Dequeue, Peek, Display, Check Empty,** and **Exit**.
* **Step 4:** Read the user's choice.
* **Step 5:** If the choice is **Enqueue**, read the number of elements and insert each element at the rear of the queue using `push_back()`.
* **Step 6:** If the choice is **Dequeue**, check whether the queue is empty. If empty, display **"Queue is empty."** Otherwise, remove the front element using `erase()` and display the updated queue.
* **Step 7:** If the choice is **Peek**, check whether the queue is empty. If not empty, display the front element.
* **Step 8:** If the choice is **Display**, check whether the queue is empty. If empty, display **"Queue is empty."** Otherwise, display all elements of the queue.
* **Step 9:** If the choice is **Check Empty**, check whether the queue is empty and display the appropriate message.
* **Step 10:** If the choice is **Exit**, terminate the program.
* **Step 11:** If an invalid choice is entered, display **"Invalid choice!"**
* **Step 12:** Repeat Steps 3–11 until the user selects **Exit**.
* **Step 13:** Stop.


*/