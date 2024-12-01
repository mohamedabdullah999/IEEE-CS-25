//Launch of Collider
#include <bits/stdc++.h>

using namespace std;

vector<int>v;
set <int> st;

void solve(int n , string s) {
    bool flag = 0;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(i == n - 1) break;
        if(s[i] == 'R' && s[i + 1] == 'L') {
            flag = 1;
            ans = min(ans , (v[i + 1] - v[i]) / 2);
        }
    }
    flag? cout << ans << endl: cout << -1 << endl;
}

int main()
{
    int n , x; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    solve(n , s);
    return 0;
}
