#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , x , q, m; cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin() , v.end());
    cin >> q;
    while(q--){
        cin >> m;
        cout << upper_bound(v.begin(), v.end(), m) - v.begin() << endl;
    }
    return 0;
}
