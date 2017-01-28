#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n,k;
        double p;
        scanf("%d%d%d%lf",&n,&k,&k,&p);
        printf("Case %d: %.9lf\n",z,n*k*p);
    }
    return 0;
}

