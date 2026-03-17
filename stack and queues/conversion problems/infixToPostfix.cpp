/* Infix to Postfix: 
Problem Statement: Given an infix expression, Your task is to convert the given infix expression to a postfix expression.

Example 1:
Input:
 a + b * (c^d - e) ^ (f + g * h) - i  
Output:
 abcd^e-fgh*+^*+i-

Example 2:
Input:
 (p + q) * (m - n)  
Output:
 pq+mn-*       */


/* 

int prec(char c) {
    if (c == '^')  
        return 3;
    else if (c == '/' || c == '*')  
        return 2;
    else if (c == '+' || c == '-')  
        return 1;
    else
        return -1;
}

void infixToPostfix(string s) {
    stack<char> st; 
    string result; 

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();  // Pop the ‘(‘ from the stack
        }

        //c is an operator
        else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);  
        }
    }

    
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << result << endl;  // Output the result
}

tc  O(n)
sc  O(n)

// If operand, add it to the result string
// If ‘(‘, push it to the stack
// If ‘)’, pop from stack until an ‘(‘ is encountered, then pop '(' as well
//if c = operator whose precedence value <= precedence value of operator at top, pop the top, add into result, push the lower prec into stack
//at last pop all the remaining elements from the stack


*/