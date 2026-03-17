/* MinStack problem:
Problem Statement: Design a stack that supports the following operations in constant time: push, pop, top, and retrieving the minimum element.

Implement the MinStack class:

MinStack(): Initializes the stack object.
void push(int val): Pushes the element val onto the stack.
void pop(): removes the element on the top of the stack.
int top(): gets the top element of the stack.
int getMin(): retrieves the minimum element in the stack. */

/* brute: runtime error in lc

class MinStack {

    stack <pair<int,int>> st; //classmember
    MinStack() { }
    
    void push(int value) {
        if(st.empty()) {
            st.push( {value, value} );
            return;
        }
        
        int mini = min(getMin(), value);
        st.push({value, mini});
    }
    
    void pop() {
        st.pop(); 
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }

};

instead of storing single elements we store pairs where
pair.first = val, pair.second = min val of stack
if stack is empty, we insert the val and min = val
else we get the min element between current val and last min

min will always be stored in second pair value */


/* optimal:

class MinStack {
private:

    stack <int> st;
    int mini;
    
public:

    MinStack() { }
    
    void push(int value) {
        
        if(st.empty()) {
            mini = value;
            st.push( value );
            return;
        }
        
        if(value > mini) {
            st.push(value);
        }
        else {

            // Add the modified value to stack
            st.push(2 * value - mini);

            // Update the minimum
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        
        // Get the top
        int x = st.top();
        st.pop(); // Pop operation
        
        // If the modified value was added to stack
        if(x < mini) {
            // Update the minimum
            mini = 2 * mini - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
        int x = st.top();
        
        if(mini < x) return x;
        return mini;
    }
    
    int getMin() {
        return mini;
    }

};

anytime i get a value (<min) which is going to replace my minimum, i'll instead insert
2*value - prevMini = modified value, and replace the prev min with value

whenever someone asks pop when topVal < mini
top value would be mini
we replace the mini with prev mini 
prevMini = 2*currentMini - new modifiedMini

after i modify, my min is the top value
*/


/*

leetcode soln: //make sure all varibles are storeed in long long even in stack 

class MinStack {

stack<long long>st;
long long mini;

public:
    MinStack() { }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
            return;
        }
        if(val>mini){
            st.push(val);
            return;
        }
        else{
            st.push(2LL*val - mini);
            mini=val;
            return;
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long x=st.top();
        st.pop();
        if(x>mini){
            return;
        }else{
            mini = 2LL*mini - x;
        }
    }
    
    int top() {
        if(st.empty())return -1;
        long long x=st.top();
        if(x>mini){
            return x;
        }else{
            return mini;
        }

    }
    
    int getMin() {
        if(st.empty())return -1;
        return mini;
    }
};


 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 

*/