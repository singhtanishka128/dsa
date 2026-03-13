/* Combination Sum 3

Problem Statement: Determine all possible set of k numbers that can be added together to equal n while meeting the following requirements:
1. There is only use of numerals 1 through 9.
2. A single use is made of each number.
Return list of every feasible combination that is allowed. The combinations can be returned in any order, but the list cannot have the same combination twice.

Example 1:
Input:
 k = 3, n = 7
Output:
 [[1, 2, 4]]
Explanation:

1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:
Input:
 k = 3, n = 9
Output:
 [[1, 2, 6],[1, 3, 5],[2, 3, 4]]
Explanation:

1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations. */


/* optimal:

    void func(int target, int ind, vector<int> &nums, int k, vector<vector<int>> &ans) {

        if(target == 0 && nums.size() == k) {
            ans.push_back(nums);
            return; 
        }
        if(target <= 0 || nums.size() > k) return; 

        for(int i = ind; i <= 9; i++) {

            if(i <= target) {
                nums.push_back(i); 
                func(target - i, i + 1, nums, k, ans); 
                nums.pop_back(); 
            } 
            else {
                break;   // If target < i , break the loop
            }
        }
    } 

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; 
        vector<int> nums; 
        func(n, 1, nums, k, ans);
        return ans; 
    }

Time Complexity: O(2^9 * k), due to the exploration of all subsets of the set {1, 2, ..., 9}..
Space Complexity: O(k), where k is the number of elements in the combination. This is due to the space used by the recursive call stack and the storage of valid combinations.

*/