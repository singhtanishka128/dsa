/* Asteroid Collision:
Problem Statement: Given an array of integers asteroids, where each integer represents an asteroid in a row, determine the state of the asteroids after all collisions. 
In this array, the absolute value represents the size of the asteroid, and the sign represents its direction (positive meaning right and negative meaning left). 
All asteroids move at the same speed.
When two asteroids meet, the smaller one will explode. If they are the same size, both will explode. Asteroids moving in the same direction will never meet. 

Input:
 asteroids = [2, -2]
Output:
 []

positive always move in right
negative always move in left
collision happens when 2 moving in opp directions
when 2 asteroids collide, smaller one gets destroyed, if both equal, both  destroys 

if 2, -3 collides, 2 gets destroyed, sign only represents direction*/


/* optimal : 

vector<int> asteroidCollision(vector<int> &asteroids){
        
        int n = asteroids.size();
        vector<int> st;  
        
        for(int i=0; i < n; i++) {
            
            if(asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            
            else {
                
                while(!st.empty() && st.back() > 0 && 
                st.back() < abs(asteroids[i])) {

                    st.pop_back();
                }
                
                
                if(!st.empty() && 
                    st.back() == abs(asteroids[i])) {
    
                    st.pop_back();
                }
                
               
                else if(st.empty() || st.back() < 0) {
                    
                    st.push_back(asteroids[i]);
                }
            }
        }
        
        return st;
    }

tc: O(n)
sc: O(n)

Traverse all the asteroids
if the asteroid is positive (moving right ->) push into stack
if the steroid is negative (moving left <-) collisions start happening
the one with smaller absolute value gets destroyed
if both have same value both gets destroyed 
if the negative asteroid gets destoyed we never push it into stack
only if the stack is empty or the last pushed value
(must have dominated over a positive and got pushed into stack) is negative, keep on pushing negative 
*/



