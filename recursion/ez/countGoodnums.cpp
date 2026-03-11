/*
Problem Statement: A digit string is considered good if the digits at even indices (0-based) are even digits (0, 2, 4, 6, 8) 
and the digits at odd indices are prime digits (2, 3, 5, 7).
Given an integer n, return the total number of good digit strings of length n. 
As the result may be large, return it modulo 10^9 + 7. 

A digit string is a string consisting only of the digits '0' through '9'. It may contain leading zeros.

Example 1:
Input:
 n = 1
Output:
 5
Explanation:
 Only one index (0) → must be even.
Valid strings: "0", "2", "4", "6", "8"

Example 2:
Input:
 n = 2
Output:
 20
Explanation:
 Index 0: 5 options (even digits)
Index 1: 4 options (prime digits)
Total: 5 * 4 = 20  */


/* brute force:

const int MOD = 1e9 + 7;

int countGoodNumbers(int index, int n) {
    if (index == n) return 1;

    if (index % 2 == 0) {
        return (5 * countGoodNumbers(index + 1, n)) % MOD;
    } 
    else {
        return (4 * countGoodNumbers(index + 1, n)) % MOD;
    }
}

int goodString(int n) {
    return countGoodNumbers(0, n);
}

tc: O(n)
sc: O(n)


approach:

1.if index=n, base case reached return 1
2.if even index -> 5 * next , odd index -> 4 * next
3.apply % MOD wherever multiplication involved


(5 even possibilities at even index : 0,2,4,6,8
4 prime possibilities at odd index : 2,3,5,7)

chatgpt->
Dry Run Example, take n = 3

We call:
goodString(3) which calls countGoodNumbers(0,3)
Step 1
countGoodNumbers(0,3)
index = 0 (even)
So:
return 5 * countGoodNumbers(1,3)

Step 2
countGoodNumbers(1,3)
index = 1 (odd)
So:
return 4 * countGoodNumbers(2,3)

Step 3
countGoodNumbers(2,3)
index = 2 (even)
So:
return 5 * countGoodNumbers(3,3)

Step 4 (Base Case)
countGoodNumbers(3,3)
Since index == n
return 1

Now recursion resolves upward
From Step 3
5 * 1 = 5
From Step 2
4 * 5 = 20
From Step 1
5 * 20 = 100

Final answer: 100
Visual recursion tree

Think of it like multiplying choices per position:
index 0 → 5 choices
index 1 → 4 choices
index 2 → 5 choices
So: 5 × 4 × 5 = 100

This recursion actually calculates: 5^(total even indices) * 4^(total odd indices)  */





/*
optimal: (using binary exponentiation)

const long long MOD = 1e9 + 7;

    long long powerr(long long base, long long power) {
        long long result = 1;

        while (power > 0) {
            if (power % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            power = power / 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenPart = powerr(5, even);
        long long oddPart = powerr(4, odd);

    return (evenPart * oddPart) % MOD;
}

eg:
n=3 -> 0,1,2
even indices (0,2) = 2 -> ((3+1)/2)
odd indices (1) = 1 -> (3/2)


tc: O(log n)
sc: O(1)

approach:
1.calculate total even and odd indices
2.calculate evenpart and oddpart
3.apply % MOD wherever multiplication involved
4.return product of evenpart and oddpart

*/



