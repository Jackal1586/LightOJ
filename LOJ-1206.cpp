#include<bits/stdc++.h>
using namespace std;
int m,bb[502],ee[502],_left[502],_right[502],vis[502],start[502],eeii,xx;
struct edge{
    int v,_next;
    edge(){}
    edge(int _v,int __next){v=_v,_next=__next;}
}edgeList[502*502];
void init(){
    eeii=0;
    memset(start,-1,sizeof(start));
    return;
}
void addEdge(int u,int v){
    edgeList[eeii]=edge(v,start[u]);start[u]=eeii;eeii++;
    //edgeList[eeii]=edge(u,start[v]);start[v]=eeii;eeii++;
    return;
}
bool dfs(int src){
    if(vis[src]==xx)return false;
    vis[src]=xx;
    for(int i=start[src];i!=-1;i=edgeList[i]._next){
        if(_right[edgeList[i].v]==-1){
            _right[edgeList[i].v]=src;
            _left[src]=edgeList[i].v;
            return true;
        }
    }
    for(int i=start[src];i!=-1;i=edgeList[i]._next){
        if(dfs(_right[edgeList[i].v])){
            _right[edgeList[i].v]=src;
            _left[src]=edgeList[i].v;
            return true;
        }
    }
    return false;
}
int BPM(){
    memset(_left,-1,sizeof(_left));
    memset(_right,-1,sizeof(_right));
    bool done=false;
    while(!done){
        xx++;
        done=true;
        for(int i=0;i<m;i++){
            if(_left[i]==-1 && dfs(i)){
                done=false;
            }
        }
    }
    int ret=0;
    for(int i=0;i<m;i++)ret+=(_left[i]!=-1);
    return ret;//>>1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>m;
        int hh,mm,x1[m],x2[m],y1[m],y2[m];
        char ch;
        for(int i=0;i<m;i++){
            cin>>hh>>ch>>mm>>x1[i]>>y1[i]>>x2[i]>>y2[i];
            bb[i]=hh*60+mm;
            ee[i]=bb[i]+abs(x1[i]-x2[i])+abs(y1[i]-y2[i]);
        }
        init();
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)continue;
                if(bb[j]>ee[i]+abs(x1[j]-x2[i])+abs(y1[j]-y2[i])){
                    addEdge(i,j);
                }
            }
        }
        cout<<"Case "<<z<<": "<<m-BPM()<<"\n";
    }
    return 0;
}

