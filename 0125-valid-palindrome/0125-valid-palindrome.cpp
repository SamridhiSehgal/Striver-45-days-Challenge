class Solution {
public:
    bool isPalindrome(string s) {

        palin(s);

        return is(s, 0, s.size() - 1);
    }

    bool is(string &s, int start, int end) {

        if (start >= end)
            return true;

        if (s[start] != s[end])
            return false;

        return is(s, start + 1, end - 1);
    }

    void palin(string &s) {

       int j=0;
       for(int i=0;i<s.size();i++)
       {
        if(isalnum(s[i]))
        {
            s[j]=tolower(s[i]);
            j++;
        }
       }
          s.resize(j);
      
    }
};