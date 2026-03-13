/*  Subset Sum : Sum of all Subsets
Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order. 


Input: N = 3, arr[] = {5,2,1}
Output: [0,1,2,3,5,6,7,8]
Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

Input: N=3,arr[]= {3,1,2}
Output: [0,1,2,3,3,4,5,6]
Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6
*/


/*brute: using power set:

vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        vector<int> sums;

        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += arr[i];
                }
            }

            sums.push_back(sum);
        }

        sort(sums.begin(), sums.end());
        return sums;
    }

TC: O(n * 2^n)
SC: O(2^n)

we find all the subsets using powerset, instead of making subsequence we keep on adding elements for each subsequence in sum var
and push it in array. */



/*  optimal: pick, not pick

    void findSums(int index, int currentSum, vector<int>& arr, vector<int>& sums) {
        if (index == arr.size()) {
            sums.push_back(currentSum);
            return;
        }

        findSums(index + 1, currentSum + arr[index], arr, sums);  //pick

        findSums(index + 1, currentSum, arr, sums);  //not pick
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sums;
        findSums(0, 0, arr, sums);
        sort(sums.begin(), sums.end()); // Sort in increasing order
        return sums;
    }

Time Complexity: O(2^n) subsets + Sorting O(2^n log(2^n)) = O(2^n log(2^n)).
Space Complexity: O(2^n) subsets + Recursion uses an additional O(n) stack space due to function calls,
so total auxiliary space is O(2^n + n).

*/