/* Next Greater Element Using Stack : NGE

Problem Statement: Given an integer array A, return the next greater element for every element in A. 
The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. 
If it doesn't exist, return -1 for this element. 

Input: arr = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: In the array, the next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4 is -1, since it does not exist.

Input : arr = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1] */


/* brute:

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nge[i] = arr[j];
                break;
            }
        }
    }
    return nge;
}

tc: O(n^2)
sc: O(n) */




/* optimal:

  vector<int> nextGreater(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            if (st.empty()) res[i] = -1;

            else res[i] = st.top();

            st.push(nums[i]);
        }

        return res;
    }

tc: O(2n) see lecture
sc: O(n) + O(n)

iterating from back
storing els in decreasing order (monotonic stack concept)
remove anytime i see top is lesser than or equal to current el (keep on doing until top is > current)
if stack is empty (no greatre el) nge = -1
else nge = top
everytime after i get nge of an element, push el into stcak

*/