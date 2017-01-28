#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int ti,de;
        scanf("%d%d",&ti,&de);
        if(ti&1) {
            printf("Case %d: 0.000000000\n",z);
            continue;
        }
        printf("Case %d: %.10lf\n",z,1.0/(1+ti));
    }
    return 0;
}

