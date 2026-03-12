/* check if there exists a subsequence with sum K :

 bool func(int ind, int sum, vector<int>& nums) {
        if (ind == nums.size()) {
            return sum == 0;
        }

        // take
        if (func(ind + 1, sum - nums[ind], nums) == true)
            return true;

        // not take
        if (func(ind + 1, sum, nums) == true)
            return true;

        return false;
    }

    bool checkSubsequenceSum(vector<int>& nums, int target) {
        return func(0, target, nums);
    }

TC:
O(2^n)

SC:
O(n) (recursion stack)

approach: reducing the target val
reducing the target value by the picked el when pick method
not including any val  when non pick method
again returning true after each call if any of the recursive call returns true

*/