/* Jump Game 2

Problem Statement: You are given a 0-indexed array nums of length n representing your maximum jump capability from each index.

You start at index 0. Each element nums[i] represents the maximum number of steps you can jump forward from index i.
Your goal is to reach the last index of the array (nums[n - 1]) using the minimum number of jumps
Return the minimum number of jumps required to reach the last index.
You can assume that it is always possible to reach the last index. 

Input: nums = [2, 3, 1, 1, 4]
Output: 2 */



/* brute: rescursive


    int minJumps(vector<int>& nums, int position) {
        if (position >= nums.size() - 1) return 0;
        if (nums[position] == 0) return INT_MAX;

        int minStep = INT_MAX;

        for (int jump = 1; jump <= nums[position]; jump++) {
            int subResult = minJumps(nums, position + jump);

            if (subResult != INT_MAX)
                minStep = min(minStep, 1 + subResult);
        }

        return minStep;
    }

//main
    int jump(vector<int>& nums) {
        return minJumps(nums, 0);
    }

tc: O(2^n)
sc: O(n) */

/* better : dp */



/* optimal: greedy

 int jump(vector<int>& nums) {
        // Initialize variables to keep track of range and jumps
        int jumps = 0, currentEnd = 0, farthest = 0;

        // Traverse through the array (excluding the last element)
        for (int i = 0; i < nums.size() - 1; i++) {
            // Update the farthest index that can be reached so far
            farthest = max(farthest, i + nums[i]);

            // When we reach the end of the current jump range
            if (i == currentEnd) {
                // We need to make a jump
                jumps++;

                // Move the current end to the farthest index we can reach
                currentEnd = farthest;
            }
        }

        // Return the total jumps needed
        return jumps;
    }

*/





