/* Implement Queue using Stack

Problem Statement: Implement a First-In-First-Out (FIFO) queue using two stacks. 
The implemented queue should support the following operations: push, pop, peek, and isEmpty.

Implement the StackQueue class:

void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise. */


/* brute: using 2 stack - push : O(2n)


class StackQueue {
private:
    stack <int> st1, st2;

public: 
    StackQueue () { }
    
    void push(int x) {
                                   
        while (!st1.empty()) {      //s1->s2
            st2.push(st1.top());
            st1.pop();
        }
        
        st1.push(x);               //x->s1
        
        while (!st2.empty()) {     //s2->s1
            st1.push(st2.top());
            st2.pop();
        }

    }
    
    int pop() {
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; 
        }
        int topElement = st1.top();
        st1.pop(); 
        
        return topElement; 
    }
    
    int peek() {

        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        return st1.top();
    }
    
    bool isEmpty() {
        return st1.empty();
    }
};

Time Complexity: O(n) for push operation, O(1) for pop and peek operations.
Space Complexity: O(n) for storing elements in the stacks.

*/




/* optimal : using 2 stack

class StackQueue {
  public:
    stack<int> input, output;

    StackQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (output.empty()) {                        // Shift input to output if output is empty
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();
    }

    bool isEmpty() {
        return input.empty() && output.empty(); //check for both
    }

};  

Time Complexity: O(1) for push operation, O(n) for pop and peek operations in the worst case when elements need to be shifted.
Space Complexity: O(n) for storing elements in the two stacks.

*/ 