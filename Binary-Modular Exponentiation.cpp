#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int BinaryExpoRecursion(int x, int n)
{
    if (n == 0)
        return 1;

    else if (n % 2 == 0)
        return BinaryExpoRecursion(x * x, n / 2);

    else
        return x * BinaryExpoRecursion(x * x, n / 2);
}

int BinaryExpoIterative(int x, int n)
{
    int ans = 1;

    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;

        x = x * x;
        n /= 2;
    }

    return ans;
}

int ModularExpoRecursion(int x, int n, int m)
{
    if (n == 0)
        return 1;

    else if (n % 2 == 0)
        return ModularExpoRecursion(((x % m) * (x % m)) % m, n / 2, m) % m;

    else
        return ((x % m) * ModularExpoRecursion(((x % m) * (x % m)) % m, n / 2, m)) % m;
}

int ModularExpoIterative(int x, int n, int m)
{
    int ans = 1;

    while (n)
    {
        if (n % 2 == 1)
            ans = ((ans % m) * (x % m)) % m;

        x = ((x % m) * (x % m)) % m;
        n /= 2;
    }

    return ans;
}

int main()
{

    int x = 4, n = 2;
    // int x = 4, n = 5;
    // int x = 3, n = 2;
    // int x = 3, n = 5;

    cout << BinaryExpoRecursion(x, n) << "\n";
    cout << BinaryExpoIterative(x, n) << "\n";

    cout << ModularExpoRecursion(x, n, mod) << "\n";
    cout << ModularExpoIterative(x, n, mod) << "\n";

    return 0;
}