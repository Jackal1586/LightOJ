#include<bits/stdc++.h>
struct edge{
    int u,v,w;
    bool operator <(const edge&p)const{
        return w<p.w;
    }edge(int a,int b,int c){
        u=a,v=b,w=c;
    }
};
int pr[60];
int parent(int r){
return (pr[r]==r)?r:pr[r]=parent(pr[r]);
}
using namespace std;
int main(){
//freopen("input.txt","r",stdin);
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    map<string,int>mp;
    string s1,s2;
    vector<edge>v;
    int cost,m,cnt=1;
    scanf("%d",&m);
    while(m--){
        cin>>s1>>s2>>cost;
        if(mp[s1]==0){
            mp[s1]=cnt++;
        }if(mp[s2]==0){
            mp[s2]=cnt++;
        }v.push_back(edge(mp[s1],mp[s2],cost));
    }sort(v.begin(),v.end());
    for(int i=0;i<cnt;i++)pr[i]=i;
    cnt--;
    int sum=0,l=v.size();
    for(int i=0;i<l;i++){
        int x=parent(v[i].u),y=parent(v[i].v);
        if(x!=y){
            pr[x]=y;
            cnt--;
            sum+=v[i].w;
            if(cnt==0)break;
        }
    }if(cnt>1)cout<<"Case "<<z<<": Impossible\n";
    else cout<<"Case "<<z<<": "<<sum<<"\n";
}
return 0;
}
