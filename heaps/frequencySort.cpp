/* frequency sort: 

eg: arr [] = [1,1,1,3,2,2,4]
ans[] = [1,1,1,2,2,3,4]


3 approaches all same complexity tc : O(n log n), sc: O(n)

1. Brute Force (Map + Vector + Sort)

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freq;

    // count frequency
    for (int num : nums) {
        freq[num]++;
    }

    // convert to vector
    vector<pair<int, int>> vec;
    for (auto it : freq) {
        vec.push_back({it.first, it.second}); // {value, freq}
    }

    // custom sort
    sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b){
        if (a.second == b.second)
            return a.first > b.first; // value desc
        return a.second < b.second;   // freq asc
    });

    // rebuild array
    vector<int> ans;
    for (auto it : vec) {
        int val = it.first;
        int f = it.second;
        while (f--) ans.push_back(val);
    }

    return ans;
}

Time: O(n log n)
Space: O(n)





2. Heap (Priority Queue) Approach

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int,int> freq;

    for (int num : nums) freq[num]++;

    // min heap
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        function<bool(pair<int,int>, pair<int,int>)>
    > pq([](pair<int,int> a, pair<int,int> b){
        if (a.first == b.first)
            return a.second < b.second; // value desc
        return a.first > b.first;       // freq asc
    });

    for (auto it : freq) {
        pq.push({it.second, it.first}); // {freq, value}
    }

    vector<int> ans;

    while (!pq.empty()) {
        auto [f, val] = pq.top();
        pq.pop();

        while (f--) ans.push_back(val);
    }

    return ans;
}

Time: O(n log n)
Space: O(n)





3. (Optimal among these) Sort the original array using frequency map.

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int,int> freq;

    for (int num : nums) freq[num]++;

    sort(nums.begin(), nums.end(), [&](int a, int b){
        if (freq[a] == freq[b])
            return a > b;          // value desc
        return freq[a] < freq[b];  // freq asc
    });

    return nums;
}
Time: O(n log n) (but fewer operations)
Space: O(n)
*/



/* OPtimal: Bucket Sort/Counting Sort

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int,int> freq;

    for (int num : nums) freq[num]++;

    // bucket: freq → list of numbers
    vector<vector<int>> bucket(nums.size() + 1);

    for (auto it : freq) {
        bucket[it.second].push_back(it.first);
    }

    vector<int> ans;

    for (int f = 1; f <= nums.size(); f++) {
        if (!bucket[f].empty()) {
            // sort values in descending order
            sort(bucket[f].begin(), bucket[f].end(), greater<int>());

            for (int val : bucket[f]) {
                for (int i = 0; i < f; i++) {
                    ans.push_back(val);
                }
            }
        }
    }

    return ans;
}

Time: O(n) (almost, ignoring small sorts inside buckets)
Space: O(n)

*/