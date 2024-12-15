#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<string> results;

void generate(string &s, int l) {
    if (l == s.size()) {
        results.insert(s);
        return;
    }
    for (int i = l; i < s.size(); i++) {
        swap(s[l], s[i]);
        generate(s, l + 1);
        swap(s[l], s[i]);
    }
}

int main() {
    string input;
    cin >> input;
    sort(input.begin(), input.end());
    generate(input, 0);
    cout << results.size() << endl;
    for (const auto &res : results) {
        cout << res << endl;
    }
    return 0;
}
