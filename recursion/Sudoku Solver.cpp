bool isValid(vector<vector<char>>& board, int row, int col, char c){
    for(int i = 0; i < 9; i++){
        // Checking for column
        if(board[i][col] == c)
            return false;
        
        // Checking for row
        if(board[row][i] == c)
            return false;
        
        // Checking 3*3 matrix
        if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == c)
            return false;
    }

    return true;
}

bool solve(vector<vector<char>>& board){
    // Traversing the whole matrix
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            // If the cell is empty
            if(board[i][j] == '.'){
                // Trying for all the possible answers, via brute-force
                for(char c = '1'; c <= '9'; c++){
                    // Checking whether it is valid 'c' value or not
                    if(isValid(board, i, j, c)){
                        board[i][j] = c;

                        // If we get the answer than we simply return
                        if(solve(board))
                            return true;
                        // Else we backtrack, and undo the changes made
                        else
                            board[i][j] = '.';
                    }
                }   
                return false;
            }
        }
    }

    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}