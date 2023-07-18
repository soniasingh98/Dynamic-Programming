#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return lcs(text1, text2, n - 1, m - 1, dp);
    }
    int lcs(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return 1 + lcs(s, t, i - 1, j - 1, dp);
        return dp[i][j] = max(lcs(s, t, i - 1, j, dp), lcs(s, t, i, j - 1, dp));
    }
};

// Tabulation

int longestCommonSubsequence(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// Space optimization

int longestCommonSubsequence(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}