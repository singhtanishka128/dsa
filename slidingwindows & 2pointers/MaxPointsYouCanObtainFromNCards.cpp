/*  Maximum point you can obtain from cards
Problem Statement: Given N cards arranged in a row, each card has an associated score denoted by the cardScore array. Choose exactly k cards. In each step, a card can be chosen either from the beginning or the end of the row. The score is the sum of the scores of the chosen cards.

Input :cardScore = [1, 2, 3, 4, 5, 6] , k = 3
Output : 15
Explanation :Choosing the rightmost cards will maximize your total score. 
So optimal cards chosen are the rightmost three cards 4 , 5 , 6.
Th score is 4 + 5 + 6 => 15.  */



/* optimal: 

int MaxPoints(vector<int> &arr, int k){

   int lsum=0, rsum=0, maxSum=INT_MIN;

   for(int i=0; i<=k-1; i++){
       lsum=lsum + arr[i];
    }

    maxSum = max(maxSum, lsum);

    int n= arr.size();
    int rindex=n-1;

    for(int i=k-1; i>=0; i--){
       lsum=lsum - arr[i];
       rsum=rsum + arr[rindex];
       rindex = rindex-1;
       maxSum=max(maxSum, lsum + rsum);
    }

 return maxSum;
}

tc: O(2k)
sc: O(1)
*/