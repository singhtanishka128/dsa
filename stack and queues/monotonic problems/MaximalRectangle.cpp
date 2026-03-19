/* Maximum Rectangle Area with all 1's
Problem Statement: Given a m x n binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

eg: matrix given:
        {'1','0','1','0','0'}
        {'1','0','1','1','1'}
        {'1','1','1','1','1'}
        {'1','0','0','1','0'}

largest rectangle containing only 1's and its area:
'1','1','1'
'1','1','1'
area = 3*2 = 6 (ans)  */


/* optimal: 

//calc largest rectangle area from histogram
int LHist(vector<int>&arr){
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

//main 
int maximalRectangle(vector<vector<char>>& matrix){
if(matrix.empty()) return 0;
int maxArea=0;
int n=matrix.size(); //rows
int m=matrix[0].size(); //cols
vector<vector<int>> prefixSum(n, vector<int>(m, 0));

    ///prefixSum ready
    for(int j=0; j<m; j++){
        int sum = 0;
        for(int i=0; i<n; i++){
            if(matrix[i][j] == '1'){
            sum += 1;
            }
            else{
            sum = 0;
            }
            prefixSum[i][j]=sum;
        }
    }

    ///compute all rows
    for(int i=0; i<n; i++){
       maxArea= max(maxArea, LHist(prefixSum[i])); //sending each row entirely
    }
    return maxArea;
}

tc : O(mxn) + O(nx2m)
sc: O(mxn) + O(n)

we create a dummy matrix initially initialised with 0, 
which will contain the prefix sum column wise from top to down summation
we traverse col wise, if any matrix cell is 0, sum=0
once the prefix sum matrix is ready we will treat each row as an array of heights of buildings
to calculate the largest rectangular area from the assumed histogram

*/