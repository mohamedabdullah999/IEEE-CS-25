#include <iostream>
#include <vector>
using namespace std;

const int M = 8;
vector<string> b(M);
bool v[M], d1[2 * M], d2[2 * M];
int r = 0;

void f(int x) {
    if (x == M) {
        r++;
        return;
    }
    for (int y = 0; y < M; y++) {
        if (b[x][y] == '*' || v[y] || d1[x + y] || d2[x - y + M - 1]) {
            continue;
        }
        v[y] = d1[x + y] = d2[x - y + M - 1] = true;
        f(x + 1);
        v[y] = d1[x + y] = d2[x - y + M - 1] = false;
    }
}

int main() {
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    f(0);
    cout << r << endl;
    return 0;
}
