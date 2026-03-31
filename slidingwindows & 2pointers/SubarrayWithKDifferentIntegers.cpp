/* Number of Subarrays With K Different Integers
Problem Statement: You are given an integer array nums and an integer k. Return the number of good subarrays of nums.
A good subarray is defined as a contiguous subarray of nums that contains exactly k distinct integers. A subarray is a contiguous part of the array.

Input: nums = [1, 2, 1, 3, 4], k = 3  
Output: 3
Explanation: The 3 subarrays with exactly 3 different integers are:  
[1,2,1,3], [2,1,3], [1,3,4]   */


/* brute: generating all subarrays

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[nums[j]]++;
                if (mpp.size() == k) count++;
                if (mpp.size() > k)break;
            }
        }

        return count;
    }

    tc: O(n^2 * k)
    sc: O(k)
*/


/* better: 

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int> &nums, int k){
        int l=0, r=0, cnt=0;
        unordered_map<int,int> mpp;
        while(r < nums.size() ){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){ mpp.erase(nums[l]); }
                l++;
            }
          cnt = cnt + (r-l+1);
          r++;       
        }

        return cnt;
    }
 

*/