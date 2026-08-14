class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string &s, string &p, int s1, int p1) {

        // Both finished
        if (s1 == s.size() && p1 == p.size())
            return true;

        // Pattern finished but string remains
        if (p1 == p.size())
            return false;

        // Already calculated
        if (dp[s1][p1] != -1)
            return dp[s1][p1];

        bool ans = false;

        // x*
        if (p1 + 1 < p.size() && p[p1 + 1] == '*') {

            // 0 occurrences
            if (solve(s, p, s1, p1 + 2))
                ans = true;

            // 1 or more occurrences
            else if (s1 < s.size() &&
                     (s[s1] == p[p1] || p[p1] == '.')) {

                ans = solve(s, p, s1 + 1, p1);
            }
        }

        // Normal character
        else if (s1 < s.size() && s[s1] == p[p1]) {

            ans = solve(s, p, s1 + 1, p1 + 1);
        }

        // .
        else if (s1 < s.size() && p[p1] == '.') {

            ans = solve(s, p, s1 + 1, p1 + 1);
        }

        return dp[s1][p1] = ans;
    }

    bool isMatch(string s, string p) {

        dp.assign(s.size() + 1,
                  vector<int>(p.size() + 1, -1));

        return solve(s, p, 0, 0);
    }
};