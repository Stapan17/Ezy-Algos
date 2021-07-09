// Longest Increasing Subsequence
// Time Complexity O(N*N)

#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> a)
{
    int n = a.size();

    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                ans[i] = max(ans[i], ans[j] + 1);
        }
    }

    int mx = 1;

    for (int i = 0; i < n; i++)
        mx = max(mx, ans[i]);

    return mx;
}

int main()
{

    vector<int> a = {1, 2, 3, 2, 3, 4, 6};

    int lis = LIS(a);

    cout << "Length of Longest Increasing Subsequence : " << lis << "\n";

    return 0;
}