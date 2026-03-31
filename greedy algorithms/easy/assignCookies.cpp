/* Assign Cookies

Problem Statement: Consider a scenario where a teacher wants to distribute cookies to students, 
with each student receiving at most one cookie. 
Given two arrays, student and cookie, the ith value in the student array describes the minimum size of cookie 
that the ith student can be assigned. The jth value in the cookie array represents the size of the jth cookie. 
If cookie[j] >= student[i], the jth cookie can be assigned to the ith student. 
Maximize the number of students assigned with cookies and output the maximum number.


int findContentChildren(vector<int>& student, vector<int>& cookie) {
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        int studentIndex = 0; 
        int cookieIndex = 0;  

        while (studentIndex < student.size() && cookieIndex < cookie.size()) {
            if (cookie[cookieIndex] >= student[studentIndex]) {
                studentIndex++; 
            }
            cookieIndex++; 
        }

        return studentIndex;
    }

    tc : O(n log n + m log m + n + m)
    sc : O(1)


*/