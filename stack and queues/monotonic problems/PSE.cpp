/* PSE : previous smaller element in left:

arr= [4   5   2   10   8]
pse= [-1  4  -1   2    2]

brute: 

vector<int> prevSmallerEl(vector<int>arr){
int n = arr.size();
vector<int>pse(n,-1);
   for(int i=0; i<n; i++){
       for(int j=i-1; j--){
           if(arr[j]<arr[i]){
            pse[i]=arr[j];
            break;
           }
       }
   }
   return pse;
}

tc: O(n^2)
sc: O(n)

optimal: 

vector<int> prevSmallerEl(vector<int> arr){
int n= arr.size();
vector<int>pse(n);
stack<int>st;
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top()>=arr[i]){
        st.pop();
        }
     pse[i]=st.empty()? -1 : st.top();
     st.push(arr[i]);
    }
return pse;
}

tc: O(2n)
sc: O(n) + O(n)

iterate forward from left to right
if nothing in stack, pse = -1
stack is monotonically increasing
stacks top is the pse */