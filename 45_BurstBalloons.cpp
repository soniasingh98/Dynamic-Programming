#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return f(1, n, nums, dp);
    }
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MIN;
        for (int ind = i; ind <= j; ind++)
        {
            ans = max(ans, nums[j + 1] * nums[ind] * nums[i - 1] + f(i, ind - 1, nums, dp) + f(ind + 1, j, nums, dp));
        }
        return dp[i][j] = ans;
    }
};

// Tabulation

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                dp[i][j] = max(dp[i][j], nums[j + 1] * nums[ind] * nums[i - 1] + dp[i][ind - 1] + dp[ind + 1][j]);
            }
        }
    }
    return dp[1][n];
}