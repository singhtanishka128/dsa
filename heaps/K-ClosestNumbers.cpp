/* Return K closest numbers to a given reference number x from the array.
“Find k closest elements to x (excluding x itself)”

eg: a[] = [5,6,7,8,9] k=3 x=7
ans [] = [6,7,8]


brute: using max heap (Max-heap stores (difference, element))

vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
    priority_queue<pair<int, int>> maxH; 

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) continue;
        maxH.push({abs(arr[i] - x), arr[i]}); 
        if (maxH.size() > k) {
            maxH.pop(); 
        }
    }

    vector<int> ans;
    while (!maxH.empty()) {
        ans.push_back(maxH.top().second); 
        maxH.pop();
    }

  reverse(ans.begin(),ans.end());
    return ans;
}

tc: O(n log k)
sc: O(k)





optimal: using binary search and 2-pointers



*/