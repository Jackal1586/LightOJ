#include<bits/stdc++.h>
using namespace std;
int s,t,sz;
int vis[1010];
vector<int>v[1010];
int prime[]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
void bfs() {
    queue<int>q;
    q.push(s);
    vis[s]=0;
    while(!q.empty()) {
        int src=q.front();
        q.pop();
        for(int i=0; i<v[src].size(); i++) {
            int dest=src+v[src][i];
            if((dest)<=t) {
                if(vis[dest]>(vis[src]+1)) {
                    vis[dest]=(vis[src]+1);
                    q.push(dest);
                }
            }
        }
    }
}
int main() {
    int T;
    sz=25;
    for(int i=2;i<=1000;i++){
        int x=i,lim=sqrt(x)+1;
        for(int j=0;j<sz && prime[j]<lim;j++){
            if(x%prime[j]==0){
                while(x%prime[j]==0)x/=prime[j];
                v[i].push_back(prime[j]);
            }
        }if(x>1 && x!=i)v[i].push_back(x);
    }
    scanf("%d",&T);
    for(int z=1; z<=T; z++) {
        scanf("%d%d",&s,&t);
        for(int i=0; i<=t; i++)vis[i]=numeric_limits<int>::max();
        if(t<s) {
            cout<<"Case "<<z<<": "<<"-1\n";
            continue;
        } else if(t==s) {
            cout<<"Case "<<z<<": "<<"0\n";
            continue;
        }

        //sz=v.size();
        bfs();
        if(vis[t]==numeric_limits<int>::max()){
            cout<<"Case "<<z<<": -1\n";
        }else cout<<"Case "<<z<<": "<<vis[t]<<"\n";
        //v.clear();
    }
    return 0;
}
