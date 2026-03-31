/* N meetings in one room

Problem Statement: There is one meeting room in a firm. 
You are given two arrays, start and end each of size N. 
For an index ‘i’, start[i] denotes the starting time of the ith meeting 
while end[i] will denote the ending time of the ith meeting. 
Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time. 
Print the order in which these meetings will be performed.

Examples 
Input: N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
Output: [1, 2, 4, 5] */

 /*  optimal: greedy

struct Meeting {
    int start;
    int end;
    int index;
};

bool compare(Meeting &a, Meeting &b) {
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}

vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    
    vector<Meeting> meetings;

    for (int i = 0; i < n; i++) {
        Meeting m;
        m.start = start[i];
        m.end = end[i];
        m.index = i + 1;
        meetings.push_back(m);
    }

    sort(meetings.begin(), meetings.end(), compare);

    vector<int> result;

    int cnt = 1;
    int freeTime = meetings[0].end;

    result.push_back(meetings[0].index);

    // Start from second meeting
    for (int i = 1; i < n; i++) {
        if (meetings[i].start > freeTime) {
            cnt++;
            result.push_back(meetings[i].index);
            freeTime = meetings[i].end;
        }
    }

    return result;
}

tc: O(2n + n log n)
sc: O(3*n + n)

 */