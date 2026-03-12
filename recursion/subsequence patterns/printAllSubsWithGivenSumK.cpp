/* Print all subsequences with given sum 'k'

void printSub(int index, vector<int> &ds, int s, int sum, vector<int> &arr, int n) {

    if(index == n){
        if(s == sum){
            for(auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }

    // take
    ds.push_back(arr[index]);
    s += arr[index];

    printSub(index+1, ds, s, sum, arr, n);

    s -= arr[index];
    ds.pop_back();

    // not take
    printSub(index+1, ds, s, sum, arr, n);
}

void subsequencesWithSumK(vector<int>& arr, int k) {

    vector<int> ds;
    printSub(0, ds, 0, k, arr, arr.size());
}
    
Time Complexity: O(2^n × n)
Space Complexity: O(n) (recursion stack + current subsequence)   */




/* return a vector containing all subsequences whose sum is 'k'

void solve(int index, vector<int>& nums, int k, int sum,
vector<int>& ds, vector<vector<int>>& ans) {
        
        if(index == nums.size()) {
            if(sum == k) ans.push_back(ds);
            return;
        }

        // take
        ds.push_back(nums[index]);
        solve(index + 1, nums, k, sum + nums[index], ds, ans);
        ds.pop_back();

        // not take
        solve(index + 1, nums, k, sum, ds, ans);
    }

vector<vector<int>> subsequencesWithSumK(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, k, 0, ds, ans);
        return ans;
}

Time Complexity: O(2^n × n)
Space Complexity: O(2^n × n) (result storage) + O(n) recursion stack


approach: 
taking sum as a parameter using pick and non pick
*/