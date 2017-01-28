#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
struct edge{
int u,v,w,d;
bool operator<(const edge&p)const{return w<p.w;}
edge(int a,int b,int c,int e){u=a,v=b,w=c,d=e;}
};
int n,m,pr[210],l;
int parent(int r){return (pr[r]==r)?r:pr[r]=parent(pr[r]);}
vector<edge>v;
long long mst(int day){
for(int i=0;i<=n;i++)pr[i]=i;
long long sum=0,cnt=0;
for(int i=0;i<l;i++){
    if(v[i].d<=day){
        int x=parent(v[i].u),y=parent(v[i].v);
        if(x!=y){
            pr[x]=y;
            sum+=v[i].w;
            cnt++;
            if(cnt==(n-1))break;
        }
    }
}if(cnt<(n-1))return -1;
return sum;
}
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%d%d",&n,&m);
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        v.push_back(edge(a,b,c,i));
    }sort(v.begin(),v.end());
    cout<<"Case "<<z<<":\n";
    l=v.size();
    for(int i=0;i<m;i++){
        cout<<mst(i)<<"\n";
    }v.clear();
}
return 0;
}
