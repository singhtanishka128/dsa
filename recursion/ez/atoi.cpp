/* description:

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. 
If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], 
then round the integer to remain in the range. Specifically, integers less than -2^31 should be rounded to -2^31, 
and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
Return the integer as the final result.

Example 1:
Input: s = "42"
Output: 42

Example 2:
Input: s = "1337c0d3"
Output: 1337

Example 3:
Input: s = "0-1"
Output: 0

Example 4:
Input: s = "words and 987"
Output: 0  */



/* Brute force: Recursive Atoi

const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647;

int helper(const string &s, int i, long long res, int sign) {

    // If out of bounds or at a non-digit, return
    if (i >= n || !isdigit(s[i]))
        return (int)(sign * res);

    // Update res with current digit
    res = res * 10 + (s[i] - '0');

    // Clamp if overflow
    if (sign * res <= INT_MIN_VAL) return INT_MIN_VAL;
    if (sign * res >= INT_MAX_VAL) return INT_MAX_VAL;

    // Recurse for next character
    return helper(s, i + 1, res, sign);
}

int myAtoi(string s, int i = 0) {

    int n = s.size();
    while (i < n && s[i] == ' ') i++;

    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    //recursion
    return helper(s, i, 0, sign);
}


tc: O(n)
sc: O(n)  


approach:
1.skip whitwspace
2.handle sign
3. recursive helper fn ->
   a)check if out of bound or non digit character
   b)convert string to integer
   c)check overflow case
   d)next iteration

*/





/* Optimal: String Atoi

int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        long res = 0; 
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');      //converting string number into integer number
            
            if (sign == 1 && res > INT_MAX) return INT_MAX;
            if (sign == -1 && -res < INT_MIN) return INT_MIN;
            
            i++;
        }
        
    return (int)(res * sign);
}


tc: O(n)
sc: O(1)  


approach:
1.skip leading whitespace
2.handle sign
3.converting string to integer

*/



