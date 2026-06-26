class Solution {
public:
    int beautySum(string s) {
        unordered_map<char,int>mp;
        int diff=0;
        for(int i=0;i<s.size();i++){
            mp.clear();
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto it:mp){
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                diff+=maxi-mini;
            }
        }
        return diff;
    }
};