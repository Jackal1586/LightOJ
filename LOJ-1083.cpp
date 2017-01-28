#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    int n,arr[30000+3],aa[30000+3],x,mx;
    int st[30000+3],ii;
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        ii=0;
        for(int i=0; i<n; i++) {
            scanf("%d",&arr[i]);
            while(ii>0) {
                if(arr[i]<=arr[st[ii-1]]) {
                    ii--;
                }
                else break;
            }
            if(ii==0)x=-1;
            else x=st[ii-1];
            aa[i]=i-x-1;
            st[ii++]=i;
        }
        mx=-1;
        ii=0;
        for(int i=n-1; i>=0; i--) {
            while(ii>0) {
                if(arr[i]<=arr[st[ii-1]]) {
                    ii--;
                }
                else break;
            }
            x=n;
            if(ii>0) {
                x=st[ii-1];
            }
            x=x-i-1;
            mx=max(mx,arr[i]*(x+aa[i]+1));
            st[ii++]=i;
        }
        cout<<"Case "<<z<<": "<<mx<<"\n";
    }
    return 0;
}

