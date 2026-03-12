/*
Combination Sum - 1

Problem Statement: 

Given an array of distinct integers and a target, 
you have to return the list of all unique combinations where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from the given array an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 Example 1:
Input: array = [2,3,6,7], target = 7
Output: [[2,2,3],[7]] */


/*

 void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
       
        if (ind == arr.size()) {
            
            if (target == 0) {        // If the target is zero, we have found a valid combination
                ans.push_back(ds);  // Add the current combination to the result
            }
            return;
        }

        //pick the same index if target >= current index value (dont pick same index if target < current index val)
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);  
            findCombination(ind, target - arr[ind], arr, ans, ds);  
            ds.pop_back();  // Backtrack
        }

        // Skip the current element and move to the next index
        findCombination(ind + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds);  
        return ans; 
    }

    tc: O(2^t * k) t=target, k=avg length of data structure 
    sc: O(k * x) (x=number of combinations) (see lecture)

    approach: reducing the target val
    we are allowed to take the same el(index) as many times,
    pick the same index only if target >= current index value and keep reducing the target by picked ind
    if target becomes < cuurent index val we take next index 

*/