/* Implement Queue Using Array

Problem Statement: Implement a First-In-First-Out (FIFO) queue using an array. 
The implemented queue should support the following operations: push, dequeue, pop, and isEmpty.

Implement the ArrayQueue class:

void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise.


class ArrayQueue {   //these should be class members

    int* arr;
    int start, end;
    int currSize, maxSize;

public:
    
    ArrayQueue() {              // Constructor
        arr = new int[10];
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = 10;
    }

    void push(int x) {

        if (currSize == maxSize) {
            cout << "Queue is full." << endl;
            exit(1);      // exit(1) terminates the entire program immediately.
        }
        
        if (end == -1) {
            start = 0;
            end = 0;
        } 
        else {

            // Circular increment of end
            end = (end + 1) % maxSize;
        }
            
        arr[end] = x;
        currSize++;
    }

    int pop() {

        if (start == -1) {
            cout << "Queue Empty." << endl;
            exit(1);
        }
        int popped = arr[start];
        
        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            // Circular increment of start
            start = (start + 1) % maxSize;
        }
        
        currSize--;
        return popped;
    }

    int peek() {

        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    bool isEmpty() {
        return (currSize == 0);
    }
};

push     → TC: O(1), SC: O(1)
pop      → TC: O(1), SC: O(1)
peek     → TC: O(1), SC: O(1)
isEmpty  → TC: O(1), SC: O(1)

Overall queue space → O(n)
*/