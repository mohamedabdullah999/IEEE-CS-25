#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , x; cin >> n;
    vector <int> v;
    for(int i = 0 ; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    int pointer_1 = 0 , pointer_2 = n - 1 , cntr_1 = 0 , cntr_2 = 0 , sum_a = v[0] , sum_b= v[n - 1];
    while(pointer_1 <= pointer_2) {
        if(sum_a <= sum_b) {
            sum_a += v[++pointer_1];
            cntr_1++;
        }
        else {
            sum_b += v[--pointer_2];
            cntr_2++;
        }
    }
    cout << cntr_1 << " " << cntr_2 << endl;
    return 0;
}