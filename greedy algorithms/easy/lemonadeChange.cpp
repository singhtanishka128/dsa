/* Lemonade Change

Problem Statement: Given an array representing a queue of customers and the value of bills they hold, 
determine if it is possible to provide correct change to each customer. 
Customers can only pay with 5$, 10$ or 20$ bills and we initially do not have any change at hand. 
Return true, if it is possible to provide correct change for each customer otherwise return false.

Example 1:
Input: bills = [5, 5, 5, 10, 20]
Output: True  */


/*
bool lemonadeChange(vector<int>& bills) {

        int five = 0; // Counter for $5 bills
        int ten = 0;  // Counter for $10 bills

        for (int i=0; i<bills.size(); i++) {
        int bill = arr[i];
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five > 0) {
                    five--; 
                    ten++;  
                } else {
                    return false; 
                }
            }
            else { 
                if (five > 0 && ten > 0) {
                    five--; 
                    ten--;  
                } 
                else if (five >= 3) {
                    five -= 3; 
                } 
                else {
                    return false; 
                }
            }
        }
        return true; 
    }

tc: O(n)
sc: O(1)

*/