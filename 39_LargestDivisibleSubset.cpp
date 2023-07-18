#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 1, index = 0;
        for (int i = 0; i < n; i++)
            hash[i] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                index = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[index]);
        while (hash[index] != index)
        {
            index = hash[index];
            ans.push_back(nums[index]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};