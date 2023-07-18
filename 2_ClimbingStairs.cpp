#include <bits/stdc++.h>
using namespace std;

// memoization

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return cs(n, dp);
}
int cs(int i, vector<int> &dp)
{
    if (i == 0 || i == 1)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = cs(i - 1, dp) + cs(i - 2, dp);
}

// Tabulation

int climbStairs(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space optimization

int climbStairs(int n)
{
    int prev2 = 1, prev1 = 1, curi;
    for (int i = 2; i <= n; i++)
    {
        curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}