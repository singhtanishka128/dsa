/* Given an array -> PRINT ALL SUBSEQUENCES (can be contiguous/non-contiguous, must maintain order). 
*/

//logic: each digit has 2 possibilities of being taken & not taken, 
//for each digit we explore till the end of array undertaking both the possibilities


//optimal:
/* take and not take (pick and not pick)

 void helper(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Base case
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        //take
        current.push_back(nums[index]);   //add
        helper(nums, index + 1, current, result);  //call

        //not take
        current.pop_back();  //remove
        helper(nums, index + 1, current, result);  //call
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        helper(nums, 0, current, result);
        return result;
    }

(add,call,remove,call)

*/

// OR


/* not take and take (not pick and pick)

void helper(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        //not take
        helper(nums, index + 1, current, result);  //call

        //take
        current.push_back(nums[index]);              //add
        helper(nums, index + 1, current, result);    //call
        current.pop_back(); // backtrack            //remove
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        helper(nums, 0, current, result);
        return result;
    }

(call,add,call,remove)

*/


/*
tc: O(2^n * n)
sc: O(n)  //auxilliary stack space
*/

//see recursion tree in copy

