/*
Reverse a stack using recursion:

Problem Statement: You are given a stack of integers. 
Your task is to reverse the stack using recursion. 
You may only use standard stack operations (push, pop, top/peek, isEmpty). 
You are not allowed to use any loop constructs or additional data structures like arrays or queues.

Your solution must modify the input stack in-place to reverse the order of its elements.
*/



/* brute:

void insertAtBottom(stack<int> &st, int val) {
    
    if (st.empty()) {          
        st.push(val);
        return;
    }
    int topVal = st.top();       
    st.pop();
    insertAtBottom(st, val);      
    st.push(topVal);               // Push the popped element back
}

void reverseStack(stack<int> &st) {
    
    if (st.empty()) {return;}     // Base case: If stack is empty, return
    int topVal = st.top();       
    st.pop();
    reverseStack(st);       
    insertAtBottom(st, topVal);       // Insert the popped element at the bottom
}

tc: O(n^2)
sc: O(n)


approach:
1. if->
x=s.top();
s.pop();
is happening, it means stack is being emptied and x would always store the 0th (bottomMost) element  

The idea is to recursively pop elements until the stack becomes empty, 
then while recursion unwinds 
I insert each element at the bottom. 
This reverses the order of elements.  */




/* optimal:

void reverseStack(stack<int>& st) {
    stack<int> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    st = temp;
}

tc: O(n)
sc: O(n)  


I use an auxiliary stack. 
I pop each element from the original stack and push it into a temporary stack. 
Since stack is LIFO, this automatically reverses the order of elements  
(Auxiliary space → extra memory used by an algorithm)*/