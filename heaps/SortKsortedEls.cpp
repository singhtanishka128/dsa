/* sort k sorted elements or sort the nearly sorted array
 
brute: 

vector <int> nearlySorted(int arr[], int n, int k) {
   sort(arr.begin(),arr.end() );
   vector<int>ans(arr.begin(),arr.end());
   return ans;
}

tc: O(n log n)
sc: O(n)


optimal: 

vector <int> nearlySorted(int arr[], int n, int k){

    priority_queue<int,vector<int>,greater<int>> minh;
    vector<int>ans;

        for(int i=0;i<n;i++)
        {
            minh.push(arr[i]);
            if(minh.size() > k)
            {
                ans.push_back(minh.top());
                minh.pop();
            }
        }

        while(minh.size() > 0)
        {
            ans.push_back(minh.top());
            minh.pop();
        }

    return ans;
}

tc: O(n log k)
sc: O(k)

*/