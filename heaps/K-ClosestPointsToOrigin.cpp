/* given a 2D array containing graphical coordinates, return the K closest points to origin
 
eg: arr = [(1,3) , (-2,2) , (5,8) , (0,1)]
    ans = [(0,1) , (-2,2)]


optimal:

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, vector<int>>> maxH;

    for (int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];

        int dist = (x * x) + (y * y);

        maxH.push({dist, points[i]});

        if (maxH.size() > k) {
            maxH.pop();
        }
    }

    vector<vector<int>> ans;

    while (!maxH.empty()) {
        ans.push_back(maxH.top().second);
        maxH.pop();
    }

    return ans;
}


tc: O(n log k)
sc: O(k)


*/
