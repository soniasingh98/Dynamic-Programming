#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return lcs(t, s, n - 1, n - 1, dp);
    }
    int lcs(string &t, string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (t[i] == s[j])
            return dp[i][j] = 1 + lcs(t, s, i - 1, j - 1, dp);
        return dp[i][j] = max(lcs(t, s, i - 1, j, dp), lcs(t, s, i, j - 1, dp));
    }
};

// Tabulation

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    string t = s;
    reverse(s.begin(), s.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (t[i - 1] == s[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

// Space optimization

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    string t = s;
    reverse(s.begin(), s.end());
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (t[i - 1] == s[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[n];
}
