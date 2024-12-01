// Police Recruits
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , x , untreated = 0;cin >>n;
    int cntr_1 = 0;
    for(size_t i = 0; i < n; ++i) {
        cin >> x;
        if(x > 0) cntr_1 += x;
        else if(cntr_1) cntr_1--;
        else untreated++;
    }
    cout << untreated << endl;
    return 0;
}
