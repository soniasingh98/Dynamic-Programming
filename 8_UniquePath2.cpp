#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return uniquePath2(n - 1, m - 1, obstacleGrid, dp);
    }
    int uniquePath2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (grid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = uniquePath2(i - 1, j, grid, dp);
        int left = uniquePath2(i, j - 1, grid, dp);
        return dp[i][j] = up + left;
    }
};

// Tabulation

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                int left = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n - 1][m - 1];
}

// Space optimization

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<int> prev(m), curr(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j] == 1)
                curr[j] = 0;
            else if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = 0;
                if (i > 0)
                    up = prev[j];
                int left = 0;
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}