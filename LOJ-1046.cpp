#include<bits/stdc++.h>
using namespace std;
int dirr[]={1, 1, 2, 2, -1, -1, -2, -2};
int dirc[]={2, -2, 1, -1, 2, -2, 1, -1};
char s[11][11];
int n,m,cost[11][11],mv[11][11],pp[11][11],ttcc[11][11];
bool vis[11][11];
void bfs(pair<int,int>src,int vv){
	memset(vis,0,sizeof(vis));
	memset(mv,0,sizeof(mv));
	memset(cost,0,sizeof(cost));
	queue<pair<int,int> >q;
	q.push(src);
	vis[src.first][src.second]=1;
	pp[src.first][src.second]++;
	while(!q.empty()){
		src=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			pair<int,int>dest=make_pair(src.first+dirr[i],src.second+dirc[i]);
			if(dest.first<0 || dest.second<0 || dest.first>=n || dest.second>=m)continue;
			if(!vis[dest.first][dest.second]){
				vis[dest.first][dest.second]=1;
				mv[dest.first][dest.second]=(mv[src.first][src.second]+1)%vv;
				pp[dest.first][dest.second]++;
				if(mv[src.first][src.second]==0){
					cost[dest.first][dest.second]=cost[src.first][src.second]+1;
				}else{
					cost[dest.first][dest.second]=cost[src.first][src.second];
				}
				ttcc[dest.first][dest.second]+=cost[dest.first][dest.second];
				q.push(dest);
			}
		}
	}
	return;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf(" %s",&s[i]);
		}
		memset(pp,0,sizeof(pp));
		memset(ttcc,0,sizeof(ttcc));
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]>='1' && s[i][j]<='9'){
					//bfs(i,j,s[i][j]-'0');
					bfs(make_pair(i,j),s[i][j]-'0');
					cnt++;
				}
			}
		}
		int mn=(1<<(30));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(pp[i][j]==cnt && mn>ttcc[i][j]){
					mn=ttcc[i][j];
				}
			}
		}
		cout<<"Case "<<z<<": "<<((mn==(1<<30))?-1:mn)<<"\n";
    }
    return 0;
}
