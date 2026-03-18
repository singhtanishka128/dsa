/* remove k digits : given a string num and k, remove k digits such that the remaining string is the smallest one 
Problem Statement: Given a string nums representing a non-negative integer, and an integer k, find the smallest possible integer after removing k digits from num.

Input:
 nums = "541892", k = 2
Output:
 "1892"  */


/* optimal: 

 
    string removeKdigits(string nums, int k) {
        
        stack <char> st;         
        for(int i=0; i < nums.size(); i++) {
            
            char digit = nums[i];
            
            while(!st.empty() && k > 0
            && st.top() > digit) {

                st.pop(); 
                k--; 
            }
            
            st.push(digit);
        }
        
        // If more digits can be removed
        while(!st.empty() && k > 0) {
            
            st.pop(); 
            k--; 
        }
        
        // Handling edge case
        if(st.empty()) return "0";


        // Adding digits in stack to result
        string res = "";
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        // Trimming the trailing zeroes
        while(res.size() > 0 && 
        res.back() == '0') {

            res.pop_back();
        }
        
        reverse(res.begin(), res.end());
        
        if(res.empty()) return "0";
        
        return res;
    }

tc, sc : watch lecture

keep smaller digits at the start,
get rid of k larger digits

edge cases: 
1. if k==n -> remove all digits and return "0" string
2. if after removing we get smthing like "00100" we'll trim initial 0s to  make it valid "100"
3. if the digits in string are in increasing order or when none of digits getting cancelled, we'll delete last k larger digits

if stacks top > current el, pop top, k--, push el into stack
trim all the 0s at the back (because in actual these are at the front, leading 0s)
after trimming reverse res (since stack stores el in reverse order)
if after trimming result is empty, return "0"

*/