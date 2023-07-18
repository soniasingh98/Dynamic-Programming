#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
    }

    int k = totalsum;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nt = dp[i - 1][target];
            bool t = false;
            if (arr[i] <= target)
            {
                t = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = nt || t;
        }
    }

    int mn = 1e9;
    for (int i = 0; i <= totalsum / 2; i++)
    {
        if (dp[n - 1][i] == true)
        {
            mn = min(mn, abs((totalsum - i) - i));
        }
    }
    return mn;
}
