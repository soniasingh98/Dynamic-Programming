#include <bits/stdc++.h>
using namespace std;

// memoization

int f(int i, int pd, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        int maxi = 0;
        for (int k = 0; k <= 2; k++)
        {
            if (k != pd)
                maxi = max(maxi, points[i][k]);
        }
        return maxi;
    }
    if (dp[i][pd] != -1)
        return dp[i][pd];
    int maxi = 0;
    for (int k = 0; k <= 2; k++)
    {
        if (k != pd)
        {
            int point = points[i][k] + f(i - 1, k, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[i][pd] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, 3, points, dp);
}

// Tabulation

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(max(points[0][1], points[0][0]), points[0][2]);
    for (int i = 1; i < n; i++)
    {
        for (int pd = 0; pd < 4; pd++)
        {
            int maxi = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != pd)
                    maxi = max(maxi, points[i][task] + dp[i - 1][task]);
            }
            dp[i][pd] = maxi;
        }
    }
    return dp[n - 1][3];
}

// space optimization

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4), curr(4);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(max(points[0][1], points[0][0]), points[0][2]);
    for (int i = 1; i < n; i++)
    {
        for (int pd = 0; pd < 4; pd++)
        {
            int maxi = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != pd)
                    maxi = max(maxi, points[i][task] + prev[task]);
            }
            curr[pd] = maxi;
        }
        prev = curr;
    }
    return curr[3];
}
