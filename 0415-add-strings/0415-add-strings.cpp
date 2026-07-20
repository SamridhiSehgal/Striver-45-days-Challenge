class Solution {
public:
    string addStrings(string num1, string num2) {

        string ans = "";

        solve(num1, num1.size() - 1,
              num2, num2.size() - 1,
              0, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }

    void solve(string &num1, int i,
               string &num2, int j,
               int carry, string &ans) {

        if (i < 0 && j < 0) {
            if (carry)
                ans.push_back(carry + '0');
            return;
        }

        int n1 = (i >= 0) ? num1[i] - '0' : 0;
        int n2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = n1 + n2 + carry;

        ans.push_back((sum % 10) + '0');

        solve(num1, i - 1,
              num2, j - 1,
              sum / 10, ans);
    }
};