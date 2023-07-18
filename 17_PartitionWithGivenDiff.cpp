#include <bits/stdc++.h>
using namespace std;

int modu = 1e9 + 7;
int f(int i, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (k == 0 && arr[i] == 0)
            return 2;
        if (k == 0 || arr[i] == k)
            return 1;
        return 0;
    }
    if (dp[i][k] != -1)
        return dp[i][k];
    int p = 0;
    if (k >= arr[i])
        p = f(i - 1, arr, k - arr[i], dp);
    int np = f(i - 1, arr, k, dp);
    return dp[i][k] = (p + np) % modu;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    if (arr.size() == 0)
        return 0;
    int ts = 0;
    for (auto it : arr)
        ts += it;
    if (ts - d < 0)
        return 0;
    if ((ts - d) % 2)
        return 0;
    int k = (ts - d) / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, arr, k, dp);
}

// Tabulation

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    if (arr.size() == 0)
        return 0;
    int ts = 0;
    for (auto it : arr)
        ts += it;
    if (ts - d < 0)
        return 0;
    if ((ts - d) % 2)
        return 0;
    int k = (ts - d) / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    if (arr[0] <= k)
        dp[0][arr[0]] = 1;
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int p = 0;
            if (j >= arr[i])
                p = dp[i - 1][j - arr[i]];
            int np = dp[i - 1][j];
            dp[i][j] = (p + np) % modu;
        }
    }
    return dp[n - 1][k];
}

// space optimization

#include <bits/stdc++.h>
int modu = 1e9 + 7;

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    if (arr.size() == 0)
        return 0;
    int ts = 0;
    for (auto it : arr)
        ts += it;
    if (ts - d < 0)
        return 0;
    if ((ts - d) % 2)
        return 0;
    int k = (ts - d) / 2;
    vector<int> prev(k + 1, 0), curr(k + 1);

    if (arr[0] <= k)
        prev[arr[0]] = 1;
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int p = 0;
            if (j >= arr[i])
                p = prev[j - arr[i]];
            int np = prev[j];
            curr[j] = (p + np) % modu;
        }
        prev = curr;
    }
    return prev[k];
}
