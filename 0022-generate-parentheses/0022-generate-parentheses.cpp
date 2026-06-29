class Solution {
public:
    vector<string> generateParenthesis(int n) {
    vector<string>res;
    char ch;
    int open=0;
    int close=0;
    solve(n,res,"",open,close);   
    return res; 
    }
   void solve(int n,vector<string>&res,string curr,int open,int close){
        if(curr.length()==2*n){
            res.push_back(curr);
        }
        
        if(open<n){
            solve(n,res,curr+'(',open+1,close);
        }
        if(close<open){
            solve(n,res,curr+')',open,close+1);
        }


    }
};