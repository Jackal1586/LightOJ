#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        long long int n,w;
        scanf("%lld%lld",&n,&w);
        long long int p[n],b;
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&b,&p[i]);
        }
        sort(p,p+n);
        int ans=0;
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n && p[j]<=(p[i]+w))j++;
            i=j;
            i--;
            ans++;
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

