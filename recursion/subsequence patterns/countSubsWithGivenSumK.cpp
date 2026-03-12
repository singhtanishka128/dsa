/* count all the subsequences with given sum k */


/* 
    int solve(int ind, int sum, int k, vector<int>& nums) {

        if(sum > k) return 0; //only if array contains positives

        if(ind == nums.size()) {
            if(sum == k) return 1;
            else return 0;
        }

        // pick
        sum += nums[ind];
        int l = solve(ind + 1, sum, k, nums);

        sum -= nums[ind];

        // not pick
        int r = solve(ind + 1, sum, k, nums);

        return l + r;
    }

    int countSubsequences(vector<int>& nums, int k) {
        return solve(0, 0, k, nums);
    }

Time Complexity: O(2^n)
Space Complexity: O(n)


approach: using 1 and 0
if base case satisfies return 1 else 0
counting the total number of 1s we get by storing the returned val (0 or 1) in integers

*/