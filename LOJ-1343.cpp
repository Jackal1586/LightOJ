#include<bits/stdc++.h>
using namespace std;
struct node{
    int ii,jj;
    long long vv;
    node(){}
    node(int _ii,int _jj,long long int _vv){ii=_ii,jj=_jj,vv=_vv;}
    bool operator<(const node&p)const{
        if(vv<p.vv)return true;
        if(vv==p.vv){
            if(ii==p.ii)return jj>p.jj;
            return ii<p.ii;
        }
        return false;
    }
};
int n;
long long w[502];
unsigned tree[505][505];
void update(int ii,int jj,unsigned vv){
    while(ii<=n){
        int yy=jj;
        while(yy<=n){
            tree[ii][yy]+=vv;
            yy+=((yy)&(-yy));
        }
        ii+=((ii)&(-ii));
    }
    return;
}
unsigned read(int ii,int jj){
    unsigned ret=0;
    while(ii>0){
        int yy=jj;
        while(yy>0){
            ret+=tree[ii][yy];
            yy-=((yy)&(-yy));
        }
        ii-=((ii)&(-ii));
    }
    return ret;
}
unsigned query(int ii,int jj){
    return (read(n,jj-1)-read(ii,jj-1));
}
vector<node>v;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        v.clear();
        memset(tree,0,sizeof(tree));
        for(int i=0;i<n;i++){
            scanf("%d",&w[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v.push_back(node(i+1,j+1,w[i]+w[j]));
            }
        }
        sort(v.begin(),v.end());
        unsigned ans=0;
        for(int i=0;i<v.size();i++){
            unsigned x=1+query(v[i].ii,v[i].jj);
            update(v[i].ii,v[i].jj,x);
            ans+=x;
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

