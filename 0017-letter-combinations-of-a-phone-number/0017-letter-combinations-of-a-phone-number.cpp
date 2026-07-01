class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string combos[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s="";
        vector<string>ans;
        solve (digits,combos,s,ans,0);
        return ans;
    }
    void solve(string digits,string combos[],string s,vector<string>&ans,int ind)
    {
        if(ind==digits.size()){
            ans.push_back(s);
            return;
        }
        int dig=digits[ind]-'0';
        for(int i=0;i<combos[dig].size();i++){
            solve(digits,combos,s+combos[dig][i],ans,ind+1);
        }
    }
};