#include<bits/stdc++.h>
using namespace std;
const long long int mod=100000007;
long long int dp[102720];
set<long long>s;
vector<long long>v;
long long rec(int ii){
	if(ii==0)return dp[ii]=1;
	if(ii==1)return dp[ii]=1;
	if(ii==2)return dp[ii]=2;
	//if(ii==3)return dp[ii]=5;
	if(dp[ii]!=-1)return dp[ii];
	long long ret=0;
	for(int i=1;i<=ii;i++){
		ret+=(rec(i-1)*rec(ii-i))%mod;
		ret%=mod;
	}
	return dp[ii]=ret%mod;
}
int main() {
    int t;
    long long x,y,lim=100000;
	for(x=2;x<=lim;x++){
		y=x*x;
		while(y<=lim*lim){
			s.insert(y);
			y*=x;
		}
	}
	for(set<long long>::iterator i=s.begin();i!=s.end();i++){
		v.push_back(*i);
	}
	memset(dp,-1,sizeof(dp));
	//cout<<rec(3)<<endl;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
		long long a,b;
		scanf("%lld%lld",&a,&b);
		int low=0,high=102229,mid;
		while((high-low)>=4){
			mid=(low+high)>>1;
			if(v[mid]>=a){
				high=mid;
			}else low=mid;
		}
		for(;low<=high;low++){
			if(v[low]>=a)break;
		}
		//low--;
		int ans=low;
		low=0,high=102229;
		while((high-low)>=4){
			mid=(low+high)>>1;
			if(v[mid]>b)high=mid;
			else low=mid;
		}
		for(;low<=high;low++){
			if(v[low]>b)break;
		}
		low--;
		//if(low>high)low--;
		ans=low-ans+1;
		if(ans==0){
			cout<<"Case "<<z<<": 0\n";
			continue;
		}
		cout<<"Case "<<z<<": "<<rec(ans)<<"\n";
    }
    return 0;
}

