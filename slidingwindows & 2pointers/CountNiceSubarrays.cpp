/* Count number of nice subarrays:
Problem Statement: Given an array nums and an integer k. An array is called nice if and only if it contains k odd numbers. Find the number of nice subarrays in the given array nums. A subarray is continuous part of the array. */


//treating all odds as 1s, all evens as 0s, on summing up if i get an odd value, subarray is nice

/* brute:

 int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;

        for (int start = 0; start < nums.size(); start++) {
            int oddCount = 0;

            for (int end = start; end < nums.size(); end++) {
                if (nums[end] % 2 != 0) oddCount++;
                if (oddCount > k) break;

                if (oddCount == k) count++;
            }
        }

        return count;
    }

tc: O(n^2)
sc: O(1)  */




/* optimal: 


int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += (nums[right] % 2);  //gives 0 if even, 1 if odd

            while (sum > k) {
                sum -= (nums[left] % 2);
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

tc: O(n)
sc: O(1)   */
