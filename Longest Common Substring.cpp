// Longest Common Substring
// Time Complexity O(N*N)

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int dp[maxn][maxn];

int FindLcsLength(string a, string b)
{
    int n = a.length(), m = b.length();

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = 0;
        }
    }

    int mx = 0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            mx = max(mx, dp[i][j]);

    return mx;
}

int main()
{
    string a = "abcbc";
    string b = "cbcba";

    memset(dp, 0, sizeof(dp));

    int len = FindLcsLength(a, b);

    cout << "Length of Longest Common Substring : " << len << "\n";

    return 0;
}