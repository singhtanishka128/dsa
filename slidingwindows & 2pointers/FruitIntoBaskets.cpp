/* Fruit into baskets: 
Problem Statement: There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.
The goal is to gather as much fruit as possible, adhering to the owner's stringent rules :

There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.
Once reaching a tree with fruit that cannot fit into any basket, stop.
Return the maximum number of fruits that can be picked.

Input :fruits = [1, 2, 1]
Output :3

Input : fruits = [1, 2, 3, 2, 2]
Output : 4 */



/* brute: 

 int totalFruit(vector<int>& fruits) {

        int maxFruits = 0;
        for (int start = 0; start < fruits.size(); ++start) {

            unordered_map<int, int> basket;
            int currentCount = 0;

            for (int end = start; end < fruits.size(); ++end) {

                basket[fruits[end]]++;

                if (basket.size() > 2) {
                    break;
                }

                currentCount++;
            }

            maxFruits = max(maxFruits, currentCount);
        }

        return maxFruits;
    }

tc: O(n^2)
sc: O(1)  */



/* better: 


*/