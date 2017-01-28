#include<bits/stdc++.h>
using namespace std;
int rec(int n,int k){
    if(n==1)return 1;
    return ((rec(n-1,k)+k-1)%n+1);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n,k;
        scanf("%d%d",&n,&k);
        cout<<"Case "<<z<<": "<<rec(n,k)<<"\n";
    }
    return 0;
}

