/* Shortest Job First (or SJF) CPU Scheduling

Problem Statement: Given a list of job durations representing the time it takes to complete each job. 
Implement the Shortest Job First algorithm to find the average waiting time for these jobs. 

Example 1:
Input:jobs = [3, 1, 4, 2, 5]
Output: 4   


greedy:

 float calculateAverageWaitTime(vector<int>& jobs) {
        sort(jobs.begin(), jobs.end());

        float waitTime = 0; 
        int totalTime = 0;   
        int n = jobs.size();

        for (int i = 0; i < n; i++) {
            waitTime += totalTime;  
            totalTime += jobs[i];   
        }

        return (waitTime / n);
    }
tc: O(n) + O(n log n)
sc: O(1)

*/

