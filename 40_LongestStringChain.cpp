#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isvalid(string &a, string &b)
    {
        if (a.size() != b.size() + 1)
            return false;
        int f = 0, s = 0;
        while (f < a.size())
        {
            if (a[f] == b[s])
            {
                f++;
                s++;
            }
            else
            {
                f++;
            }
        }
        if (f == a.size() && s == b.size())
            return true;
        return false;
    }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), [&](string &a, string &b)
             { return a.size() < b.size(); });
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isvalid(words[i], words[j]) && dp[j] + 1 > dp[i])
                {
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};