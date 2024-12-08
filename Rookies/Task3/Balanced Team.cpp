#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n , x; cin >> n;
    vector <int> v;
    for(int i = 0 ; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }                                                  // 1 2 10 12 15 17
    sort(v.begin() , v.end());
    int slow = 0 , cntr = 0;
    for(int fast = 0 ; fast < n;  fast++) {
        while(v[fast] - v[slow] > 5) {
            slow++;
        }
        cntr = max(cntr , fast - slow + 1);
    }


    cout << cntr << endl;

}

int main()
{
    solve();
    return 0;
}