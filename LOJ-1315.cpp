#include<bits/stdc++.h>
using namespace std;
int dirr[]={1,-1,-1,-2,-3,-2};
int dirc[]={-2,-3,-2,-1,-1,1};
int t,n,dp[502][502],q,w,_xor;
int rec(int ii,int jj){
    if(dp[ii][jj]!=-1)return dp[ii][jj];
    set<int>s;
    for(int i=0;i<6;i++){
        int x=ii+dirr[i],y=jj+dirc[i];
        if(x<0 || y<0)continue;
        s.insert(rec(x,y));
    }
    int a=0;
    while(s.find(a)!=s.end())a++;
    return dp[ii][jj]=a;
}
int main(){
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        _xor=0;
        while(n--){
            scanf("%d%d",&q,&w);
            _xor^=rec(q,w);
        }
        if(_xor)cout<<"Case "<<z<<": Alice\n";
        else cout<<"Case "<<z<<": Bob\n";
    }
    return 0;
}

