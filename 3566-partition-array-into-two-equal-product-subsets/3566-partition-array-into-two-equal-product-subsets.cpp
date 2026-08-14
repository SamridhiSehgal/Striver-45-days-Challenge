class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return solve(nums,target,1,1,0,0,0);
    }
    bool solve(vector<int>&nums,long long target,long long p1,long long p2,int c1,int c2,int ind){
        if(ind==nums.size()){
            if(c1>0&&c2>0&&p1==target&p2==target){
                return true;
            }
            return false;
        }
        //take
        if(p1<=target/nums[ind]){
        if(solve(nums,target,p1*nums[ind],p2,c1+1,c2,ind+1))
        return true;
        }
           if(p2<=target/nums[ind]){
        if(solve(nums,target,p1,p2*nums[ind],c1,c2+1,ind+1))
        return true;}
        return false;


    }
};