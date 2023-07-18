#include <bits/stdc++.h>
using namespace std;

// memoization

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        int s = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(s + 1, vector<int>(s + 1, -1));
        return f(1, s, cuts, dp);
    }
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int steps = INT_MAX;
        for (int ind = i; ind <= j; ind++)
        {
            steps = min(steps, cuts[j + 1] - cuts[i - 1] + f(i, ind - 1, cuts, dp) + f(ind + 1, j, cuts, dp));
        }
        return dp[i][j] = steps;
    }
};

// Tabulation

int minCost(int n, vector<int> &cuts)
{
    int s = cuts.size();
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(s + 2, vector<int>(s + 2, 0));
    for (int i = s; i >= 1; i--)
    {
        for (int j = i; j <= s; j++)
        {
            dp[i][j] = INT_MAX;
            for (int ind = i; ind <= j; ind++)
            {
                dp[i][j] = min(dp[i][j], cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j]);
            }
        }
    }
    return dp[1][s];
}