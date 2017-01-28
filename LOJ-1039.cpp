#include<bits/stdc++.h>
using namespace std;
template<class T>inline int cal(T x){return 26*26*(x[0]-'a')+26*(x[1]-'a')+(x[2]-'a');}
string st,en,as[3];
int bok[]={1,-1};
int cost[18000];
void dfs(string x,int idx){
    if(idx==3){
        cost[26*26*(x[0]-'a')+26*(x[1]-'a')+(x[2]-'a')]=-1;
        return;
    }for(int i=0;as[idx][i];i++){
        x[idx]=as[idx][i];
        dfs(x,idx+1);
    }
}
void bfs(){
    queue<string>q;
    q.push(st);
    cost[cal(st)]=0;
    while(!q.empty()){
        string src=q.front();q.pop();
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                string dest=src;
                dest[i]=src[i]+bok[j];
                if(dest[i]<'a')dest[i]='z';
                else if(dest[i]>'z')dest[i]='a';
                if(cost[cal(dest)]>(cost[cal(src)]+1)){
                    cost[cal(dest)]=cost[cal(src)]+1;
                    q.push(dest);
                }
            }
        }
    }
}
int main(){
int t;
//freopen("input.txt","r",stdin);
cin>>t;
for(int z=1;z<=t;z++){
    for(int i=0;i<18000;i++)cost[i]=numeric_limits<int>::max();
    cin>>st>>en;
    int n;
    cin>>n;
    while(n--){
        cin>>as[0]>>as[1]>>as[2];
        string x;
        x.resize(3);
        dfs(x,0);
    }if(cost[cal(st)]==-1 || cost[cal(en)]==-1){
        cout<<"Case "<<z<<": -1\n";
        continue;
    }if(st==en){
        cout<<"Case "<<z<<": 0\n";
        continue;
    }bfs();
    if(cost[cal(en)]==numeric_limits<int>::max()){
        cout<<"Case "<<z<<": -1\n";
        continue;
    }cout<<"Case "<<z<<": "<<cost[cal(en)]<<"\n";
}
return 0;
}
