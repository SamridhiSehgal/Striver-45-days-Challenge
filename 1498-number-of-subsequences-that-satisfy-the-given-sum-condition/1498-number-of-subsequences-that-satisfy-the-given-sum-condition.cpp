class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
         const int MOD = 1e9 + 7;
     sort(nums.begin(),nums.end());
     int n=nums.size();
      vector<int> power(n);
        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2LL) % MOD;
        }

     int left=0;
     int ans=0;
     int right=nums.size()-1;
     while(left<=right){
        if(nums[left]+nums[right]<=target){
  ans = (ans + power[right - left]) %MOD;
       left++;
     }else
     right--;}
     return ans;
    }
    /*void solve(vector<int>&nums,int target,int i,int &ans,vector<int>&temp,vector<vector<int>>&res){
        if(i==nums.size()){
            if(!temp.empty()){
                int mini=*min_element(temp.begin(), temp.end());
                int maxi=*max_element(temp.begin(),temp.end());
                if(mini+maxi<=target){
                    ans++;
                    
                }
            }
            res.push_back(temp);
            return;
        }
        solve(nums,target,i+1,ans,temp,res);
        temp.push_back(nums[i])
     solve(nums,target,i+1,ans,temp,res);
        temp.pop_back();
    }*/
};