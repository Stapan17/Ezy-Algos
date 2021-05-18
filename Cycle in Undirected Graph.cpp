#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 100002;
vector<int> g[MAXN], visited(MAXN, 0), parent(MAXN, -1);
int cycle_start = -1, cycle_end = -1;

bool dfs(int v, int par)
{
    visited[v] = true;
    for (int u : g[v])
    {
        if (u == par)
            continue;
        if (visited[u])
        {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void Detect_cycle()
{

    for (int v = 0; v < n; v++)
        if (!visited[v] && dfs(v, parent[v]))
            break;

    if (cycle_start == -1)
        cout << "Graph is Acyclic\n";

    else
    {
        vector<int> cycle;

        for (int i = cycle_start; i != cycle_end; i = parent[i])
            cycle.push_back(i);

        cycle.push_back(cycle_end);
        cycle.push_back(cycle_start);

        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found with size : ";
        cout << cycle.size() << "\n";

        for (int i : cycle)
            cout << i << " ";
        cout << "\n";
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    Detect_cycle();

    return 0;
}
