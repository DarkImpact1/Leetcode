class Solution {
public:
    bool isPlacedValid(vector<vector<char>>&board, int row, int col,char val){
        
        // let's check for the row
        for(int r =0; r<9; r++){
            if(r == row) continue;
            if(board[r][col] == val) return false;
        }

        // let's check for the column
        for(int c = 0; c<9; c++){
            if(c == col) continue;
            if(board[row][c] == val) return false;
        }

        // let's check for 3x3 grid
        int r_grid = (row/3)*3;
        int c_grid = (col/3)*3;
        for(int i = r_grid; i<r_grid+3; i++){
            for(int j = c_grid; j<c_grid+3; j++){
                if(i == row && j==col) continue;
                if(board[i][j] == val) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9;i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    char val = board[i][j];
                    if(!isPlacedValid(board,i,j,val)) return false;
                }
            }
        }
        return true;
    }
};