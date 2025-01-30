#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAXN = 1e5 + 3;

int m, ans;
bitset<MAXN> hasCat;
vector<vector<int>> adjList;
int maxConsecCats[MAXN] = {0}, currConsecCats[MAXN] = {0};

void dfs(int u, int parent = 0) {
    if (hasCat[u])
        currConsecCats[u] = 1 + (hasCat[parent] ? currConsecCats[parent] : 0);
    else
        currConsecCats[u] = 0;

    maxConsecCats[u] = max(currConsecCats[u], maxConsecCats[parent]);

    bool isLeaf = true;
    for (int v : adjList[u]) {
        if (v != parent) {
            dfs(v, u);
            isLeaf = false;
        }
    }

    if (isLeaf && maxConsecCats[u] <= m)
        ++ans;
}

int main() {
    int n;
    cin >> n >> m;

    adjList.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        int cat;
        cin >> cat;
        hasCat[i] = cat;
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    ans = 0;
    dfs(1);

    cout << ans << endl;
    return 0;
}
