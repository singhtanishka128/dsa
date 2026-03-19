/* Sliding Window Maximum:
Problem Statement: Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window..

Input: arr = [4,0,-1,3,5,3,6,8], k = 3
Output: [4,3,5,5,6,8] */


/* brute:

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
int n= nums.size();
vector<int> ans;
   for(int i=0; i<=n-k; i++){
       int maxi = nums[i];
       for(int j=0; j<=i+k-1; j++){
          maxi = max(maxi, nums[j]);
        }
    ans.push_back(maxi);
   }
  return ans;
}

tc: O(n-k)*k
sc: O(n-k)
*/




/* optimal: 

 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int n=nums.size();

        for (int i = 0; i < n; i++) {

            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
}

Time Complexity: O(n) Each element is pushed and popped from the deque at most once, so overall traversal is linear.
Space Complexity: O(k) Deque stores at most k elements at any time, one for each index in the window.

Remove elements from the front if they are out of this window's range
Remove all elements from the back that are smaller than current element
if deque is empty or conditions satisfy Add the current index to the deque
Once the first window is completed, add front element to result
k-1 -> From this point onward, every index gives me a new valid window, 
eg k=3 so from 2 onwards , a k-sized window ends at every falling index at and beyond 2
*/