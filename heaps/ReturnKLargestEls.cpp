/* return k largest elements from a given array 

eg: arr[] = [7,10,4,3,20,15] k=3
    ans[] = [20,15,10]

brute: using sorting technique

vector<int> KlargestElements(vector<int>&arr, int k){
    vector<int>temp;
    sort(arr.begin(), arr.end());
    int n=arr.size();
    for(int i=n-1; i>=n-k; i--){
        temp.push_back(arr[i]);
    }
    return temp;
}

tc: O(n log n)+ O(k)
sc: O(k)



optimal: using heap data st

vector findKLargest(vector<int>& nums, int k) {

    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
        if(pq.size() > k) {
          pq.pop();
        }
    }

    vector<int>ans;
    while(pq.size()!=0){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans; 
}

tc: O(n log k) + O(k)
sc: O(k)


*/