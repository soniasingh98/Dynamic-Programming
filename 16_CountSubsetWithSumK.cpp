#include <bits/stdc++.h>
using namespace std;

int f(int i, int tar, vector<int> &num, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (num[i] == 0 && tar == 0)
            return 2;
        if (tar == 0 || num[i] == tar)
            return 1;
        return 0;
    }
    if (dp[i][tar] != -1)
        return dp[i][tar];
    int nt = f(i - 1, tar, num, dp);
    int t = 0;
    if (num[i] <= tar)
        t = f(i - 1, tar - num[i], num, dp);
    return dp[i][tar] = nt + t;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    if (num.size() == 0)
        return 0;
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f(n - 1, tar, num, dp);
}