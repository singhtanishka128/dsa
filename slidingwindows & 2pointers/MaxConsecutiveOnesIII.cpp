/*  Maximum consecutive Ones III:

Problem Statement: Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's. 
Input : nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0] , k = 3
Output : 10  */

/* brute:

 int longestOnes(vector<int>& nums, int k) {

        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {

            int zeros = 0;

            for (int j = i; j < nums.size(); j++) {

                if (nums[j] == 0) {
                    zeros++;
                }

                if (zeros > k) {
                    break;
                }

                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }

    tc: O(n^2)
    sc: O(1)
    
    treating the question like longest subarray with atmost k zeros
    generating all the subarrays, once the k counting of 0 gets over, stop measuring the length */


/* better : using sliding windows

    
int longestOnes(vector<int>& nums, int k) {

    int left = 0;
    int right = 0;
    int zeros = 0;
    int maxLen = 0;

    while (right < nums.size()) {

        if (nums[right] == 0) {
            zeros++;
        }

        while (zeros > k) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);

        right++; 
    }

    return maxLen;
}

    tc: (2n)
    sc: O(1)

If number of zeros exceeds k, shrink the window from left
(shrinking? keep on mving left forward until it passes the first 0, once this happens, while loop condition doesnt satisfy) */



/* optimal : using sliding window

int longestOnes(vector<int>& nums, int k) {

    int left = 0;
    int right = 0;
    int zeros = 0;
    int maxLen = 0;

    while (right < nums.size()) {

        if (nums[right] == 0) {
            zeros++;
        }

        if (zeros > k) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);

        right++; 
    }

    return maxLen;
}

tc: O(n)
sc: O(1)

We shrink only one step at a time
But since right moves forward every iteration, the window eventually becomes valid anyway

*/