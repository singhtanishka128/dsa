/* sum of subarray ranges: 
Problem Statement: Given an integer array nums, determine the range of a subarray, defined as the difference between the largest and smallest elements within the subarray. Calculate and return the sum of all subarray ranges of nums.
A subarray is defined as a contiguous, non-empty sequence of elements within the array.

Example 1:
Input:
 nums = [1, 2, 3]
Output:
 4
Explanation:
 The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4. */

/* brute: generating all subarrays

    long long subArrayRanges(vector<int> &arr) {
        
        int n = arr.size();
        long long sum = 0;
        
        for(int i=0; i < n; i++) {
            
            int smallest = arr[i];
            int largest = arr[i];
            
            for(int j=i; j < n; j++) {
                
                smallest = min(smallest, arr[j]);                
                largest = max(largest, arr[j]);

                sum += (largest - smallest);
            }
        }        
        return sum;
    }

tc: O(n^2)
sc: O(1)  

genrate all subarrays, store smallest and largest for each 
calc range (largest-smallest), sum up. */



/* optimal: 



*/

