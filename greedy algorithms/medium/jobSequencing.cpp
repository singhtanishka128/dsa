/* Job Sequencing Problem

Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. 
The profit can only be earned upon completing the job within its deadline. 
Find the number of jobs done and the maximum profit that can be obtained. 
Each job takes a single unit of time and only one job can be performed at a time. 

Example 1:
Input:
  
N = 4, Jobs = {(1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30)}  
Output:
 2 60  


optimal: greedy


    struct Job {
       int id; 
       int dead;
       int profit; 
    };

      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit); 
      }

   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);

      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
        maxi = max(maxi, arr[i].dead);  
      }

      int slot[maxi + 1];
      for (int i = 0; i <= maxi; i++)
        slot[i] = -1;  

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {

         for (int j = arr[i].dead; j > 0; j--) {

            if (slot[j] == -1) {  
                slot[j] = i;  
                countJobs++;  
                jobProfit += arr[i].profit;  
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }

tc: O(n log n + n*maxDeadline)
sc: O(maxDeadline)

more optimal: apply DSU graphs

*/