#include<bits/stdc++.h>
using namespace std;
inline int RI() {
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
int n,source,sink,u,v,pr[50005];
vector<int>g[50005];
void bfs(){
    memset(pr,-1,sizeof(pr));
    pr[source]=-2;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(int i=0;i<g[src].size();i++){
            if(pr[g[src][i]]==-1){
                pr[g[src][i]]=src;
                if(g[src][i]==sink)return;
                q.push(g[src][i]);
            }
        }
    }
}
int main(){
    int t=RI();
    //scanf("%d",&t);
    for(int z=1;z<=t;z++){
        n=RI();
        //scanf("%d",&n);
        for(int i=0;i<=50000;i++)g[i].clear();
        for(int i=0;i<n;i++){
            u=RI();
            //scanf("%d",&u);
            if(i==0){
                source=u;
            }else {
                if(i==n-1)sink=u;
                g[v].push_back(u);
                g[u].push_back(v);
            }
            v=u;
        }
        for(int i=0;i<=50000;i++)sort(g[i].begin(),g[i].end());
        bfs();
        stack<int>st;
        while(pr[sink]!=-2){
            st.push(sink);
            sink=pr[sink];
        }
        cout<<"Case "<<z<<":\n"<<source;
        while(!st.empty()){
            cout<<" "<<st.top();
            st.pop();
        }
        cout<<"\n";
    }
    return 0;
}

