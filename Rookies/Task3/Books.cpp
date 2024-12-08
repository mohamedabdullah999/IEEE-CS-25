#include <bits/stdc++.h>

using namespace std;

void solve() {
     int n , t , x;cin >> n >> t;
    vector<int>v;
    for(int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    int maxx = 0 , slow = 0 , sum = 0;
    for(int fast = 0; fast < n; fast++) {
        sum += v[fast];
        if(sum > t) {
            sum -= v[slow];
            slow++;
        }
        maxx = max(maxx , fast - slow + 1);
    }
    cout << maxx << endl;
}

int main()
{
    solve();
    return 0;
}
