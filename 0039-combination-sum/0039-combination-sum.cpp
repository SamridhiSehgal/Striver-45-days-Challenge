class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(candidates,0,target,res,temp);
        return res;

        
    }
    void solve(vector<int>&candidates,int ind,int target,vector<vector<int>>&res,vector<int>&temp)
    {
        if(ind==candidates.size()){
            if(target==0){
                res.push_back(temp);

            }
            return;
        }
        if(candidates[ind]<=target){
                 temp.push_back(candidates[ind]);
            solve(candidates,ind,target-candidates[ind],res,temp);
       temp.pop_back();

        }
        solve(candidates,ind+1,target,res,temp);
    }
};