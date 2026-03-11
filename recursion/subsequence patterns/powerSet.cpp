/* Power Set: Print all the possible subsequences of the String
Problem Description: Given a string, find all the possible subsequences of the string.

eg:
Input: str = "abc"
Output: [a, ab, abc, ac, b, bc, c]
Explanation: Given string has 7 subsequences.

eg:
Input: str = "aa"
Output: [a, a, aa] 
Explanation: Given string has 3 subsequences.

total subset formula = 2^n where n = length of string
eg: string str = "abc" subsets =["", "a", "b", "c", "ab", "ac", "bc", "abc"] (2^3 = 8)
*/



/*optimal 1: using bit manipulation

    vector<string> getSubsequences(string s) {

        int n = s.size();
        int total = 1 << n;    //(2^n)

        vector<string> subsequences;

        for (int mask = 0; mask < total; mask++) {  //iterating from 0 to (2^n)-1
            
            string subseq = "";   // current subsequence string

            for (int i = 0; i < n; i++) {  
                
                if (mask & (1 << i)) {   //if i-th bit is set then include s[i]   (maskNum & 2^i)
                    subseq += s[i];
                }
            }

            subsequences.push_back(subseq);
        }
        return subsequences;
    }

tc: O(n*(2^n))
sc: O(n*(2^n))

approach:
1.bit indexing starts from 0 from RIGHT to LEFT
2.mask numbers = 0 to (2^n)-1 eg. n=3 then mask nums = 0,1,2,3,4,5,6,7
3.everytime we get 1 as a result of (maskNum & 2^i), i add that index of string to the current subsequence string

*/



//string example
/* optimal 2: using recursion -> check printAllSubsequences for array

    void helper(string &s, int index, string current, vector<string> &result) {
        
        if (index == s.size()) {        //Base case: If index reaches string length, add current subsequence to result
            result.push_back(current);
            return;
        }

        helper(s, index + 1, current, result);  //not take  (call)

        current.push_back(s[index]);   //take   (add)
        helper(s, index + 1, current, result); (call)

        current.pop_back();   //Backtrack: remove last character before returning to previous call (remove)
    }

    vector<string> getSubsequences(string s) {
        vector<string> result;  
        string current = "";    
        helper(s, 0, current, result);
        return result;
    }

    
tc: O(n*(2^n))
sc: O(n*(2^n))

*/