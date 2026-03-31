/* 
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true  */


/* brute : recursion

 bool isValid(string& s, int i, int open) {
        if (open < 0) return false;

        if (i == s.length()) return open == 0;

        if (s[i] == '(') {
            return isValid(s, i + 1, open + 1);
        } 
        else if (s[i] == ')') {
            return isValid(s, i + 1, open - 1);
        } 
        else {
            return isValid(s, i + 1, open) ||       
                   isValid(s, i + 1, open + 1) ||    
                   isValid(s, i + 1, open - 1);      
        }
    }

     bool checkValidString(string s) {
        return isValid(s, 0, 0); 
    }

    tc: O(3^n)
    sc: O(n)




better : apply dp 
optimal: greedy (rewatch)

*/