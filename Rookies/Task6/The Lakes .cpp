#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dx[4] = {-1, 1, 0, 0};  // Movement in 4 directions
const int dy[4] = {0, 0, -1, 1};
const char dir[4] = {'U', 'D', 'L', 'R'};  // Direction representation

struct Cell {
    int x, y, time;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vector<vector<int>> monster_time(n, vector<int>(m, INF));  // Time when monster reaches each cell
    vector<vector<int>> player_time(n, vector<int>(m, INF));   // Time when player reaches each cell
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<Cell> q;
    pair<int, int> start;

    // Read input and locate monsters & start position
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j, 0});
                monster_time[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    // BFS for monsters (Spread their times first)
    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && monster_time[nx][ny] == INF) {
                monster_time[nx][ny] = cur.time + 1;
                q.push({nx, ny, cur.time + 1});
            }
        }
    }

    // BFS for player
    q.push({start.first, start.second, 0});
    player_time[start.first][start.second] = 0;

    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();

        // If we reach the boundary, reconstruct path
        if (cur.x == 0 || cur.x == n - 1 || cur.y == 0 || cur.y == m - 1) {
            cout << "YES\n";
            vector<char> path;
            int x = cur.x, y = cur.y;

            // Trace back using parent
            while (parent[x][y] != make_pair(-1, -1)) {
                int px = parent[x][y].first, py = parent[x][y].second;
                for (int d = 0; d < 4; d++) {
                    if (x == px + dx[d] && y == py + dy[d]) {
                        path.push_back(dir[d]);
                        break;
                    }
                }
                tie(x, y) = parent[x][y];
            }

            reverse(path.begin(), path.end());
            cout << path.size() << "\n";
            for (char c : path) cout << c;
            cout << "\n";
            return;
        }

        // Explore next moves
        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && player_time[nx][ny] == INF) {
                if (cur.time + 1 < monster_time[nx][ny]) {  // Ensure player reaches before monster
                    player_time[nx][ny] = cur.time + 1;
                    parent[nx][ny] = {cur.x, cur.y};
                    q.push({nx, ny, cur.time + 1});
                }
            }
        }
    }

    cout << "NO\n";  // No escape found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}