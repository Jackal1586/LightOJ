#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char a[11],b[11];
int k,lim;
int dp[10][4][91][91];
int rec(register int ii,register int cn,register int ss,register int ds){
	//cout<<ii<<endl;
	if(ii==lim){
		if(ss%k==0 && ds%k==0)return 1;
		return 0;
	}
	int&ret=dp[ii][cn][ss][ds];
	if(ret!=-1)return ret;
	ret=0;
	int ll,ul;
	if(cn==0){
		ll=a[ii]-48;
		ul=b[ii]-48;
	}else if(cn==1){
		ll=a[ii]-48;
		ul=9;
	}else if(cn==2){
		ll=0;
		ul=b[ii]-48;
	}else {
		ll=0;
		ul=9;
	}
	if(cn==0/* && cout<<ii<<" "<<ll<<" "<<ul<<endl */&& ll==ul)return ret=rec(ii+1,cn,(ss*10+ll)%k,(ds+ll)%k);
	for(int i=ll;i<=ul;i++){
		if(cn==0){
			if(i==ll)ret+=rec(ii+1,1,(ss*10+i)%k,(ds+i)%k);
			else if(i==ul)ret+=rec(ii+1,2,(ss*10+i)%k,(ds+i)%k);
			else ret+=rec(ii+1,3,(ss*10+i)%k,(ds+i)%k);
		}else if(cn==1){
			if(i==ll)ret+=rec(ii+1,1,(ss*10+i)%k,(ds+i)%k);
			else ret+=rec(ii+1,3,(ss*10+i)%k,(ds+i)%k);
		}else if(cn==2){
			if(i==ul)ret+=rec(ii+1,2,(ss*10+i)%k,(ds+i)%k);
			else  ret+=rec(ii+1,3,(ss*10+i)%k,(ds+i)%k);
		}else ret+=rec(ii+1,3,(ss*10+i)%k,(ds+i)%k);
	}
	return ret;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	int x,y;
	scanf("%d%d%d",&x,&y,&k);
	sprintf(b,"%d",y);
	lim=strlen(b);
	char d[11];
	sprintf(d,"%d",x);
	int i=0,c=strlen(d);
	//cout<<lim<<" "<<c<<endl;
	for(i=0;i<(lim-c);i++)a[i]='0';
	a[i]='\0';
	//i--;
	//cout<<i<<endl;
//	string jx="";
//	while(x){
//		jx+=(48+(x%10));
//		x/=10;
//	}
//	reverse(jx.begin(),jx.end());
	strcat(a,d);
	//for(int j=0;j<c;j++)a[i++]=d[j];
	//for(int i=0;i<lim;i++)cout<<a[i]<<endl;
	if(k>(9*lim)){
		cout<<"Case "<<z<<": 0\n";
		continue;
	}
	memset(dp,-1,sizeof(dp));
	cout<<"Case "<<z<<": "<<rec(0,0,0,0)<<"\n";
    }
    return 0;
}
