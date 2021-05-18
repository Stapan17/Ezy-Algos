#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 100002;
vector<int> g[MAXN], color(MAXN, 0), parent(MAXN, -1);
int cycle_start = -1, cycle_end = -1;

bool dfs(int v)
{
    color[v] = 1;

    for (int u : g[v])
    {
        if (color[u] == 0)
        {
            parent[u] = v;

            if (dfs(u))
                return true;
        }
        else if (color[u] == 1)
        {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void Detect_cycle()
{

    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0 && dfs(i))
            break;
    }

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
            cout << i + 1 << " ";
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
    }

    Detect_cycle();

    return 0;
}
