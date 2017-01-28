#include<bits/stdc++.h>
using namespace std;
struct node{
    int x[8],y[8];
}sol[100],p;
int sz,dp[8][1<<8];
inline bool validate(int r,int c,node mask){
    for(int i=0;i<r;i++){
        if(mask.y[i]==c || abs(mask.y[i]-c)==abs(mask.x[i]-r))return 0;
    }
    return 1;
}
void dfs(int ii,node mask){
    if(ii==8){
        sol[sz]=mask;
        sz++;
        return;
    }
    for(int i=0;i<8;i++){
        if(validate(ii,i,mask)){
            mask.x[ii]=ii;
            mask.y[ii]=i;
            dfs(ii+1,mask);
        }
    }
    return;
}
inline int countStep(int x1,int y1,int x2,int y2){
    if(x1==x2 && y1==y2)return 0;
    if(x1==x2 || y1==y2 || abs(x1-x2)==abs(y1-y2))return 1;
    return 2;
}
int rec(int ii,int mask,int jj){
    if(ii==8)return 0;
    if(dp[ii][mask]!=-1)return dp[ii][mask];
    int ret=12345678;
    for(int i=0;i<8;i++){
        if(!(mask&(1<<i))){
            ret=min(ret,countStep(p.x[ii],p.y[ii],sol[jj].x[i],sol[jj].y[i])+rec(ii+1,mask|(1<<i),jj));
        }
    }
    return dp[ii][mask]=ret;
}
void _generate(){
    node a;
    dfs(0,a);
    return;
}
int main(){
    _generate();
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        char ch;
        int ii=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                scanf(" %c",&ch);
                if(ch=='q'){
                    p.x[ii]=i;
                    p.y[ii]=j;
                    ii++;
                }
            }
        }
        int ans=12345678;
        for(int i=0;i<sz;i++){
            memset(dp,-1,sizeof(dp));
            ans=min(ans,rec(0,0,i));
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

