/* Generate Paranthesis:

Problem Statement: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input:
 n = 3
Output:
 ["((()))", "(()())", "(())()", "()(())", "()()()"]

Example 2:
Input:
 n = 1
Output:
 ["()"]  

eg: )( is invalid. */



/* brute:

bool isValid(string s) {    // Check if a string has valid parentheses
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false; //checks if theres any ')' before '(', if yes then invalid
    }
    return balance == 0; (if string is valid, balance should be 0 at the end)
}

void generateAll(string curr, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        if (isValid(curr)) res.push_back(curr);
        return;
    }
    generateAll(curr + '(', n, res);
    generateAll(curr + ')', n, res);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateAll("", n, res);
    return res;
}

tc: O(2^(2n) * n) 
sc: O(n) 


approach:
Generate all sequences of length 2n.
For each sequence, use a validator to check conditions.
Ensure the count of ')' never exceeds '(' at any point.
At the end of the sequence, the count must be 0.
 */




/*optimal:

void backtrack(string curr, int open, int close, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        res.push_back(curr);
        return;
    }
    if (open < n) backtrack(curr + '(', open + 1, close, n, res);
    if (close < open) backtrack(curr + ')', open, close + 1, n, res);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack("", 0, 0, n, res);
    return res;
}

Time Complexity: O(2^n) (Catalan number): C(n) = (2n)! / (n!(n+1)!) is the number of valid sequences.
Each sequence takes O(n) to build.
So, total complexity: O(C(n) × n)

Space Complexity: O(n) recursion depth.
O(C(n) × n) to store results.
*/

