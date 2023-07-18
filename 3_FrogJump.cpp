#include <bits/stdc++.h>
using namespace std;

// Memoization

int fj(int i, vector<int> &heights, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int os = fj(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
    int ts = INT_MAX;
    if (i > 1)
        ts = fj(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);
    return dp[i] = min(os, ts);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return fj(n - 1, heights, dp);
}

// tabulation

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int os = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ts = INT_MAX;
        if (i > 1)
            ts = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(os, ts);
    }
    return dp[n - 1];
}

// space optimization

int frogJump(int n, vector<int> &heights)
{
    int prev2 = 0, prev1 = 0, curi;
    for (int i = 1; i < n; i++)
    {
        int os = prev1 + abs(heights[i] - heights[i - 1]);
        int ts = INT_MAX;
        if (i > 1)
            ts = prev2 + abs(heights[i] - heights[i - 2]);
        curi = min(os, ts);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}
