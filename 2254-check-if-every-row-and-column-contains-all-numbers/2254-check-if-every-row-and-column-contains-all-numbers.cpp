class Solution {
public:
    bool isUnique(vector<vector<int>>& matrix,int n, int row, int col,int val){
        // let's check for all the rows
        for(int r=0; r<n; r++){
            if(r== row) continue;
            if(matrix[r][col] == val) return false;
        }
        //let's check for all the cols
        for(int c=0; c<n; c++){
            if(c == col) continue;
            if(matrix[row][c] == val) return false;
        }
        return true;
    }

    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int val = matrix[i][j];
                if(!isUnique(matrix,n,i,j,val)) return false;
            }
        }
        return true;
    }
};