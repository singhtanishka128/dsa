/* Problem Statement: Given a string, S. Find the length of the longest substring without repeating characters.

Input:
 S = "abcddabac"  
Output:
 4  
Explanation:
 The longest substring with distinct characters is "abcd", which has a length of 4. */

/* brute: 

 int longestNonRepeatingSubstring(string &s) {
        
        int n = s.size();         
        int maxLen = 0;    
        
        for (int i = 0; i < n; i++) {
        vector<int> hash(256, 0);  
            
            for (int j = i; j < n; j++) {
                
                if (hash[s[j]] == 1) break;  
                hash[s[j]] = 1;
                
                int len = j - i + 1;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen; 
    }

tc: O(n^2)
sc: O(1)    

Hash to track characters in the current substring window 
If s[j] is already in the current substring window, break
Update the hash to mark s[j] as present in the current window
Calculate the length of the current substring
Update maxLen if the current substring length is greater
Return the maximum length */



/* optimal:

 int longestNonRepeatingSubstring(string& s) {
        int n = s.size();
        
        int HashLen = 256; 
        int hash[HashLen]; 
        
        for (int i = 0; i < HashLen; i++) {
            hash[i] = -1;
        }

        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
            
            if (hash[s[r]] != -1) {
                l = max(hash[s[r]] + 1, l);
            }
            
            int len = r - l + 1;            
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }       
        return maxLen;
    }

    tc: O(n)
    sc: O(1)

hash to maintain if character has appeared previously in the string
if appeared, move the left pointer 1 place ahead of wherever it appeared previously,
calc len, store max
store the current index of r in hash, r++


*/