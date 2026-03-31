/* sum of elements between k1-th smallest and k2-th smallest numbers
arr[] = [1,3,12,5,15,11] k1=3, k2=6
ans = 23



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

int sumBetweenK1K2(vector<int> &arr, int k1, int k2){

    int first = Kthsmallestelement(arr,k1);
    int second = Kthsmallestelement(arr,k2);

    int sum=0;
    for(int i=0; i<arr.size(); i++){
       if(arr[i] > first && arr[i] < second){
           sum=sum+arr[i];
        }
    }

    return sum;
}

tc: O(n log k)
sc: O(k)

*/