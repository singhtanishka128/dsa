/* return top k frequent numbers from the array;

eg: a[] = [1,1,1,3,2,2,4] k=2
ans[] = [1,2]

optimal: using map & minHeap

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;

    for (int i=0; i<nums.size() ; i++) {
        mpp[nums[i]]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    for (auto it : mpp) {
        minHeap.push({it.second, it.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> v;
    while (!minHeap.empty()) {
        v.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return v;
}

tc: O(n log k)
sc=> O(n + k + k)       (map,heap,vector)
  => O(n+2k) => O(n)

*/