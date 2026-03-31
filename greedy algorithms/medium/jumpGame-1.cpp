/* Jump Game - I
statement: Given an array where each element represents the maximum number of steps you can jump forward from that element, return true if we can reach the last index starting from the first index. Otherwise, return false.

Examples
Example 1:
Input:nums = [2, 3, 1, 0, 4]
Output: True         

greedy soln: 

    bool canJump(vector<int>& nums) {
        int maxIndex = 0; // The farthest index we can currently reach

        for (int i = 0; i < nums.size(); i++) {

            // If current index is beyond the farthest reachable point
            if (i > maxIndex) {
                return false; // We cannot move further
            }

            maxIndex = max(maxIndex, i + nums[i]);
        }

        return true;
    }

tc: O(n)
sc: O(1)

*/