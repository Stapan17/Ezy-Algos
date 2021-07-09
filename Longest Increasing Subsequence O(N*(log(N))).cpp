// Longest Increasing Subsequence
// Time Complexity O(N*(log(N)))

#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> a)
{
    int n = a.size();
    vector<int> lis;

    lis.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (lis.back() < a[i])
        {
            lis.push_back(a[i]);
        }
        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[idx] = a[i];
        }
    }

    return (int)lis.size();
}

int main()
{
    vector<int> a = {1, 2, 3, 2, 3, 4, 6};

    int lis = LIS(a);

    cout << "Length of LIS : " << lis << "\n";
    return 0;
}