/* Connect Ropes: find the minimun cost of connecting the ropes from given array containing lengths of respective ropes.

arr[] = [1,2,3,4,5]
min cost = 33.

optimal cost approach:

int minCostRopes(vector<int> &arr){

   priority_queue <int , vector<int>, greater<int> >minHeap;
   int n=arr.size();
   int totalCost=0;

   for(int i=0;i<n;i++){
       minHeap.push(arr[i]);
   }

   while(minHeap.size()>=2){
      int el1 = minHeap.top();
      minHeap.pop();
      int el2 = minHeap.top();
      minHeap.pop();
      totalCost = totalCost + (el1 + el2);
      minHeap.push(el1 + el2);
   }

   return totalCost;
}

tc: O(n log n)
sc: O(n)

If interviewer asks:
“Why not sort once and then do it?”
You say:
After merging, a new rope is formed, and it must be reinserted in sorted order
Sorting again each time = inefficient
That’s why we use a min heap → dynamic sorting

*/