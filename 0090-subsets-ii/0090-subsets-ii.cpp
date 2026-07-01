class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(nums,0 ,res,temp);
        return res;
    }
    void solve(vector<int>&nums,int ind,vector<vector<int>>&res,vector<int>&temp){
        res.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])
            continue;
            temp.push_back(nums[i]);
            solve(nums,i+1,res,temp);
            temp.pop_back();
        }
    }
};