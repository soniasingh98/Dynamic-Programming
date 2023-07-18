#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return f(0, k, n, arr, dp);
    }
    int f(int i, int k, int n, vector<int> &arr, vector<int> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int len = 0;
        int maxele = arr[i];
        int ans = INT_MIN;
        for (int j = i; j < min(n, i + k); j++)
        {
            len++;
            maxele = max(maxele, arr[j]);
            ans = max(ans, maxele * len + f(j + 1, k, n, arr, dp));
        }
        return dp[i] = ans;
    }
};

// Tabulation

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int len = 0;
        int maxele = arr[i];
        int ans = INT_MIN;
        for (int j = i; j < min(n, i + k); j++)
        {
            len++;
            maxele = max(maxele, arr[j]);
            ans = max(ans, maxele * len + dp[j + 1]);
        }
        dp[i] = ans;
    }
    return dp[0];
}