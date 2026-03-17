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



*/