#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return mt(0, 0, triangle, dp);
    }
    int mt(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i == triangle.size() - 1)
            return triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = triangle[i][j] + mt(i + 1, j, triangle, dp);
        int dig = triangle[i][j] + mt(i + 1, j + 1, triangle, dp);
        return dp[i][j] = min(down, dig);
    }
};

// Tabulation

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = triangle[i].size() - 1; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int dig = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, dig);
        }
    }
    return dp[0][0];
}

// Space optimization

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> prev(n), curr(n);
    for (int j = 0; j < n; j++)
    {
        prev[j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = triangle[i].size() - 1; j >= 0; j--)
        {
            int down = triangle[i][j] + prev[j];
            int dig = triangle[i][j] + prev[j + 1];
            curr[j] = min(down, dig);
        }
        prev = curr;
    }
    return prev[0];
}