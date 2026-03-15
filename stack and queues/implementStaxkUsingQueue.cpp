/* implement push pop top of stack properties using queue

class MyStack {
    queue<int>q;  //this should be a class member
public:
    MyStack() {}  //empty constructor
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
        return;
    }
    
    int pop() {
        int popped=q.front();
        q.pop();
        return popped;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};


 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

