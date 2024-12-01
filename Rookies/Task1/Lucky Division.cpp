//Lucky Division
#include <bits/stdc++.h>

using namespace std;

int s;
bool flag = 1;

bool check_lucky(int x) {
    int rem;
    while(x != 0) {
        rem = x % 10;
        if(rem != 4 && rem != 7) return false;
        x /= 10;
    }
    return true;
}

bool solve() {
    for(int i = 1; i <= s; i++) {
        if(check_lucky(i) && s % i == 0) return true;
    }
    return false;
}

int main()
{
    cin >> s;
    if(solve()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
