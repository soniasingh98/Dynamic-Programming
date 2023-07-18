#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m - 1, n - 1, m, grid, dp);
    }
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
            return -1e8;
        if (i == r)
        {
            if (j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int ans = -1e9;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                int val = 0;
                if (j1 == j2)
                    val = grid[i][j1];
                else
                    val = grid[i][j1] + grid[i][j2];
                val += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
                ans = max(ans, val);
            }
        }
        return dp[i][j1][j2] = ans;
    }
};

// Tabulation

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {

                int ans = -1e9;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {

                        int val = 0;
                        if (j1 == j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            val += -1e8;
                        ans = max(ans, val);
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    return dp[0][0][m - 1];
}

// Space Optimization

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> prev(m, vector<int>(m, -1)), curr(m, vector<int>(m, -1));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                prev[j1][j2] = grid[n - 1][j1];
            else
                prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {

                int ans = -1e9;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {

                        int val = 0;
                        if (j1 == j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += prev[j1 + dj1][j2 + dj2];
                        else
                            val += -1e8;
                        ans = max(ans, val);
                    }
                }
                curr[j1][j2] = ans;
            }
        }
        prev = curr;
    }
    return prev[0][m - 1];
}
