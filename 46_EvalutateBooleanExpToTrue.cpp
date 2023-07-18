

#include <bits/stdc++.h>
using namespace std;

int modu = 1003;
class Solution
{
public:
    int f(int i, int j, bool isTrue, string &A, vector<vector<vector<int>>> &dp)
    {
        if (i == j)
        {
            return (isTrue) ? A[i] == 'T' : A[i] == 'F';
        }
        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        int ways = 0;
        for (int ind = i + 1; ind < j; ind += 2)
        {
            int lt = f(i, ind - 1, true, A, dp);
            int lf = f(i, ind - 1, false, A, dp);
            int rt = f(ind + 1, j, true, A, dp);
            int rf = f(ind + 1, j, false, A, dp);

            if (A[ind] == '|')
            {
                if (isTrue)
                {
                    ways = (ways + (lt * rt) % modu + (lt * rf) % modu + (lf * rt) % modu) % modu;
                }
                else
                    ways = (ways + (lf * rf) % modu) % modu;
            }
            else if (A[ind] == '&')
            {
                if (isTrue)
                {
                    ways = (ways + (lt * rt) % modu) % modu;
                }
                else
                {
                    ways = (ways + (lf * rf) % modu + (lt * rf) % modu + (lf * rt) % modu) % modu;
                }
            }
            else
            {
                if (isTrue)
                {
                    ways = (ways + (lf * rt) % modu + (lt * rf) % modu) % modu;
                }
                else
                {
                    ways = (ways + (lt * rt) % modu + (lf * rf) % modu) % modu;
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }

    int countWays(int N, string S)
    {
        // code here
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(2, -1)));
        return f(0, N - 1, true, S, dp) % modu;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
}
