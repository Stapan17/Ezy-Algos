#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 100005;
vector<int> g[MAXN], inDegree(MAXN, 0), ans;

void Kahn()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            int vertex = g[i][j];
            inDegree[vertex]++;
        }
    }

    queue<int> q;

    int cnt = 0;

    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {

        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (int i = 0; i < g[u].size(); i++)
        {
            int vertex = g[u][i];
            inDegree[vertex]--;

            if (inDegree[vertex] == 0)
                q.push(vertex);
        }
        cnt++;
    }

    if (cnt != n)
        cout << "There exists a cycle in the graph.";

    else
        for (int i : ans)
            cout << i + 1 << " ";
    cout << "\n";
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

    Kahn();
}