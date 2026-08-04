class Solution {
public:
    int solve(vector<int>& coins, int i, int amount, vector<vector<int>>& dp)
    {
        if(amount == 0)
            return 1;

        if(i == coins.size())
            return 0;

        if(dp[i][amount] != -1)
            return dp[i][amount];

        int take = 0;

        if(coins[i] <= amount)
            take = solve(coins, i, amount - coins[i], dp);

        int notTake = solve(coins, i + 1, amount, dp);

        return dp[i][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        return solve(coins, 0, amount, dp);
    }
};