#include <bits/stdC++.h>

using namespace std;

long long solve(int index, long long group1, long long group2, const vector<int>& weights) {
    if (index == weights.size()) {
        return abs(group1 - group2);
    }
    long long option1 = solve(index + 1, group1 + weights[index], group2, weights);
    long long option2 = solve(index + 1, group1, group2 + weights[index], weights);
    return min(option1, option2);
}

int main() {
    int n;cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << solve(0, 0, 0, v) << endl;
    return 0;
}
