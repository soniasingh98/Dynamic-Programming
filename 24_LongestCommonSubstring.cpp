#include <bits/stdc++.h>
using namespace std;

// Tabulation

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(dp[i][j], ans);
            }
        }
    }
    return ans;
}

// Space optimization

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                ans = max(curr[j], ans);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}