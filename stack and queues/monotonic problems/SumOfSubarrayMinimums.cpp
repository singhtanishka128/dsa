/* 
Problem Statement: Given an array of integers arr of size n, calculate the sum of the minimum value in each (contiguous) subarray of arr. 
Since the result may be large, return the answer modulo 10⁹ +7. 

Input:
 arr = [3, 1, 2, 5]
Output:
 18
Explanation:
 The minimum of subarrays: [3], [1], [2], [5], [3, 1], [1, 2], [2, 5], [3, 1, 2], [1, 2, 5], [3, 1, 2, 5] are 3, 1, 2, 5, 1, 1, 2, 1, 1, 1 respectively and their sum is 18. */




/* brute: 

 int sumSubarrayMins(vector<int> &arr) {
       
       int n = arr.size();
       int mod = 1e9 + 7; 
       int sum = 0;
       
       for(int i=0; i < n; i++) {
           
           int mini = arr[i];
           
           for(int j=i; j < n; j++) {
               mini = min(mini, arr[j]);
               sum = (sum + mini) % mod;
           }
       }
       
       return sum;
   }

generate all subarrays, check mini, add to sum  */

/* optimal: 


*/