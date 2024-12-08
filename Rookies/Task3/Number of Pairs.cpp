#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int l, int r, vector<int> a) {
    sort(a.begin(), a.end());
    long long cntr = 0;
    for (int i = 0; i < n; ++i) {
        int lo = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin();
        int hi = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin() - 1;
        if (lo <= hi) {
            cntr += (hi - lo + 1);
        }
    }
    return cntr;
}

int main() {
    int t;cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve(n, l, r, a) << endl;
    }

    return 0;
}
