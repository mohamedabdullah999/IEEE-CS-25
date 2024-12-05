#include <bits/stdc++.h>

using namespace std;

int v[100005];
int n,k;
int main() {
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    long long ans=0;
    sort(v+1,v+n+1);
    for(int i=1;i<=n-2;i++)
    {
        long long p=upper_bound(v+i,v+1+n,v[i]+k)-v-1;
        ans+=(p-i)*(p-i-1)/2;
    }
    cout<<ans;

    return 0;
}