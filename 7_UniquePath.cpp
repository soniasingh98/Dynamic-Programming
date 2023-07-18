#include <bits/stdc++.h>
using namespace std;

// Memization

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp);
    }
    int f(int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == 0 && j == 0)
            return 1;
        int up = f(i - 1, j, dp);
        int left = f(i, j - 1, dp);
        return dp[i][j] = up + left;
    }
};

// Tabulation

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0;
                    if (i >= 1)
                        up = dp[i - 1][j];
                    int left = 0;
                    if (j >= 1)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Space optimization

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0), curr(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    curr[j] = 1;
                else
                {
                    int up = 0;
                    if (i >= 1)
                        up = prev[j];
                    int left = 0;
                    if (j >= 1)
                        left = curr[j - 1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return curr[n - 1];
    }
};