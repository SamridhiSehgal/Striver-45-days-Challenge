class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,-1);
        if(n==1){
            return nums[0];
        }
        vector<int>dp2(n,-1);
        int first=solve(nums,0,n-2,dp1);
        int sec=solve(nums,1,n-1,dp2);
        return max(first,sec);

        
    }
    int solve(vector<int>&nums,int i,int n,vector<int>&dp){
    
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int take=nums[i]+solve(nums,i+2,n,dp);
        int nottake=solve(nums,i+1,n,dp);
        dp[i]=max(take,nottake);
        return dp[i];
    }

};