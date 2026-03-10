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

*/