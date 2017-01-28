#include<bits/stdc++.h>
using namespace std;
int r,c;
int dirr[] = {1,1,0,-1,-1,-1,0,1};
int dirc[] = {0,1,1,1,0,-1,-1,-1};
int cc[9];
int dp[8][1<<8][1<<8];
int rec(int ii,int ps,int pr){
	if(ii==r){
		if(ps==((1<<c)-1))return 0;
		return (1<<28);
	}
	int&ret=dp[ii][ps][pr];
	if(ret!=-1)return ret;
	ret=1<<28;
	for(int i=0;i<(1<<c);i++){
		int nx=cc[ii+1],tpr=pr,tps=ps;
		for(int j=0;j<c;j++){
			if(i&(1<<j)){
				tpr^=(1<<j);
				for(int k=0;k<8;k++){
					int x=ii+dirr[k],y=j+dirc[k];
					if(x<0 || x>=r || y<0 || y>=c)continue;
					if(dirr[k]==-1)tps^=(1<<y);
					else if(dirr[k]==0)tpr^=(1<<y);
					else nx^=(1<<y);
				}
			}
		}
		if(ii==0 || tps==((1<<c)-1)){
			ret=min(ret,rec(ii+1,tpr,nx)+__builtin_popcount(i));
		}
	}
	return ret;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	scanf("%d%d",&r,&c);
	int rm=0,cm=0;
	char s;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<r;i++){
		cm=0;
		for(int j=0;j<c;j++){
			scanf(" %c",&s);
			if(s=='*'){
				cm|=(1<<j);
			}
		}
		cc[i]=cm;
	}
	int ans=rec(0,0,cc[0]);
	if(ans>=(1<<28))cout<<"Case "<<z<<": impossible\n";
	else cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
