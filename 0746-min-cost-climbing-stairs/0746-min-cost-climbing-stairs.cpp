class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int  n=cost.size();
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
      return min(dp[0],dp[1]);    
    }
    /*int solve(vector<int>&cost,int i,vector<int>&dp){int ans=0;
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){return dp[i];}
        int one=cost[i]+solve(cost,i+1,dp);
        int two=cost[i]+solve(cost,i+2,dp);
        return dp[i]=min(one,two);
    }*/
};