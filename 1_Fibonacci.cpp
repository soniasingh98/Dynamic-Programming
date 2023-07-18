#include <bits/stdc++.h>
using namespace std;

// Memoization

int fib(int n)
{
    vector<int> dp(n + 1, -1);
    return f(n, dp);
}
int f(int i, vector<int> &dp)
{
    if (i == 0 || i == 1)
        return i;
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = f(i - 1, dp) + f(i - 2, dp);
}

// Tabulation

int fib(int n)
{
    if (n == 0)
        return 0;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space optimization

int fib(int n)
{
    if (n == 0)
        return 0;
    int prev2 = 0, prev1 = 1, curi;
    for (int i = 2; i <= n; i++)
    {
        curi = prev2 + prev1;
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}
