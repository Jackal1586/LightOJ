#include<bits/stdc++.h>
using namespace std;
struct edge{
int u,v,w;
bool operator<(const edge&p)const{
return w<p.w;
}edge(int a,int b,int c){u=a,v=b,w=c;}
};
int pr[10010];
int parent(int r){return (pr[r]==r)?r:pr[r]=parent(pr[r]);}
int main(){
int t;
freopen("input.txt","r",stdin);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n,m,a;
    scanf("%d%d%d",&n,&m,&a);
    vector<edge>v;
    for(int i=0;i<=n;i++)pr[i]=i;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v.push_back(edge(a,b,c));
    }sort(v.begin(),v.end());
    long long sum=0,cnt=0,l=v.size(),ac=0;
    for(int i=0;i<l;i++){
        int x=parent(v[i].u),y=parent(v[i].v);
        if(x!=y && v[i].w<a){
            pr[x]=y;
            cnt++;
            sum+=v[i].w;
            if(cnt==(n-1))break;
        }
    }for(int i=1;i<=n;i++){
        if(pr[i]==i)ac++;
    }sum+=(a*(ac));
    cout<<"Case "<<z<<": "<<sum<<" "<<ac<<"\n";
}
return 0;
}

