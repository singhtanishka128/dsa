/* Sudoku Solver

Problem Statement: Create a program that fills in the blank cells in a Sudoku puzzle to solve it. Every sudoku solution needs to follow to these guidelines:
1) In every row, the numbers 1 through 9 must appear exactly once.
2) In every column, the numbers 1 through 9 must appear exactly once.
3) In each of the grid's nine 3x3 sub-boxes, the numbers 1 through 9 must appear exactly once.
Empty cells are indicated by the '.' character.   


    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c) return false;
            if(board[row][i]==c) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){

                if(board[row][col]=='.'){    //empty cell

                    for(char c='1'; c<='9'; c++){   //try all

                        if(isValid(board,row,col,c)){

                            board[row][col]=c;

                            if(solve(board)) return true;  //recursion unwinding

                            board[row][col]='.'; // backtrack
                        }
                    }

                    return false; // nothing worked for this empty cell
                }
            }
        }

        return true; // no empty cells → solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the nxn777777 board, we have 9 possible numbers.
Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.

logic:

we traverse the unsolved sudoku matrix and look for an empty cell,
the moment we get an empty cell we start trying out every possibility and check for validity,
if valid then makw next recursion call for next empty cell,
if the possibility of putting a number fails we return false and we backtrack, unmarking / making the marked cells empty agin

solveSudoku — entry point, calls solve()
solve — iterates every cell; when it finds an empty cell ('.'), tries digits '1'–'9', places a valid one, and recurses. If recursion fails, it backtracks by resetting the cell to '.'
isValid — checks that placing c at (row, col) doesn't violate any of the three Sudoku rules:
Same column check
Same row check
Same 3×3 box check — the index formula 3*(row/3) + i/3 and 3*(col/3) + i%3 maps i (0–8) to all 9 cells in the box */