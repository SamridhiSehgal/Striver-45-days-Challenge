class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        int st = 0;
        int end = 0;
        int i = 0;
        int n = s.size();

        while(i < n) {

            while(i < n && s[i] == ' ')
                i++;

            if(i == n)
                break;

            st = end;

            while(i < n && s[i] != ' ')
                s[end++] = s[i++];

            reverse(s.begin() + st, s.begin() + end);

            while(i < n && s[i] == ' ')
                i++;

            if(i < n)
                s[end++] = ' ';
        }

        s.resize(end);

        return s;
    }
};