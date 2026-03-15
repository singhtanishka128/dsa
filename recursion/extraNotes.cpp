/*
# Which sorting algorithm does C++ STL sort use?
Introsort (Quicksort + Heapsort + Insertion Sort)

sort() is not stable.
If stability is needed, STL provides:
stable_sort() which uses Merge Sort internally.

sort()        → Introsort
stable_sort() → Merge Sort
tc of both : O(n log n)

# Auxiliary space → extra memory used by an algorithm

#
if->
x=s.top();
s.pop();
is happening, it means stack is being emptied and x would always store the 0th (bottomMost) element 

# string.back() in C++ simply means:
Give me the last character of the string.

#In C/C++, an if without braces {} only controls the next single statement.

Example:
if (x > 0)
    cout << "Positive";   // only this is inside the if
cout << "Hello";          // this runs ALWAYS

# correct way of iterating through characters

for (char c = 0; c < s.length(); c++) { xyz } is wrong

correct:
for (char c : s)

       or

for (int i = 0; i < s.length(); i++) {
    char c = s[i];
}

# subsequence vs subset vs subArray

subarray (or substring for strings) → contiguous elements only. no skipping allowed.
example: array [1,2,3,4] → subarrays: [1], [2,3], [3,4], [1,2,3], [2,3,4]… etc

subsequence → can skip elements, must keep order.
example: [1,2,3,4] → subsequences: [1,3], [2,4], [1,2,4], [1,2,3,4]… etc

subset → just pick any elements, order doesn’t matter at all.
example: [1,2,3] → subsets: {1}, {2,3}, {1,3}… etc
notice how {3,2} isn’t listed separately since {2,3} and {3,2} are same cause order doesnt matter. OOOOOOOOOOHHHHHHHHHHHHHHHHHHHH lmao

# string.push_back(this) = add this character to the end of the string.

*/