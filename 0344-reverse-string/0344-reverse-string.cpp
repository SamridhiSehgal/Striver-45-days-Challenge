class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        rev(s,i,j);
    }
    void rev(vector<char>&s,int i,int j){
        if(i>=j){
            return;
        }
        swap(s[i],s[j]);
        rev(s,i+1,j-1);
    }
};