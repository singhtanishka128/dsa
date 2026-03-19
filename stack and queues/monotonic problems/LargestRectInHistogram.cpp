/* largest rectangle in histogram:

Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1 return the area of the largest rectangle in histogram. .
Input: N =6, heights[] = {2,1,5,6,2,3}
Output: 10  */



/* brute: precomputing nse, pse

vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
        }
    return nse;
}


vector<int> findPSE(vector<int> &arr){
int n= arr.size();
vector<int>pse(n);
stack<int>st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){ //arr[st.top()] =>because stack stores indices
        st.pop();
        }
     pse[i]=st.empty()? -1 : st.top();
     st.push(i); //storing index
    }
return pse;
}


//main
int area(vector<int>arr){

//both storing indices instead of value
vector<int>nse = findNSE(arr);
vector<int>pse = findPSE(arr);
int largestArea = 0;
int n = arr.size();
for(int i=0; i<n; i++){
  largestArea = max(largestArea, arr[i]*(nse[i]-pse[i]-1));
}
return largestArea;  
}

tc: O(5n)
sc: O(2n)+O(2n) X 2 pass soln X optimise

for each block, width = 1,
for every block i can go until a smaller el is encountered
i need pse and nse for every block, so pse and nse are my stopping points
between these 2 i can form my area
if i dont have nse for any block then assign nth index to be the nse for that block
*/





/* optimal: touching els one by one and kicking them out

int area(vector<int>&arr){
stack<int>st;
int maxArea=0;
int n= arr.size();
    for(int i=0; i<n; i++){
          while(!st.empty() && arr[st.top()]>arr[i]) 
          {
          int element = st.top(); 
          st.pop();
          int nse = i;  
          int pse = st.empty() ? -1 : st.top();  
          maxArea = max(maxArea, arr[element]*(nse-pse-1));
          }
    st.push(i);
    }

    //these guys do not have nse
    while(!st.empty()){
    int nse = n;
    int element = st.top();
    st.pop();
    int pse = st.empty() ? -1 : st.top();
    maxArea = max(maxArea, arr[element]*(nse-pse-1));
    }

   return maxArea;
}

tc: O(n)+O(n) (traversal)+(popping at max n els from stack)
sc: O(n)

stack, nse, pse all stores indices
whenever stacks top > currEl we pop the (top) greater el because currEl is smaller (so this is nse for this greater el)
this greater el is the el im computing the area for. pse for this (top) greater el will be the previous top before this
or if the stack is empty pse will be -1. 
after all that if stack is still not empty, this means the remaining els donot have nse so nse for them will be nth index
and pse will be previous top or -1 if st is empty */