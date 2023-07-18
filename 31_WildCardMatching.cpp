#include <bits/stdc++.h>
using namespace std;

// memoization

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(p, s, m - 1, n - 1, dp);
    }
    bool f(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if (j < 0 && i < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;

        if (j < 0 && i >= 0)
        {
            for (int ii = 0; ii <= i; ii++)
            {
                if (s[ii] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || s[i] == '?')
            return dp[i][j] = f(s, p, i - 1, j - 1, dp);
        else if (s[i] == '*')
        {
            return dp[i][j] = f(s, p, i - 1, j, dp) || f(s, p, i, j - 1, dp);
        }
        return dp[i][j] = false;
    }
};