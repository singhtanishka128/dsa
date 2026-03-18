/*  Next Greater Element 2: NGE2 (NGE + clockwise rotation)
Problem Statement: Given a circular integer array arr, return the next greater element for every element in arr.
The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner.
If it doesn't exist, return -1 for that element element.

Input:
 arr = [3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9]
Output:
 [10, -1, 6, 6, 2, 6, 7, 7, 9, 9, 10] */


/* brute:

vector<int> nge2(vector<int>& a) {
    int n = a.size();
    vector<int> nge(n, -1);

    for (int i = 0; i < n; i++) {

        // Step 1: check right side
        bool found = false;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                nge[i] = a[j];
                found = true;
                break;
            }
        }

        // Step 2: if not found, check from start
        if (!found) {
            for (int k = 0; k < i; k++) {
                if (a[k] > a[i]) {
                    nge[i] = a[k];
                    break;
                }
            }
        }
    }

    return nge;
}

Time → O(n²)
Space → O(n)  */




//use this brute
/* brute: circular array conecpt

 vector<int> ngeII(vector<int> arr) {
       
    int n = arr.size(); 
    vector<int> nge(n, -1);

    for(int i=0;i<n;i++){
       for(int j=i+1; j<= i+n-1; j++){
            int ind = j % n;
            if(arr[ind] > arr[i]){
                nge[i]=arr[ind];
                break;
            }
       }
    }
  return nge;
}


tc: O(n^2)
sc: O(n)

hypothetically double the array, to get the real index for hypothetical index => hypotheticalIndex % n
eg: [ 2 10 12 1 11] 2 10 12 1 11
      0  1  2 3  4  5  6  7 8  9
so 7th hypothetical index is actually 2nd (7%5 = 2)
arr[7] = 12, arr[2] = 12
i check from i+1 to i+n-1  */



/* optimal : monotonic stcak concept 

vector<int> nextGreaterElements(vector<int> arr) {
        
        int n = arr.size(); 
        vector<int> nge(n);
        stack<int> st;
        
        for(int i = 2*n-1; i >= 0; i--) {
            
            int ind = i % n;
            int currEle = arr[ind];
            
            while(!st.empty() && st.top() <= currEle) {
                st.pop();
            }
            
            if(i < n) {
            nge[i] = st.empty()? -1 : st.top();
            }
            
            st.push(currEle);
        }

        return nge;
    }

tc: O(4n)
sc: O(2n) + O(n)

double the array hypothetically, same nge concept
iterate back from hypthetical index 2n-1

*/