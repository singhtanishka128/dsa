/* Binary subarray with sum

Problem Statement: You are given a binary array nums (containing only 0s and 1s) and an integer goal. Return the number of non-empty subarrays of nums that sum to goal. A subarray is a contiguous part of the array.

Examples
Input: nums = [1, 0, 0, 1, 1, 0], goal = 2  
Output: 6
Explanation: There are 6 subarrays with sum exactly equal to 2:
[1, 0, 0, 1], [0, 0, 1, 1], [0, 1, 1], [1, 1], [1, 1, 0], [0,0,1,1,0] */


/* brute:

 int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == goal){ count++;}
            }
        }

        return count;
    }

tc: O(n^2)
sc: O(1)  

count number of subarrays reference */



/* better : count number of subarrays using hashmap

int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;
        int count = 0, sum = 0;
        prefixSumCount[0] = 1;

        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];

            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[sum - goal];
            }

            prefixSumCount[sum]++;
        }

        return count;
    }

tc: O(N)
sc: O(N)  */




/* optimal : sliding window : count the number of subarrays whose sum is at most goal, 
and subtract from it the number of subarrays whose sum is at most goal- 1. 

int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > k) {
                sum -= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

tc: O(n)
sc: O(1)    
*/