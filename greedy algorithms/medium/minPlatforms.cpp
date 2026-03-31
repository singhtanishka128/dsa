/* Minimum number of platforms required for a railway

Problem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of platforms needed at the railway station so that no train has to wait. 
Input:  N=6, 
arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00}
dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}
Output: 3
*/



/* brute: max number of intersection = min number of platforms req
(some test cases failing)

 int countPlatforms(int n, int arr[], int dep[]) {

        int ans = 1;
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {

                if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                    (arr[j] >= arr[i] && arr[j] <= dep[i])) {
                    count++;
                }
            }

            ans = max(ans, count);
        }

        return ans;
    }

tc: O(n^2)
sc: O(1)    */



/* optimal: greedy

int countPlatforms(int n, int arr[], int dep[]) {

        sort(arr, arr + n);
        sort(dep, dep + n);

        int platforms = 1;
        int result = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {

            if (arr[i] <= dep[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }

            result = max(result, platforms);
        }

        return result;
    }

tc: O(2*(n log n)) + O(2n)
sc: O(1) 

*/