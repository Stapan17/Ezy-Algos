#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(int n, vector<vector<int>> &graph)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] < INT_MAX && graph[k][j] < INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main()
{
    // 0 based indexing is followed.
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;

            else
                graph[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        x--, y--;

        graph[x][y] = min(graph[x][y], z);
        graph[y][x] = min(graph[y][x], z);
    }

    floyd_warshall(n, graph);

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (graph[x][y] == INT_MAX)
            cout << "-1\n";

        else
            cout << graph[x][y] << "\n";
    }

    return 0;
}