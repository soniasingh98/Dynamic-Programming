#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxarea(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> s;
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && (i == n || arr[s.top()] >= arr[i]))
            {
                int height = arr[s.top()];
                s.pop();
                int width;
                if (s.empty())
                    width = i;
                else
                    width = i - s.top() - 1;
                ans = max(ans, height * width);
            }
            s.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> col(m, 0);
        int maxans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    col[j]++;
                }
                else
                    col[j] = 0;
            }
            int ans = maxarea(col);
            maxans = max(maxans, ans);
        }
        return maxans;
    }
};