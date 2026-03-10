/*Sort a Stack:
Problem Statement: 
You are given a stack of integers. Your task is to sort the stack in descending order using recursion, 
such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods 
(e.g., quicksort, mergesort). 
You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).  */


/*brute force:

void insert(stack<int>& s, int temp) {
                                                   
    if (s.empty() || s.top() <= temp) {         // Base case: if the stack is empty or temp is larger than the top element
        s.push(temp);
        return;
    }
    int val = s.top();      // Otherwise, pop the top element and recursively insert
    s.pop();
    insert(s, temp);
    s.push(val);     // Push the popped element back
}
void sortStack(stack<int>& s) {

    if (s.empty()) return;
    int temp = s.top();
    s.pop();
    sortStack(s);
    insert(s, temp);
}

tc: O(n^2)
sc: O(n)

approach: 
1.empty the stack storing 0th element in temp
2.back-tracking - start inserting elements in backward fashion only if
   a)the stack is empty or temp is larger than top value if not then keep emptying the stack until 
     the stack is empty or temp is larger than top  
*/




/* optimal:

void sortStack(stack<int>& s) {
    vector<int> v;

    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }

    sort(v.begin(), v.end());

    for(int x : v)
        s.push(x);
}

tc: O(n log n)
sc: O(n)

*/