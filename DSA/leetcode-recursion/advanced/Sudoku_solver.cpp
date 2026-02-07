class Solution {
public:
    bool check(vector<vector<char>>&board,int row,int col,char k){
        for(int i=0;i<board.size();i++){
            if(board[i][col]==k)return false;
        }
        for(int j=0;j<board[0].size();j++){
            if(board[row][j]==k)return false;
        }
        int r=row/3*3;
        int c=col/3*3;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(board[i][j]==k) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(check(board,i,j,k)==true){
                            board[i][j]=k;
                            if(solve(board)==true)return true;
                            board[i][j]='.';
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
};