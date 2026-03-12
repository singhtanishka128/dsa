/* Combination Sum 2 - Find all unique combinations 

Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target. 

difference btw CS1 and CS2:
Each number in candidates may only be used once in the combination. 

all combinations should be in sorted mannr

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]]
 
Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: [[1,2,2],[5]]*/


/* brute: combination sum 1 only with each element picked only once


 void findCombination(int ind, int target, vector<int>& arr, set<vector<int>>& ans, vector<int>& ds) {
       
        if (ind == arr.size()) {
            
            if (target == 0) {        
                ans.insert(ds);  //modified
            }
            return;
        }

        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);  
            findCombination(ind+1, target - arr[ind], arr, ans, ds);    //modification : after picking we move to the next index
            ds.pop_back();  
        }

        findCombination(ind + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;   //modified : storing all combs in set to store only unique combinations
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds);  
        return ans; 
    }

tc: O(2^t * k * log(set size))
sc: chatgpt

storing all valid combinations in set,
picking each inddex only once

*/


/* optimal:

void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (target == 0) {
        ans.push_back(ds);  
        return;
    }

    for (int i = ind; i < arr.size(); i++) {
        if (i > ind && arr[i] == arr[i - 1]) continue;
        if (arr[i] > target) break;                 // If the current element is greater than the remaining target, break the loop

        ds.push_back(arr[i]);   //pick
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();   //backtrack
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());  
    vector<vector<int>> ans; 
    vector<int> ds;  
    findCombination(0, target, candidates, ans, ds);  
    return ans;
}

tc: O(2^n * k) (n=number of unique elements) (k=avg length of every combination)
sc: O(k * x) (x=number of combinations)

approach:
sort the array
we keep looping from current index to n-1
if arr[ind] > target we break cause in the right there will be even greater elements since the array is sorted
if current index val == next index value we skip the iteration (arr[ind]==arr[ind-1])
i>ind check because we always want to take th element which is appearing for the first and and we wont want it the second time
It skips duplicate numbers at the same recursion level.
Two conditions must be true:
i > ind → we are not at the first element of this recursion level
arr[i] == arr[i-1] → current number is same as previous number
If both happen → skip it.

*/