// Find a place that's safe, to place the new 'Q' in the next column
bool isSafe(int row, int col, vector<string>& board, int n){
    int dupRow = row;
    int dupCol = col;

    // Upper Diagonal
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q')  
            return false;
        row--;
        col--;
    }

    row = dupRow;
    col = dupCol;

    // Row
    while(col >= 0){
        if(board[row][col] == 'Q')  
            return false;
        col--;
    }

    row = dupRow;
    col = dupCol;

    // Lower Diagonal
    while(col >= 0 && row < n){
        if(board[row][col] == 'Q')  
            return false;
        row++;
        col--;
    }

    return true;
}
void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
    if(col == n){
        ans.push_back(board);
        return ;
    }

    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            // Putting the queen at this position at this place, then calling recursion for it
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);

            // This is the backtracking step, we mark that place as empty again
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n, '.');

    for(int i = 0; i < n; i++)
        board[i] = s;
    
    solve(0, board, ans, n);

    return ans;
}