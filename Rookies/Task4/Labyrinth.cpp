#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char dir[] = {'L', 'R', 'U', 'D'};

bool is_valid(int x, int y, int n, int m, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    pair<int, int> start, end;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (make_pair(x, y) == end) {
            found = true;
            break;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (is_valid(nx, ny, n, m, grid, visited)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    string path;
    pair<int, int> current = end;
    while (current != start) {
        pair<int, int> prev = parent[current.first][current.second];
        for (int d = 0; d < 4; ++d) {
            if (prev.first + dx[d] == current.first && prev.second + dy[d] == current.second) {
                path += dir[d];
                break;
            }
        }
        current = prev;
    }

    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    cout << path << endl;

    return 0;
}
