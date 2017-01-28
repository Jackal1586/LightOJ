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
        long long arr[n+1];
        arr[0]=0;
        for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
        int mn=-1;
        for(int i=1;i<=n;i++){
            if((arr[i]-arr[i-1])>mn)mn=(arr[i]-arr[i-1]);
            else if((arr[i]-arr[i-1])==mn)mn++;
        }
        cout<<"Case "<<z<<": "<<mn<<"\n";
    }
    return 0;
}

