#include<bits/stdc++.h>
using namespace std;
struct node{
    int xx,yy;
    bool sex;
    node(){}
    node(int _xx,int _yy,bool _sex){xx=_xx,yy=_yy,sex=_sex;}
    bool operator<(const node&p)const{return (xx<p.xx || (xx==p.xx && yy<p.yy));}
};
int tree[2][200005],n,m;
void update(bool ff,int ii,int vv){
    while(ii<=(n+m)){
        tree[ff][ii]+=vv;
        ii+=((ii)&(-ii));
    }
    return;
}
long long read(int ii,bool ff){
    int ret=0;
    while(ii>0){
        ret+=tree[ff][ii];
        ii-=((ii)&(-ii));
    }
    return ret;
}
vector<node>v;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(tree,0,sizeof(tree));
        v.clear();
        int x,y;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            v.push_back(node(x,y,0));
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            v.push_back(node(x,y,1));
        }
        sort(v.begin(),v.end());
        long long ans=0;
        for(int i=0;i<v.size();i++){
            ans+=(read(n+m,!v[i].sex)-read(v[i].yy-1,!v[i].sex));
            update(v[i].sex,v[i].yy,1);
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

