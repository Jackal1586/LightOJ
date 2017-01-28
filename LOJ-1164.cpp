#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,q;
        scanf("%d%d",&n,&q);
        long long bit1[n+2],bit2[n+2];
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        cout<<"Case "<<z<<":\n";
        while(q--){
            int a,x,y,v;
            scanf("%d%d%d",&a,&x,&y);
            x++,y++;
            if(a==0){
                scanf("%d",&v);
                int idx=x;
                while(idx<=n){
                    bit1[idx]+=v;
                    bit2[idx]+=(v*(x-1));
                    idx+=(idx&(-idx));
                }idx=y+1;
                while(idx<=n){
                    bit1[idx]+=(-v);
                    bit2[idx]+=(-v*y);
                    idx+=(idx&(-idx));
                }
            }else{
                long long ans1=0,ans2=0;
                int idx=x-1;
                while(idx>0){
                    ans1+=(bit1[idx]);
                    idx-=(idx&(-idx));
                }ans1*=(x-1);
                idx=(x-1);
                while(idx>0){
                    ans1-=(bit2[idx]);
                    idx-=(idx&(-idx));
                }idx=y;
                while(idx>0){
                    ans2+=(bit1[idx]);
                    idx-=(idx&(-idx));
                }ans2*=y;
                idx=y;
                while(idx>0){
                    ans2-=(bit2[idx]);
                    idx-=(idx&(-idx));
                }cout<<ans2-ans1<<"\n";
            }
        }
    }
    return 0;
}

