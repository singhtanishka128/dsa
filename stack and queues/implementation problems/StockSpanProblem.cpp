/* Problem Statement: Given an array arr of size n, where each element arr[i] represents the stock price on day i. Calculate the span of stock prices for each day.
The span Sᵢ for a specific day i is defined as the maximum number of consecutive previous days (including the current day) for which the stock price was less than or equal to the price on day i.

Input:
 n = 7, arr = [120, 100, 60, 80, 90, 110, 115]
Output:
 1 1 1 2 3 5 6  */

/* brute: 

 vector <int> stockSpan(vector<int> arr, int n) { 
        vector<int> ans(n);        
        for(int i=0; i < n; i++) {            
            int currSpan = 0;            
            for(int j=i; j >= 0; j--) {
            
                if(arr[j] <= arr[i]) {
                    currSpan++;
                }
                
                else break;
            }

            ans[i] = currSpan;
        }
        return ans;
}

Time Complexity: O(N²), since we are using two nested loops.
Space Complexity: O(1), since we are using only a couple of variables.  */



/* optimal: 

leetcode question pattern:  
This is a Class Design + Stack Optimization problem.
You don’t get all inputs at once
You process one price per function call
You must maintain state between calls

class StockSpanner {
    stack<pair<int,int>> st;
    int ind = -1;
    public:
    StockSpanner() {
        ind=-1;        
        while(!st.empty()) st.pop(); //clear stack
    }
    
    int next(int price) {
        ind  = ind +1;
        while(!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return ans;
    }
};

tc: O(2n)
sc: O(n)

 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 
cuurent index - wherever the pge occurred = no. of consecutive days
storing <pge value, index> pair in stack
if stack is empty, we can let <-1, -1>

for any el if i see the top containing  < or = element, i'll kick them off
because at all time, i wanna see nge for all the respective el at the top
maintaining monotonicity.

*/