#include <bits/stdc++.h>
using namespace std;

// Memoization

bool f(int i, int k, vector<int> &arr, vector<vector<bool>> &dp)
{
    if (k == 0)
        return true;
    if (i == 0)
    {
        return k == arr[i];
    }
    if (dp[i][k] != -1)
        return dp[i][k];
    bool t = false;
    if (k >= arr[i])
        t = f(i - 1, k - arr[i], arr, dp);
    bool nt = f(i - 1, k, arr, dp);
    return dp[i][k] = t || nt;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

// Tabulation

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool t = false;
            if (j >= arr[i])
                t = dp[i - 1][j - arr[i]];
            bool nt = dp[i - 1][j];
            dp[i][j] = t || nt;
        }
    }
    return dp[n - 1][k];
}

// Space optimization

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false), cur(k + 1, false);

    prev[0] = true;
    cur[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool t = false;
            if (j >= arr[i])
                t = prev[j - arr[i]];
            bool nt = prev[j];
            cur[j] = t || nt;
        }
        prev = cur;
    }
    return prev[k];
}