// MO's Algorithm
#include <bits/stdc++.h>
using namespace std;

int block_size;

struct Query
{
    int L, R;
};

// Sorting Queries
bool Compare(Query x, Query y)
{
    if (x.L / block_size != y.L / block_size)
        return x.L / block_size < y.L / block_size;

    return x.R < y.R;
}

// Answering Quries
void QueryAns(int arr[], int n, Query q[], int m)
{
    block_size = sqrt(n);

    sort(q, q + m, Compare);

    int curL = 0, curR = 0, curSum = 0;

    int l0 = q[0].L, r0 = q[0].R;

    curL = l0;
    curR = r0;
    while (l0 != r0 + 1)
    {
        curSum += arr[l0];
        l0++;
    }

    cout << curSum << "\n";

    for (int i = 1; i < m; i++)
    {
        int L = q[i].L, R = q[i].R;

        while (curL < L)
        {
            curSum -= arr[curL];
            curL++;
        }

        while (curL > L)
        {
            curL--;
            curSum += arr[curL];
        }

        while (curR <= R)
        {
            curR++;
            curSum += arr[curR];
        }

        while (curR > R)
        {
            curSum -= arr[curR];
            curR--;
        }

        cout << curSum << "\n";
    }
}

int main()
{
    // int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    // int n = sizeof(a) / sizeof(a[0]);
    // Query q[] = {{2, 4}, {3, 3}, {4, 6}};
    // int m = sizeof(q) / sizeof(q[0]);
    // QueryAns(a, n, q, m);

    return 0;
}