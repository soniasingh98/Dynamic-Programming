#include <bits/stdc++.h>
using namespace std;

// memoization

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
    int f(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (cap == 0 || i == prices.size())
            return 0;
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        if (buy)
        {
            return dp[i][buy][cap] = max(-prices[i] + f(i + 1, 0, cap, prices, dp), f(i + 1, 1, cap, prices, dp));
        }
        return dp[i][buy][cap] = max(prices[i] + f(i + 1, 1, cap - 1, prices, dp), f(i + 1, 0, cap, prices, dp));
    }
};

// Tabulation

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                {
                    dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
                }
                else
                    dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
            }
        }
    }
    return dp[0][1][2];
}

// Space optimization

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                {
                    cur[buy][cap] = max(-prices[i] + prev[0][cap], prev[1][cap]);
                }
                else
                    cur[buy][cap] = max(prices[i] + prev[1][cap - 1], prev[0][cap]);
            }
        }
        prev = cur;
    }
    return prev[1][2];
}