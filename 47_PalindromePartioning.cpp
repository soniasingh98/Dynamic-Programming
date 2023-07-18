#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    bool isPalin(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return f(0, s, n, dp) - 1;
    }
    int f(int i, string &s, int n, vector<int> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int mini = INT_MAX;
        for (int ind = i; ind < n; ind++)
        {
            if (isPalin(i, ind, s))
            {

                mini = min(mini, 1 + f(ind + 1, s, n, dp));
            }
        }
        return dp[i] = mini;
    }
};

// Tabulation

class Solution
{
public:
    bool isPalin(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = INT_MAX;
            for (int ind = i; ind < n; ind++)
            {
                if (isPalin(i, ind, s))
                {
                    dp[i] = min(dp[i], 1 + dp[ind + 1]);
                }
            }
        }
        return dp[0] - 1;
    }
};