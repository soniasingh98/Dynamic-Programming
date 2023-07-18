#include <bits/stdc++.h>
using namespace std;

// Memoization

int f(int i, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return n * price[0];
    }
    if (dp[i][n] != -1)
        return dp[i][n];
    int np = f(i - 1, n, price, dp);
    int p = INT_MIN;
    int ind = i + 1;
    if (ind <= n)
    {
        p = price[i] + f(i, n - ind, price, dp);
    }
    return dp[i][n] = max(p, np);
}
int cutRod(vector<int> &price, int n)
{
    int s = price.size();
    vector<vector<int>> dp(s, vector<int>(n + 1, -1));
    return f(s - 1, n, price, dp);
}

// Tabulation

int cutRod(vector<int> &price, int n)
{

    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int np = dp[i - 1][j];
            int p = INT_MIN;
            int ind = i + 1;
            if (ind <= j)
                p = price[i] + dp[i][j - ind];
            dp[i][j] = max(p, np);
        }
    }
    return dp[n - 1][n];
}

// Space optimization

int cutRod(vector<int> &price, int n)
{

    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int np = prev[j];
            int p = INT_MIN;
            int ind = i + 1;
            if (ind <= j)
                p = price[i] + curr[j - ind];
            curr[j] = max(p, np);
        }
        prev = curr;
    }
    return prev[n];
}
