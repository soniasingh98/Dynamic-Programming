
#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, wt, val, W, dp);
    }
    int f(int i, int wt[], int val[], int W, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (W >= wt[i])
                return val[i];
            return 0;
        }
        if (dp[i][W] != -1)
            return dp[i][W];
        int t = -1e9;
        if (wt[i] <= W)
            t = val[i] + f(i - 1, wt, val, W - wt[i], dp);
        int nt = f(i - 1, wt, val, W, dp);
        return dp[i][W] = max(nt, t);
    }
};

// Tabulation

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int w = 0; w <= W; w++)
    {
        if (w >= wt[0])
            dp[0][w] = val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int t = -1e9;
            if (wt[i] <= j)
                t = val[i] + dp[i - 1][j - wt[i]];
            int nt = dp[i - 1][j];
            dp[i][j] = max(t, nt);
        }
    }
    return dp[n - 1][W];
}

// Space optimization

int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);
    for (int w = 0; w <= W; w++)
    {
        if (w >= wt[0])
            prev[w] = val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int t = -1e9;
            if (wt[i] <= j)
                t = val[i] + prev[j - wt[i]];
            int nt = prev[j];
            curr[j] = max(t, nt);
        }
        prev = curr;
    }
    return prev[W];
}
