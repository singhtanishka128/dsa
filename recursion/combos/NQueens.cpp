/* N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle

Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that 
no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. 
Each solution contains a distinct boards configuration of the queen's placement, 
where ‘Q’ and ‘.’ indicate queen and empty space respectively.

Input: N = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]] */


/* conditions:

1. each row must have only 1 queen
2. each col must have only 1 queen
3. no 2 queens should attack each other  */


/* brute: 

    bool isSafe(int row, int col, vector<string> &board, int n) {
        int duprow = row;
        int dupcol = col;

        // upper diagonal
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;

        // left side
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow;
        col = dupcol;

        // lower diagonal
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i = 0; i < n; i++) {
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }

Time Complexity: O(N!*N), we try all possible permutations of placing the queens and check for safety.
Space Complexity: O(N^2 + N), additional space used for storing distinct boards and stack space.


logic: 
creating empty board of size n x n ->
vector<string> board(n);
string s(n, '.');

for(int i = 0; i < n; i++) {
    board[i] = s;
}
Example if n = 4:
. . . .
. . . .
. . . .
. . . . 

in order to fill a Q in a col, we are checking for each row (row->for loop)

modifications are done using orig row,col value

to store the original row, col value to use them in every side/diagonal checking
int duprow = row;
int dupcol = col;

to get original row,col value in every checking
row = duprow;
col = dupcol; */




/* optimal: creating a hash

    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               vector<int> &leftRow, vector<int> &upperDiagonal,
               vector<int> &lowerDiagonal, int n) {

        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {

            if(leftRow[row] == 0 &&
               lowerDiagonal[row + col] == 0 &&
               upperDiagonal[n - 1 + col - row] == 0) {

                board[row][col] = 'Q';

                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                board[row][col] = '.';

                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');
        for(int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2*n - 1, 0);
        vector<int> lowerDiagonal(2*n - 1, 0);

        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

        return ans;
    }

Time Complexity: O(N!), we try all possible permutations of placing the queens.
Space Complexity: O(N), three boolean arrays are stored to check for safety.

approach:
take n as 8
vector<int> leftRow(n, 0);  -> for checking of rows in the left
vector<int> upperDiagonal(2*n - 1, 0);   (suppose creating a matrix of n x n, filling each cell with value (formula)row+col, largest formula value in matrix will be 2*n-2(eg 14) so we want a hash of size (2*n - 1) (eg 15))
vector<int> lowerDiagonal(2*n - 1, 0);   (suppose creating a matrix of n x n, filling each cell with value (n-1 + col-row), largest formula value in matrix will be 2*n-2(eg 14) so we want a hash of size (2*n - 1) (eg 15)  )
if we place any queen anytime, mark board Q ans simultaneously mark each hash with 1
while backtracking, we unmark the queen Q, and simultaneously unmark each hash with 0

*/