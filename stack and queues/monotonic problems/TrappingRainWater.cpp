/* 
Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain .
Input : height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output : 6
Explanation : Water is trapped in the dips between bars. The total trapped water units add up to 6 (1+1+2+1+1). */


/* 
brute: 

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefixMax(n);
        vector<int>suffixMax(n);

        prefixMax[0]=height[0];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],height[i]);
        }

        suffixMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i]=max(suffixMax[i+1],height[i]);
        }
     
        int water=0;
        for(int i=0;i<n;i++){
            int leftMax=prefixMax[i];
            int rightMax=suffixMax[i];
            if(height[i]<leftMax && height[i]<rightMax){
                water+=min(leftMax,rightMax)-height[i];
            }
        }
        return water;
    }

tc: O(3n)
sc: O(2n) X optimise

compute the tallest building for each index on left and right. 
water stored for each index is the min between the tallest building on left and right - height of the index building itself. */



/* optimal:

int trap(vector<int>& height) {

        int n = height.size();

        int l = 0;
        int r = n - 1;
        
        int Lmax = 0;
        int Rmax = 0;
        
        int totalWater = 0;

        while(l<r){
            if(height[l] <= height[r]){
                if(Lmax > height[l]) {     
                totalWater += Lmax - height[l]; }
                else {
                Lmax = height[l]; }
                l++;  
            }else{
                if(Rmax > height[r]){
                totalWater += Rmax - height[r]; }
                else {
                Rmax = height[r]; }
                r--;
            }
        }
    return totalWater;
 }
    

we just need tallwst building n left and currents building height to calc water stored
two pointer l at 0, r at n-1, storing tall buildings -> lMax =0, rMax=0, total =0
always traverse the smaller one between l and r
as we trverse we update the lMax and rMax
if (a[l]<=a[r] im sure on the right theres always someone greater
if( lmax > a[l]) theres a taller building on left than current one  */