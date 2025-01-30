#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int cost[105][105], n, vis[105];

void reset() {
    memset(vis, 0, sizeof(vis));
}

int dfs(int u) {
    vis[u] = 1;
    int max_cost = 0;

    for (int nd : adj[u]) {
        if (!vis[nd]) {
            max_cost = max(max_cost, cost[u][nd] + dfs(nd));
        }
    }

    return max_cost;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cost[a][b] = cost[b][a] = c;
    }

    reset();
    cout << dfs(0) << endl;

    return 0;
}
