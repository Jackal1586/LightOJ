#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    register double arr[100002];
    arr[0]=0.0;
    register int i,n;
    for(i=1;i<=100000;i++)arr[i]=arr[i-1]+(double(1.0)/i);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        printf("Case %d: %.9lf\n",z,n*arr[n]);
    }
    return 0;
}

