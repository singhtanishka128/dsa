/*
Generate all binary strings: STRING WITH NO CONSECUTIVE 1s

Problem Statement: Given an integer n, return all binary strings of length n that DO NOT contain consecutive 1s. 
Return the result in lexicographically increasing order.

Lexicographically basically means dictionary order.
You compare characters from left to right.

A binary string is a string consisting only of characters '0' and '1'.  

Example 1:
Input:
 n = 3  
Output:
 ["000", "001", "010", "100", "101"]  

Example 2:
Input:
 n = 2  
Output:
 ["00", "01", "10"] 

 */




/* brute:

void generate(int n, string curr, vector<string>& result) {
   
    if (curr.length() == n) {                      // Base case
        result.push_back(curr);
        return;
    }
    generate(n, curr + "0", result);               // Always try adding '0'
    if (curr.empty() || curr.back() != '1') {      // Add '1' only if previous char is not '1'
        generate(n, curr + "1", result);
    }
}

void generateAllBinaryStrings(int n){

    vector<string> result;
    generate(n, "", result);
    for(auto &s : result){
        cout << s << endl;
    }
}

tc: O(n * F(n))   F(n)=nth finonacci number
sc: O(n*F(n))    (result)+O(n) (recursion stack)

*/
