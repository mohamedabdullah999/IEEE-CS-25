//Keyboard
#include <bits/stdc++.h>

using namespace std;

string general = "qwertyuiopasdfghjkl;zxcvbnm,./" , s;
map <char , char> mp_right , mp_left;
char des;

void Set() {
     for(int i = 1 ; i < general.size(); i++) {
         mp_right[general[i]] = general[i - 1];
         mp_left[general[i - 1]] = general[i];
     }
}

void solve() {
    Set();
     for(auto it:s) {
         des == 'R'? cout << mp_right[it] : cout << mp_left[it];
     }
    cout << endl;
}

int main()
{
    cin >> des;
    cin >> s;
    solve();
    return 0;
}
