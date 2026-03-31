/* Fractional Knapsack Problem : Greedy Approach

Problem Statement: The weight of N items and their corresponding values are given. 
We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.

Input:
 val = [60, 100, 120], wt = [10, 20, 30], capacity = 50  
Output:
240.000000 



struct Item {
    int value;
    int weight;
};

class Solution {
public:

    bool static comp(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;  
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        
        sort(arr, arr + n, comp); 
        int curWeight = 0;  
        double finalvalue = 0.0;  

        for (int i = 0; i < n; i++) {

            if (curWeight + arr[i].weight <= W) 
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;  

            } 
            else  //take the fractional part
            {      
                               
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain; 
                break;  // Break as we have filled the knapsack
            }
        }

        return finalvalue;  
    }
};

tc: O(n log n + n)
sc: O(1)

*/