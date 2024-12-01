//Arrival of the General
#include <bits/stdc++.h>

using namespace std;

int n , x , minn = INT_MAX,maxx = INT_MIN ,pos_minn , pos_maxx;
vector<int>v;

void find_max_min() {
    for(int i = 0;i < n; i++) {
        if(v[i] > maxx) {maxx = v[i]; pos_maxx = i;}
        if(v[i] <= minn) {minn = v[i];pos_minn=i;}
    }
}

int solve() {
     int cntr;
     if(pos_maxx > pos_minn) {
         pos_minn++;
     }
     cntr = pos_maxx + ( (n - 1) - pos_minn);
     return cntr;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    find_max_min();

    cout << solve() << endl;

    return 0;
}
