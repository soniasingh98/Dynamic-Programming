#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return (ans >= 1e8) ? -1 : ans;
    }
    int f(int i, int amt, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (amt == 0)
            return 0;
        if (i == 0)
        {
            if (amt % coins[i] == 0)
                return amt / coins[i];
            return 1e8;
        }
        if (dp[i][amt] != -1)
            return dp[i][amt];
        int np = f(i - 1, amt, coins, dp);
        int p = 1e8;
        if (amt >= coins[i])
            p = 1 + f(i, amt - coins[i], coins, dp);
        return dp[i][amt] = min(np, p);
    }
};

// Tabulation

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int j = 0; j <= amount; j++)
    {
        if (j % coins[0] == 0)
            dp[0][j] = j / coins[0];
        else
            dp[0][j] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int np = dp[i - 1][j];
            int p = INT_MAX;
            if (j >= coins[i])
                p = 1 + dp[i][j - coins[i]];
            dp[i][j] = min(np, p);
        }
    }
    int ans = dp[n - 1][amount];
    return (ans >= 1e9) ? -1 : ans;
}

// Space Optimization

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1), curr(amount + 1);
    for (int j = 0; j <= amount; j++)
    {
        if (j % coins[0] == 0)
            prev[j] = j / coins[0];
        else
            prev[j] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int np = prev[j];
            int p = INT_MAX;
            if (j >= coins[i])
                p = 1 + curr[j - coins[i]];
            curr[j] = min(np, p);
        }
        prev = curr;
    }
    int ans = prev[amount];
    return (ans >= 1e9) ? -1 : ans;
}