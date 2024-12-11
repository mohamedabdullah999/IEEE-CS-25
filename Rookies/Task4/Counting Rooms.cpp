#include <bits/stdc++.h>
#define ios_b                         \
ios_base::sync_with_stdio(false);
#define nl '\n'

using namespace std;

int k = 0;
int n = 0, m = 0;
vector<vector<int>> a(1000);
map<int, int> maps;

int parent(int x)
{
    int cur = x;
    while (maps.count(cur) != 0)
    {
        cur = maps[cur];
    }
    return cur;
}

void load(int x, int y, char b)
{
    if (b == '#')
    {
        a[x][y] = 0;
        return;
    }

    int up = x > 0 ? a[x - 1][y] : 0;
    int left = y > 0 ? a[x][y - 1] : 0;

    int p_up = parent(up);
    int p_left = parent(left);

    if (up == 0 && left == 0)
    {
        a[x][y] = ++k;
    }
    else if (up == 0 || left == 0)
        if (up != 0)
            a[x][y] = maps.count(up) == 0 ? up : maps[up];
        else
            a[x][y] = maps.count(up) == 0 ? left : maps[left];
        else if (up != 0 && left != 0 && up == left)
            a[x][y] = maps.count(up) == 0 ? up : maps[up];
        else if (up != 0 && left != 0 && up != left)
        {
            int t = min(p_up, p_left);
            a[x][y] = t;

            if (p_up != t && maps.count(p_up) == 0 || maps.count(p_up) == 1 && maps[p_up] > t)
                maps[p_up] = t;
            if (p_left != t && maps.count(p_left) == 0 || maps.count(p_left) == 1 && maps[p_left] > t)
                maps[p_left] = t;
        }
}

void solve()
{
    char b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        a[i] = vector<int>(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> b;
            load(i, j, b);
        }
    }

    cout << k - maps.size() << nl;
}

int main()
{
    ios_b;
    solve();
    return 0;
}
