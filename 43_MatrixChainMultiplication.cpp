
#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(1, N - 1, arr, dp);
    }
    int f(int i, int j, int arr[], vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
};

// Tabulation

int matrixMultiplication(int N, int arr[])
{
    // code here
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (i == j)
                continue;
            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends