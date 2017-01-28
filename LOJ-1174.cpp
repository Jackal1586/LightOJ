#include<bits/stdc++.h>
using namespace std;
int cost[110][110];
int n,m,u,v,s,d;
void FW(){
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);}}}
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){if(i!=j){cost[i][j]=(1<<29);}else cost[i][j]=0;}}
    while(m--){
        scanf("%d%d",&u,&v);
        cost[u][v]=cost[v][u]=1;
    }scanf("%d%d",&s,&d);
    FW();
    int mx=-1;
    for(int i=0;i<n;i++)mx=max(mx,cost[s][i]+cost[i][d]);
    cout<<"Case "<<z<<": "<<mx<<"\n";
}
return 0;
}
