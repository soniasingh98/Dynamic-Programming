#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int ts = 0;
        for (auto it : nums)
        {
            ts += it;
        }
        if (ts % 2)
            return false;
        vector<vector<int>> dp(nums.size(), vector<int>(ts / 2 + 1, -1));
        return f(nums.size() - 1, nums, ts / 2, dp);
    }
    bool f(int i, vector<int> &nums, int tar, vector<vector<int>> &dp)
    {
        if (tar == 0)
            return true;
        if (i == 0)
            return nums[i] == tar;
        if (dp[i][tar] != -1)
            return dp[i][tar];
        bool t = false;
        if (tar >= nums[i])
            t = f(i - 1, nums, tar - nums[i], dp);
        bool nt = f(i - 1, nums, tar, dp);
        return dp[i][tar] = t || nt;
    }
};

// Tabulation

bool canPartition(vector<int> &nums)
{
    int ts = 0;
    for (auto it : nums)
    {
        ts += it;
    }
    if (nums.size() == 1 || ts % 2)
        return false;
    int n = nums.size(), k = ts / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (nums[0] <= k)
        dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool t = false;
            if (j >= nums[i])
                t = dp[i - 1][j - nums[i]];
            bool nt = dp[i - 1][j];
            dp[i][j] = t || nt;
        }
    }
    return dp[n - 1][k];
}