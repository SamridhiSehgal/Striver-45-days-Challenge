class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(k,n,1,res,temp);
        return res;
        
    }
    void solve(int k,int n,int ind,vector<vector<int>>&res,vector<int>&temp)
    {
        if(n==0&&temp.size()==k){
            res.push_back(temp);
            return ;
        }
         if (temp.size() >= k)
            return;
        for(int i=ind;i<=9;i++){
            if(i<=n){
                temp.push_back(i);
                solve(k,n-i,i+1,res,temp);
                temp.pop_back();
            }
            else
            break;
        }
    }
};