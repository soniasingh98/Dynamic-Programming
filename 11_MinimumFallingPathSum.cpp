#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mn = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            mn = min(mn, minsum(n - 1, k, n, matrix, dp));
        }
        return mn;
    }
    int minsum(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= n)
            return 1e9;
        if (i == 0)
            return matrix[0][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int s = matrix[i][j] + minsum(i - 1, j, n, matrix, dp);
        int ld = matrix[i][j] + minsum(i - 1, j - 1, n, matrix, dp);
        int rd = matrix[i][j] + minsum(i - 1, j + 1, n, matrix, dp);
        return dp[i][j] = min(s, min(ld, rd));
    }
};

// Tabulation

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ld = 1e9, rd = 1e9;

            int up = matrix[i][j] + dp[i - 1][j];

            if (j - 1 >= 0)
                ld = matrix[i][j] + dp[i - 1][j - 1];
            if (j + 1 < m)
                rd = matrix[i][j] + dp[i - 1][j + 1];

            dp[i][j] = min(up, min(ld, rd));
        }
    }

    int mini = dp[n - 1][0];

    for (int j = 1; j < m; j++)
    {
        mini = min(mini, dp[n - 1][j]);
    }
    return mini;
}

// Space optimization

int minFallingPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();

    int m = matrix[0].size();

    vector<int> prev(m, 0), curr(m);

    for (int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ld = 1e9, rd = 1e9;

            int up = matrix[i][j] + prev[j];

            if (j - 1 >= 0)
                ld = matrix[i][j] + prev[j - 1];
            if (j + 1 < m)
                rd = matrix[i][j] + prev[j + 1];

            curr[j] = min(up, min(ld, rd));
        }
        prev = curr;
    }

    int mini = prev[0];

    for (int j = 1; j < m; j++)
    {

        mini = min(mini, prev[j]);
    }
    return mini;
}