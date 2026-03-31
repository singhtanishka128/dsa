/* Longest Substring with At Most K Distinct Characters
Problem Statement: Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters 

Input :s = "aababbcaacc" , k = 2
Output :6
Explanation :The longest substring with at most two distinct characters is "aababb".
The length of the string 6  */


/* brute: using map ds

 int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLen = 0;
        unordered_map<char, int> mpp;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            mpp.clear();
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;

                if (mpp.size() <= k) {maxLen = max(maxLen, j-i+1);}
                else {break; }
            } 
        }

    return maxLength;
 }

 tc: O(n^2 * log(256))
 sc: O(256)  */


/* better: sliding window 

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int maxLen = 0, l = 0, r = 0;
    unordered_map<char, int> mpp;

    while (r < s.size()) {
        mpp[s[r]]++;

        while (mpp.size() > k) {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++; 
    }

    return maxLen;
}

tc: O(2n)
sc: O(k)  */



/* optimal: if asked to optimise more


int lengthOfLongestSubstringKDistinct(string s, int k) {
    int maxLen = 0, l = 0, r = 0;
    unordered_map<char, int> mpp;

    while (r < s.size()) {
        mpp[s[r]]++;

        if (mpp.size() > k) {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++; 
    }

    return maxLen;
}


*/