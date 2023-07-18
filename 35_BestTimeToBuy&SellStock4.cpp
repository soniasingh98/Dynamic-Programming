#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, k, prices, dp);
    }
    int f(int i, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size() || k == 0)
            return 0;
        if (dp[i][buy][k] != -1)
            return dp[i][buy][k];
        if (buy)
        {
            return dp[i][buy][k] = max(-prices[i] + f(i + 1, 0, k, prices, dp), f(i + 1, 1, k, prices, dp));
        }
        return dp[i][buy][k] = max(prices[i] + f(i + 1, 1, k - 1, prices, dp), f(i + 1, 0, k, prices, dp));
    }
};

// Tabulation

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int t = 1; t <= k; t++)
            {
                if (buy)
                    dp[i][buy][t] = max(-prices[i] + dp[i + 1][0][t], dp[i + 1][1][t]);
                else
                    dp[i][buy][t] = max(prices[i] + dp[i + 1][1][t - 1], dp[i + 1][0][t]);
            }
        }
    }
    return dp[0][1][k];
}

// Space Optimization

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int t = 1; t <= k; t++)
            {
                if (buy)
                    curr[buy][t] = max(-prices[i] + prev[0][t], prev[1][t]);
                else
                    curr[buy][t] = max(prices[i] + prev[1][t - 1], prev[0][t]);
            }
        }
        prev = curr;
    }
    return prev[1][k];
}