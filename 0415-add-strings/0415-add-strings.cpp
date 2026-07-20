class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
       string ans= solve(num1,i,num2,j,carry);
           reverse(ans.begin(),ans.end());
       return ans;

    }
    string solve(string &num1,int i,string &num2,int j,int carry){
        if(i<0&&j<0){
            if(carry!=0){
                return string(1,carry+'0');
            }
            return "";}
            int n1=(i>=0?num1[i]:'0')-'0';
            int n2=(j>=0?num2[j]:'0')-'0';
            int csum=n1+n2+carry;
            int digit=csum%10;
            carry=csum/10;
            string ans="";
            ans.push_back(digit+'0');
            ans+=solve(num1,i-1,num2,j-1,carry);
        
            return ans;
        }
    
};