/* print only 1 subsequence with given sum k */

/*
bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {

    if(ind == n) {
        
        if(s == sum) {   //basecase
            for(auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        else return false;
    }

    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];

    if(printS(ind + 1, ds, s, sum, arr, n) == true) {
        return true; //to avoid further recursion calls
    }

    s -= arr[ind];
    ds.pop_back();

    // not pick
    if(printS(ind + 1, ds, s, sum, arr, n) == true) return true;  //to avoid further recursion calls

    return false;  //if none of the calls return true, return false
}


Time Complexity:
O(2^n)

Space Complexity:
O(n)


approach: using true false,
if the base case passes return true 
making fn call bool
putting both the pick and not-pick fn call inside if 
checking if its true, return true thereby avoiding further recursion calls


*/