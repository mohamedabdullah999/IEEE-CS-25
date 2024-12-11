#include <bits/stdc++.h>

using namespace std;

struct State {
    int x, y, time;
};

int n, m;
vector<string> grid;
vector<vector<int>> monsterTime, playerTime;
vector<vector<pair<int, int>>> parent;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string moves = "UDLR";

void bfsMonsters(queue<State> &q) {
    while (!q.empty()) {
        auto [x, y, time] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '.' && monsterTime[nx][ny] > time + 1) {
                monsterTime[nx][ny] = time + 1;
                q.push({nx, ny, time + 1});
            }
        }
    }
}

bool bfsPlayer(int startX, int startY) {
    queue<State> q;
    q.push({startX, startY, 0});
    playerTime[startX][startY] = 0;

    while (!q.empty()) {
        auto [x, y, time] = q.front();
        q.pop();

        if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
            // Reached boundary
            vector<char> path;
            while (parent[x][y] != make_pair(-1, -1)) {
                auto [px, py] = parent[x][y];
                for (int d = 0; d < 4; ++d) {
                    if (x - px == directions[d].first && y - py == directions[d].second) {
                        path.push_back(moves[d]);
                        break;
                    }
                }
                x = px;
                y = py;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << "\n" << string(path.begin(), path.end()) << endl;
            return true;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + directions[d].first, ny = y + directions[d].second;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '.' && playerTime[nx][ny] > time + 1 && monsterTime[nx][ny] > time + 1) {
                playerTime[nx][ny] = time + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny, time + 1});
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    monsterTime.assign(n, vector<int>(m, 1e9));
    playerTime.assign(n, vector<int>(m, 1e9));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<State> monsterQueue;
    int startX, startY;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                monsterQueue.push({i, j, 0});
                monsterTime[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }
    bfsMonsters(monsterQueue);
    if (!bfsPlayer(startX, startY)) {
        cout << "NO" << endl;
    }
    return 0;
}