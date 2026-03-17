/* Valid Parenthesis:

Problem Statement: Check Balanced Parentheses. Given string str containing just the characters '(', ')', '{', '}', '[' and ']', 
check if the input string is valid and return true if the string is balanced otherwise return false. .
Note:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Example 1:
Input: str = “( )[ { } ( ) ]”
Output: True */



/* 
    bool isValid(string s) {
        stack<int> st;
        for(auto it : s){
            if(it=='('||it=='{'||it=='['){
                st.push(it);
            }else{
                if(st.empty())return false;  //if any )}] appears first, invalid
                char c = st.top();
                st.pop();
                if((it==')' && c=='(')||
                (it=='}' && c=='{')||
                (it==']' && c=='[')){continue;}else{return false;}
            }
        }
        return st.empty();
    }

Time Complexity: O(n)
Space Complexity: O(n)
*/