#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<vector<int>> adj(n + 1); 
    
    for (int i = 1; i <= n; i++) {
        int u = i;
        int v = p[i - 1];
        if (u != v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    vector<bool> visited(n + 1, false);
    
    int tree_count = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            tree_count++;
        }
    }
    
 
    cout << tree_count << endl;
    
    return 0;
}
