#include<bits/stdc++.h>
using namespace std;
char s[12];
int d,l,arr[12];
long long dp[(1<<10)+2][1001];
long long int rec(register int mask,register int sum){
	if(mask==((1<<l)-1)){
		if(sum==0)return 1;
		return 0;
	}
	long long int&ret=dp[mask][sum];
	if(ret!=-1)return ret;
	ret=0;
	for(int i=0;i<l;i++){
		if(!(mask&(1<<i))){
			ret+=rec(mask|(1<<i),(sum*10+s[i]-48)%d);
		}
	}
	return ret;
}
int main(){
int t;
int fact[11];
fact[0]=1;
for(int i=1;i<=10;i++)fact[i]=i*fact[i-1];
scanf("%d",&t);
for(int z=1;z<=t;z++){
	getchar();
	scanf("%s %d",s,&d);
	memset(dp,-1,sizeof(dp));
	l=strlen(s);
	long long int ans=rec(0,0);
	memset(arr,0,sizeof(arr));
	for(int i=0;i<l;i++){
		arr[s[i]-48]++;
	}
	for(int i=0;i<10;i++){
		ans/=fact[arr[i]];
	}
	cout<<"Case "<<z<<": "<<ans<<"\n";
}
return 0;
}
