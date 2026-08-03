class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,dp,n-1);
        
    }
    int solve(vector<int>&nums,vector<int>&dp,int i){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+solve(nums,dp,i-2);
        int nottake=solve(nums,dp,i-1);
       dp[i]=max(take,nottake);
       return dp[i];
    }
};