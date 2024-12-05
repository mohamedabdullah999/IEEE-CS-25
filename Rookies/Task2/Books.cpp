#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t , x;
    cin >> n >> t;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    int maxx = 0, sum = 0, low = 0;
    for (int high = 0; high < n; high++) {
        sum += v[high];
        while (sum > t) {
            sum -= v[low];
            low++;
        }
        maxx = max(maxx, end - low + 1);
    }
    cout << maxx << endl;
    return 0;
}
