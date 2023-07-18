#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
    int f(int i, int amt, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (amt % coins[i] == 0)
                return 1;
            else
                return 0;
        }
        if (dp[i][amt] != -1)
            return dp[i][amt];
        int p = 0;
        if (amt >= coins[i])
            p = f(i, amt - coins[i], coins, dp);
        int np = f(i - 1, amt, coins, dp);
        return dp[i][amt] = p + np;
    }
};