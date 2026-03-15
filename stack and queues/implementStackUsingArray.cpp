/* implement stack using array
size of array should always be known */

/*
class Stack {    //these should be class members
    int top;
    int capacity; 
    int arr[100];

public:

    Stack(int s) {   //constructor
        capacity = s;
        top = -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if(isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top = top + 1;
        arr[top] = x;
    }

    void pop() {
        if(isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if(isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {   // TC: O(n), SC: O(1)
        for(int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int size(){
        return top + 1;
    }
};

push  → TC: O(1), SC: O(1)
pop   → TC: O(1), SC: O(1)
peek  → TC: O(1), SC: O(1)
size  → TC: O(1), SC: O(1)

overall stack space → O(n)
*/


/*
Implement Stack using Array

Problem Statement: Implement a Last-In-First-Out (LIFO) stack using an array. 
The implemented stack should support the following operations: 
push, pop, peek, and isEmpty.

Implement the ArrayStack class:

void push(int x): Pushes element x onto the stack. 
int pop(): Removes and returns the top element of the stack. 
int top(): Returns the top element of the stack without removing it. 
boolean isEmpty(): Returns true if the stack is empty, false otherwise.



class ArrayStack {
private:

    // Array to hold elements
    int* stackArray;

    // Maximum capacity
    int capacity; 

    // Index of top element  
    int topIndex;   

public:

    // Constructor
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];

        // Initialize stack as empty
        topIndex = -1; 
    }

    // Destructor
    ~ArrayStack() {
        delete[] stackArray;
    }

    // Pushes element x 
    void push(int x) {
        if (topIndex >= capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }

    // Removes and returns top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            // Return invalid value
            return -1; 
        }
        topIndex--;
        return stackArray[topIndex];
    }

    // Returns top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[topIndex];
    }

Returns true if the 
stack is empty, false otherwise

    bool isEmpty() {
        return topIndex == -1;
    }
        
};

*/
