/* prefix to postfix


string prefixToPostfix(string prefix) {
    stack<string> s;
    int n = prefix.size();

    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            string top1 = s.top(); s.pop();
            string top2 = s.top(); s.pop();
            s.push(top1 + top2 + c);
        }
    }

    return s.top();
}

iterate right to left (back to front)
if operand, push into stack
if operator, pop last 2 tops
top1 + top2 + operator =postfix

*/