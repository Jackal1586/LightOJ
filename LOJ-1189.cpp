#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long fact[21];
	fact[0]=1;
	for(unsigned long long i=1;i<=20;i++)fact[i]=i*fact[i-1];
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		unsigned long long n;
		scanf("%llu",&n);
		vector<unsigned long long>ans;
		for(int i=20;i>=0;i--){
			if(fact[i]<=n){
				ans.push_back(i);
				n-=fact[i];
			}
		}
		if(n>0){
			cout<<"Case "<<z<<": impossible\n";
			continue;
		}
		cout<<"Case "<<z<<": ";
		for(int i=ans.size()-1;i>=0;i--){
			if(i<(ans.size()-1))cout<<"+";
			cout<<ans[i]<<"!";
		}
		puts("");
	}
	return 0;
}
