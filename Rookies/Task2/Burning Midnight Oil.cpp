#include <bits/stdc++.h>
using namespace std;

int clculate(int mid,int k,int n){
    int ans=mid;
    for(int i=1;i<30;i++){
        int w =mid/ pow(k,i);
        if(w>0)ans+=w;
        if(ans>=n||w<=0)break;
    }
    return ans;
}
int binarysearch(int n,int k){
    int l=0,r =n,ans=0;
    while (l<=r){
        int mid =(l+r)/2;
        if(clculate(mid,k,n)>=n){
            ans=mid;
            r =mid-1;
        }else l=mid+1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    cout<<binarysearch(n,k);

    return 0;
}