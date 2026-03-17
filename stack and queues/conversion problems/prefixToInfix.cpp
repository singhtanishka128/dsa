/* prefix to infix

string prefixToInfix(string prefix) {
    stack<string> s;
    int n = prefix.size();

    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            string top1 = s.top(); s.pop();
            string top2 = s.top(); s.pop();
            s.push( "(" + top1 + c + top2 + ")" );
        }
    }

    return s.top();
}


(top1 = element popped first, top2 = el popped second)
iterate from right to left (back to front)
if operand, push into stack,
if operator, pop last 2 els
infix is made by top1 + operator + top2

*/