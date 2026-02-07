#inlude<bits<stdc++.h>
class Solution {
public:
    void solve(int n,vector<int>&arr,vector<int>&dl,vector<int>&du, vector<string>& board, vector<vector<string>>& result,
               int j) {
        if (j == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if ((arr[i]==0)&&(dl[i+j]==0)&&(du[n-1+j-i]==0)){
                board[i][j] = 'Q';
                arr[i]=1;
                dl[i+j]=1;
                du[n-1+j-i]=1;
                solve(n,arr,dl,du, board, result, j + 1);
                board[i][j] = '.';
                arr[i]=0;
                dl[i+j]=0;
                du[n-1+j-i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<int>arr(n,0);
        vector<int>dl(2*n-1,0);
        vector<int>du(2*n-1,0);
        solve(n,arr,dl,du, board, result, 0);
        return result;
    }
};