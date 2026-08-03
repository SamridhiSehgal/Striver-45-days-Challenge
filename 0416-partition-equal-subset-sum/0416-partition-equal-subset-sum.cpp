class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        
        int target=sum/2;
             vector<vector<int>> dp(nums.size(),
                               vector<int>(target+1,-1));
                               return solve(nums,dp,target,0);
    }
    bool solve(vector<int>&nums,vector<vector<int>>&dp,int target,int i){
        if(i==nums.size()){
            return false;
        }
        if(target==0){
            return true;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool take=false;
        if(nums[i]<=target){
            take=solve(nums,dp,target-nums[i],i+1);
        }
        bool nottake=solve(nums,dp,target,i+1);
        return dp[i][target]= take||nottake;}
};