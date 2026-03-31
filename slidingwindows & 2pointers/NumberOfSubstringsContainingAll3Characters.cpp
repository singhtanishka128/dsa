/* Number of substring containing all three characters:
Problem Statement: Given a string s , consisting only of characters 'a' , 'b' , 'c'.Find the number of substrings that contain at least one occurrence of all these characters 'a' , 'b' , 'c'. 

Input : s = "abcba"
Output :  5
Explanation : The substrings containing at least one occurrence of the characters 'a' , 'b' , 'c' are "abc" , "abcb" , "abcba" , "bcba" , "cba".  */


/* brute: generate all subsstrings

 int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            vector<int> freq(3, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;   //=1

                if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {  // (freq[0]+freq[1]+freq[2]==3)
                    count++;
                }
            }
        }
        return count;
    }

tc: O(n^2)
sc: O(1)   */



/* better: once i get my first valid substring, i'll add the remaining length to the substring and break out.


 int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            vector<int> freq(3, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;    //=1

                if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {  // (freq[0]+freq[1]+freq[2]==3)
                    count=count+(n-j);
                    break;
                }
            }
        }
        return count;
    }
*/




/* optimal: 


int numberOfSubstring(string s){
vector<int> lastSeen(3, -1);
int cnt=0;
    for(int i=0; i<n; i++){
        lastSeen[s[i]-'a']=i;

        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
        cnt = cnt + (1 - min(lastSeen[0], lastSeen[1], lastSeen[2]));
        }
    }

   return cnt;
}

tc: O(n)
sc: O(1) 
*/

