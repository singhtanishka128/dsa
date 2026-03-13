/* Subset2 | Print all the Unique Subsets 
Problem Statement: Given an integer array nums, which can have duplicate entries, provide the power set. 
Duplicate subsets cannot exist in the solution set. Return the answer in any sequence. 

Input: array[] = [1,2,2]
Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]
Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

Input: array[] = [1]
Output: [ [ ], [1] ]
Explanation: Only two unique subsets are available.


*/


/* brute: 

    void findSubsets(int ind, vector<int>& nums, vector<int>& ds, set<vector<int>>& result) {
        if (ind == nums.size()) {
            result.insert(ds);
            return;
        }

        ds.push_back(nums[ind]);
        findSubsets(ind + 1, nums, ds, result);
        ds.pop_back();

        findSubsets(ind + 1, nums, ds, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        
        findSubsets(0, nums, ds, result);

        // Convert the set of unique subsets to a vector for the final answer
        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }

Time Complexity: O(N² * 2^N). We generate all 2^N possible subsets, and copying each subset into temporary storage costs up to O(N). Additionally, inserting each subset into a balanced BST-based set costs O(log(2^N)) = O(N), resulting in an extra O(N) factor. Combining these gives O(N * 2^N + N² * 2^N) ≈ O(N² * 2^N).
Space Complexity: O(N * 2^N). We store up to 2^N subsets in the set, each subset storing up to N elements in the worst case. Additionally, O(N) space is used for the recursion stack during subset generation.
(chatgpt)

printing all subsets/subsequences but uniquely so using a set to store all subsets to avoid duplicacy */


/* optimal: 

    void backtrack(int ind, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = ind; i < nums.size(); i++) {
            
            if (i > ind && nums[i] == nums[i - 1]) continue;   // Skip duplicates
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, nums, current, result);

        return result;
    }

Time Complexity: O(2^N),In the worst case (all unique elements), we generate all possible subsets, which is 2^N. Sorting takes O(N log N), so total complexity is O(2^N + N log N) ≈ O(2^N).
Space Complexity: O(N) ,Due to recursion depth and storage of the current subset in the call stack. The output storage is O(2^N) for all subsets.


just like combination sum2, 
if there are duplicates, only pick up first time the number is occurring when talking about starting the sequence
*/