class Solution {
public:

bool isPossible(vector<vector<char>>& board, int row, int col, char val){
    // firstly let's check for the row and column
    for(int i = 0; i<9; i++){
        if(board[i][col] == val || board[row][i] == val) 
            return false;
    }
    // let's check for the 3 x 3 grid
    int r_grid = (row / 3) * 3;
    int c_grid = (col / 3) * 3;
    for(int i = r_grid; i< r_grid + 3; i++){
        for(int j = c_grid; j < c_grid+3; j++){
            if(board[i][j] == val) return false;
        }
    }
    return true;
}

bool helper(vector<vector<char>>&board,int row, int col){
    // we will firstly fill each col then proceed to next row
    if(row == 9) return true;// it means we soduku has been filled
    
    // let's move to next row
    if(col == 9) return helper(board, row+1,0);
    
    // if the board is already filled proceed to next col
    if(board[row][col] != '.') return helper(board,row,col+1);
    
    for(char val = '1'; val <= '9'; val++){
        if(isPossible(board,row,col,val)){
            board[row][col] = val;
            
            // now let's check other empty box and try filling the value for the other possibilities
            if(helper(board,row,col+1)) return true;
            
            // if after placing the value at row,col we were not able to place another value at next vacant box then we'll simply backtrack
            board[row][col] = '.';
        }
        
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    helper(board,0,0);
}
};