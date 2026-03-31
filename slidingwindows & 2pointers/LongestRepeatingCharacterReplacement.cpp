/* longest repeating character replacement:
Problem Statement: Given an integer k and a string s, any character in the string can be selected and changed to any other uppercase English character. This operation can be performed up to k times. After completing these steps, return the length of the longest substring that contains the same letter.

Input: s = "BAABAABBBAAA", k = 2  
Output: 6  


Input: s = "AABABBA", k = 1  
Output: 4   */


/* brute : 

int characterReplacement(string s, int k) {
        
        int maxLength = 0;        
        for (int i = 0; i < s.length(); i++) {
            
            vector<int> freq(26, 0);
            int maxFreq = 0;
            
            for (int j = i; j < s.length(); j++) {
                
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);                
                int windowLength = j - i + 1;                
                int replace = windowLength - maxFreq;   //how many characters we need to replace
                
                // If number of replacements is within allowed k, update answer
                if (replace <= k) {
                    maxLength = max(maxLength, windowLength);
                }
            }
        }
        
        return maxLength;
    }

tc: O(n^2)
sc: O(1)   */


/* optimal : sliding window

int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);        
        int left = 0, right = 0;
        int maxCount = 0;
        int maxLength = 0;

        while (right < s.size()) {

            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);

            // If the current window needs more than k replacements, move left
            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);            
            right++;
        }

        return maxLength;
    }

tc: O(n)
sc: O(1)

Instead of checking all substrings, we use a sliding window technique. In a valid window, the number of characters we need to change is window length - count of most frequent character. If this number exceeds k, the window is invalid, and we shrink it from the left. This helps us maintain a valid window of maximum size. */



