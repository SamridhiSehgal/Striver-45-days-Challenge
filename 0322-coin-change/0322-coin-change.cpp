class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0){
            return 0;
        }

      vector<vector<int>> dp(n+1,
        vector<int>(amount+1,1e9));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        } 
        for(int i=1;i<=n;i++){
            for(int amt=1;amt<=amount;amt++){
                int nottake=dp[i-1][amt];
                 int take = 1e9; 
                if(amt>=coins[i-1]){
                        take=1+dp[i][amt-coins[i-1]];
                }
                dp[i][amt]=min(take,nottake);
            }
        
        }
         if(dp[n][amount] == 1e9)
            return -1;

        return dp[n][amount];
    }
};