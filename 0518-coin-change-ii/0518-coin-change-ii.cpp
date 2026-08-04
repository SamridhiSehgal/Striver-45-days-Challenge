class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,dp,0);
        
    }
    int solve(int amount,vector<int>&coins,vector<vector<int
    >>&dp,int i){
        int n=coins.size();
        if(i==n){
            return 0;
        }
        if(amount==0){
            return 1;
        }
          if(dp[i][amount] != -1)
            return dp[i][amount];
        int nottake=solve(amount,coins,dp,i+1);
        int take=0;
        if(amount>=coins[i]){
            take=solve(amount-coins[i],coins,dp,i);

        }
        return dp[i][amount]= take+nottake;
    }
};