#include<bits/stdc++.h>
using namespace std;
vector<long long>v1,v;
map<long long,bool>mp;
void gen(long long n,int l){
	if(l>=12)return ;
	v1.push_back(n*10+4);
	v1.push_back(n*10+7);
	gen(n*10+4,l+1);
	gen(n*10+7,l+1);
	return ;
}
void gen1(long long n){
	if(n>(1000000000000LL))return ;
	if(mp[n])return ;
	mp[n]=true;
	v.push_back(n);
	for(int i=0;i<v1.size();i++){
		if((n*v1[i])<(1000000000000LL)){
			gen1(n*v1[i]);
		}else return ;
	}
	return ;
}
int main() {
    int t;
    gen(0,0);
    sort(v1.begin(),v1.end());
    for(int i=0;i<v1.size();i++){
	gen1(v1[i]);
    }
    sort(v.begin(),v.end());
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	cout<<"Case "<<z<<": "<<upper_bound(v.begin(),v.end(),b)-lower_bound(v.begin(),v.end(),a)<<"\n";
    }
    return 0;
}
