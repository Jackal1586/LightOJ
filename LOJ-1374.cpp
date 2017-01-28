#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n;
        scanf("%d",&n);
        int a;
        bool mp[n];
        memset(mp,0,sizeof(mp));
        bool flag=0;
        for(int i=0; i<n; i++) {
            scanf("%d",&a);
            if(a>=n){
                flag=1;
                continue;
            }
            if(mp[a] && mp[n-a-1]){
                flag=1;
                continue;
            }
            if(!mp[a]){
                mp[a]=true;
                continue;
            }
            mp[n-a-1]=true;
        }
        if(flag)cout<<"Case "<<z<<": no\n";
        else cout<<"Case "<<z<<": yes\n";
    }
    return 0;
}

