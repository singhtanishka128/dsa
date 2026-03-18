/*  NSE next smaller element
Problem Statement: Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.
The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
If there is no smaller element to the right, then the NSE is -1.

Input:
 arr = [4, 8, 5, 2, 25]
Output:
 [2, 5, 2, -1, -1] */


/* 
 vector<int> nextSmallerElement(vector<int>& arr) {
        
        int n = arr.size(); 
        vector<int> nse(n, -1);
        
        for (int i = 0; i < n; i++) {
            
            int currEle = arr[i];
            
            for (int j = i + 1; j < n; ++j) {
                
                if (arr[j] < currEle) {
                    
                    nse[i] = arr[j];
                    break;
                }
            }
        }
    return nse;
    }

tc: O(n^2)
sc: O(n)  */




/* optimal : monotonic 
 vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;

        vector<int> nse(n, -1);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nse[i] = st.top();
            }

            st.push(arr[i]);
        }

        return nse;
    }

tc: O(n)
sc: o(n)

//same as nge
// Monotonic stack (increasing order from bottom to top)
// For each element, we remove all elements >= current element
// because they cannot be the next smaller element.
// The top of the stack (if exists) gives the next smaller element.

*/