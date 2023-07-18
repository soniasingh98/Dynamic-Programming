#include <bits/stdc++.h>
using namespace std;

// 1st Approach

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return f(0, -1, nums, dp);
    }
    int f(int i, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == nums.size())
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int len = f(i + 1, prev, nums, dp);
        if (prev == -1 || nums[prev] < nums[i])
        {
            len = max(len, 1 + f(i + 1, i, nums, dp));
        }
        return dp[i][prev + 1] = len;
    }
};

// 2nd Approach

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size(), maxi = 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }
        maxi = max(dp[i], maxi);
    }
    return maxi;
}

// 3rd Approach

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v;
    v.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (v.back() < nums[i])
            v.push_back(nums[i]);
        else
        {
            int ind = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            v[ind] = nums[i];
        }
    }
    return v.size();
}