/* Celebrity problem:
Problem Statement: A celebrity is a person who is known by everyone else at the party but does not know anyone in return. 
Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, 
determine if there is a celebrity at the party. 
Return the index of the celebrity or -1 if no such person exists.

Note that M[i][i] is always 0.

Example 1:
Input:
 M = [ [0, 1, 1, 0], [0, 0, 0, 0], [1, 1, 0, 0], [0, 1, 1, 0] ]
Output:
 1
Explanation:
 Person 1 does not know anyone and is known by persons 0, 2, and 3. Therefore, person 1 is the celebrity. */



/*logic:
1. im a celebrity only if everybody knows me but i dont know anyone. 
2. mat[i][j]=1 means i knows j, mat[i][j]=0 means i doesnt know j
3. there can only be one winner. at max 1 celebrity. else 0. see notes.
*/ 

/* brute : using 2 arrays knowMe & iKnow 

 int celebrity(vector<vector<int>> &M){
        
        int n = M.size(); //size of matrix
        vector<int> knowMe(n, 0);
        vector<int> Iknow(n, 0);
        
        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                
                if(M[i][j] == 1) {
                    knowMe[j]++;    // j is known by someone
                    Iknow[i]++;    // i knows someone
                }
            }
        }
        
        // Traverse for all persons to find the celebrity
        for(int i=0; i < n; i++) {            
            if(knowMe[i] == n-1 && Iknow[i] == 0) {
                return i;  
            }
        }        
        return -1;
    }

tc: O(n^2) + O(n)
sc: O(2n)

create 2 arrays initially containing 0s to keep a track
if there are n people in total, 1 of them is a celeb that means other n-1 are meant to be fans
arrays are to keep a track of exact n-1 fans and 0 mutuals  */



/* optimal: 

 int celebrity(vector<vector<int>> &M){
        
        int n = M.size();        
        int top = 0, down = n-1;   //pointers
        
        while(top < down) {
            
            if(M[top][down] == 1) {   //if top knows down, top isnt the celeb
                top = top + 1;        //eliminate
            }
            
            else if(M[down][top] == 1) {    //if down knows top, down isnt the celeb
                down = down - 1;           //eliminate
            }
            
            else {             //if both doesnt know each other, both cant be celeb
                top++;         //eliminated
                down--;
            }
        }
        
        // Return -1 if no celebrity is found
        if(top > down) return -1;
        
        //if i reach here it means top == down, both pointing to single person
        for(int i=0; i < n; i++) {
            if(i == top) continue;
            if(M[top][i] == 1 || M[i][top] == 0) {
                return -1;
            }
        }
        
        return top;
    }

tc: O(2n)
sc: O(1)    

at a larger frame, in order to be a celeb, entire row must be 0, entire col except diagonal cell must be 1
if found vice versa, not a celeb.

*/