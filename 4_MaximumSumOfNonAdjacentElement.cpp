#include <bits/stdc++.h>
using namespace std;

int mnas(int i, vector<int> &nums, vector<int> &dp)
{
    if (i == 0)
        return nums[0];
    if (dp[i] != -1)
        return dp[i];
    int t = nums[i];
    if (i > 1)
        t += mnas(i - 2, nums, dp);
    int nt = mnas(i - 1, nums, dp);
    return dp[i] = max(t, nt);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return mnas(nums.size() - 1, nums, dp);
}

// Tabulation

int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int t = nums[i];
        if (i > 1)
            t += dp[i - 2];
        int nt = dp[i - 1];
        dp[i] = max(t, nt);
    }
    return dp[nums.size() - 1];
}

// space optimization

int maximumNonAdjacentSum(vector<int> &nums)
{
    int prev2 = 0, prev1 = nums[0], curi = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int t = nums[i];
        if (i > 1)
            t += prev2;
        int nt = prev1;
        curi = max(t, nt);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
    ;
}
