/* postfix to infix

string postfixToInfix(string postfix) {
    stack<string> st;
    int n = postfix.size();

    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            st.push(string(1, c)); //save 1 copy of c in stack
        } else {
            string top1 = st.top(); st.pop();   //el1 -> top1
            string top2 = st.top(); st.pop(); //el2 -> top2
            st.push( "(" + top2 + c + top1 + ")" ); //making infix     
        }
    }

    return st.top();
}

tc: O(n) + O(n)
sc: O(n)

//left to right
if operand then store in stack 
else take & pop last 2 elements and form an infix 
at last the single top element left is the ans(postfix)
=>top2 + operator + top1

*/