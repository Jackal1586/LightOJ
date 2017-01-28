#include<bits/stdc++.h>
using namespace std;
struct edge {
    int u,v,w;
    edge(int a,int b,int c) {
        u=a,v=b,w=c;
    }
};
bool comp(edge a,edge b) {
    return a.w<b.w;
}
int pr[55];
int parent(int r) {
    return (pr[r]==r)?r:pr[r]=parent(pr[r]);
}
int main() {
    int t;
freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n;
        scanf("%d",&n);
        vector<edge>v;
        long long sum1=0,ax;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%lld",&ax);
                sum1+=ax;
                if(i!=j && ax!=0)v.push_back(edge(i,j,ax));
            }
        }
        sort(v.begin(),v.end(),comp);
        long long sum2=0,cnt=0,l=v.size();
        for(int i=1; i<=n; i++)pr[i]=i;
        for(int i=0; i<l; i++) {
            int x=parent(v[i].u),y=parent(v[i].v);
            if(x!=y) {
                pr[x]=y;
                sum2+=v[i].w;
                cnt++;
                if(cnt==(n-1))break;
            }
        }
        if(cnt<(n-1))cout<<"Case "<<z<<": -1\n";
        else cout<<"Case "<<z<<": "<<(sum1-sum2)<<"\n";
    }
    return 0;
}

