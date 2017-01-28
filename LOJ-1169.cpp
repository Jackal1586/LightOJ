#include<bits/stdc++.h>
using namespace std;
int n,fl[1000],fr[1000],tlr[1000],trl[1000],dp[2][1000];
int rec(register bool lr,register int flr){
	if(flr==n)return 0;
	int&ret=dp[lr][flr];
	if(ret!=-1)return ret;
	if(lr==0){
		return ret=(min(rec(0,flr+1),tlr[flr]+rec(1,flr+1))+fl[flr]);
	}
	return ret=(min(rec(1,flr+1),trl[flr]+rec(0,flr+1))+fr[flr]);
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&fl[i]);
	for(int i=0;i<n;i++)scanf("%d",&fr[i]);
	for(int i=0;i<(n-1);i++)scanf("%d",&tlr[i]);
	for(int i=0;i<(n-1);i++)scanf("%d",&trl[i]);
	memset(dp,-1,sizeof(dp));
	tlr[n-1]=trl[n-1]=0;
	cout<<"Case "<<z<<": "<<min(rec(0,0),rec(1,0))<<"\n";
    }
    return 0;
}
