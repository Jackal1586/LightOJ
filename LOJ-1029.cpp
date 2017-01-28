#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
    bool operator<(const edge &p)const{
        return w<p.w;
    }
    edge(int a,int b,int c){
        u=a,v=b,w=c;
    }
};
int pr[120];
int parent(int r){
    return (pr[r]==r)?r:pr[r]=parent(pr[r]);
}
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)pr[i]=i;
    vector<edge>v;
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)==3 && (a||b||c)){
        v.push_back(edge(a,b,c));
    }sort(v.begin(),v.end());
    int cnt=0,sum=0,l=v.size();
    for(int i=0;i<l;i++){
        int x=parent(v[i].u),y=parent(v[i].v);
        if(x!=y){
            pr[x]=y;
            cnt++;
            sum+=v[i].w;
            if(cnt==(n)){
                for(int k=0;k<=n;k++)pr[k]=k;
                break;
            }
        }
    }for(int i=l-1;i>=0;i--){
        int x=parent(v[i].u),y=parent(v[i].v);
        if(x!=y){
            pr[x]=y;
            cnt++;
            sum+=v[i].w;
            if(cnt==0)break;
        }
    }if(sum&1)cout<<"Case "<<z<<": "<<sum<<"/2\n";
    else cout<<"Case "<<z<<": "<<(sum/2)<<"\n";
}
return 0;
}
