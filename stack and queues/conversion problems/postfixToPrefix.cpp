/*  postfix to prefix

string postfixToPrefix(string postfix) {
    stack<string> s;
    int n = postfix.size();

    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            string top1 = s.top(); s.pop();
            string top2 = s.top(); s.pop();
            s.push(c + top2 + top1);
        }
    }

    // The final element in the stack is the result
    return s.top();
}

iterate from left to right 
if operand, push into stack
if operator, make prefix formula = operator + top2 + top1


*/