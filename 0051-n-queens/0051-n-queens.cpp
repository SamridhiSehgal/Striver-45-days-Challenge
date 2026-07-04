class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<vector<char>>board(n, vector<char>(n, '.'));
        solve(n,res,board,0);
        return res;
    }
    void solve(int n,vector<vector<string>>&res,vector<vector<char>>&board,int c){
        if(c==n){
            vector<string>temp;
            for(int i=0;i<n;i++){
                string row(board[i].begin(),board[i].end());
                temp.push_back(row);
            }
            res.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(i,c,board,n)){
                board[i][c]='Q';
                solve(n,res,board,c+1);
                board[i][c]='.';
            }
        }
    }
    bool issafe(int r,int c,vector<vector<char>>&board,int n){
        for(int j=0;j<c;j++){
            if(board[r][j]=='Q'){
                return false;
            }}
            for(int i=r,j=c;i>=0&&j>=0;i--,j--){
                if(board[i][j]=='Q')
                {
                    return false;
                }
            }
            for(int i=r,j=c;i<n&&j>=0;i++,j--){
                  if(board[i][j]=='Q')
                {
                    return false;
                } 
            }
        return true;
    }
};