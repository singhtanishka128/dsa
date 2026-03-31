/* return kth smallest element from an array

eg: arr[7,10,4,3,20,15] k=3
3rd smallest el in array is 7

brute: 

int Kthsmallestelement(vector<int> &arr, int k){
    sort(arr.begin(), arr.end());
    return arr[k-1];
}

tc: O(n log n)
sc: O(1)



optimal:

int Kthsmallestelement(vector<int> &arr, int k){
    priority_queue<int>maxH;
    for(int i=0; i<arr.size(); i++){
        maxH.push(arr[i]);
        if(maxH.size() > k){
            maxH.pop();
        }
    }
    return maxH.top();
}

tc: O(n log k)
sc: O(k) using heap 


*/