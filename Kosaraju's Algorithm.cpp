#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 2;

int n, m;
vector<int> g[maxn], g_rev[maxn], visited(maxn, false), top_order, component;

void dfs1(int v)
{
    visited[v] = true;

    for (int u : g[v])
    {
        if (!visited[u])
            dfs1(u);
    }

    top_order.push_back(v);
}

void dfs2(int v)
{
    visited[v] = true;
    component.push_back(v);

    for (int u : g_rev[v])
    {
        if (!visited[u])
            dfs2(u);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g_rev[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    reverse(top_order.begin(), top_order.end());

    visited.assign(maxn, false);

    int scc = 0;

    for (int i = 0; i < top_order.size(); i++)
    {
        if (!visited[i])
        {
            dfs2(i);

            for (int j = 0; j < component.size(); j++)
                cout << component[j] << " ";
            cout << "\n";

            component.clear();
            scc++;
        }
    }

    cout << "Number Of Strongly Connected Component : " << scc << "\n";

    return 0;
}