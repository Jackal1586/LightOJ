#include<bits/stdc++.h>
using namespace std;
inline int RI()
{
    int ip = getchar_unlocked(), ret = 0, flag = 1;

    for(; ip < 48 || ip > 57; ip = getchar_unlocked())
    {
        if(ip == 45)
        {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }

    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
const long long mod=1000000007;
long long tree[100002];
int n;
pair<int,int>arr[100002];
bool comp(pair<int,int>a,pair<int,int>b){
	return (a.first<b.first || (a.first==b.first && a.second>b.second));
}
inline void update(int ii,int vv){
	while(ii<=n){
		tree[ii]+=vv;
		tree[ii]%=mod;
		ii+=((ii)&(-ii));
	}
	return;
}
inline long long read(int ii){
	long long ret=0;
	while(ii>0){
		ret+=tree[ii];
		ret%=mod;
		ii-=((ii)&(-ii));
	}
	return ret;
}
int main(){
	int t;
	t=RI();
	//scanf("%d",&t);
	for(int z=1;z<=t;z++){
		n=RI();
		//scanf("%d",&n);
		for(int i=1;i<=n;i++){
			arr[i]=make_pair(RI(),i);
			//scanf("%d",&arr[i].first);
			//arr[i].second=i;
			tree[i]=0;
		}
		sort(arr+1,arr+n+1,comp);
		for(int i=1;i<=n;i++){
			update(arr[i].second,1+read(arr[i].second-1));
		}
		cout<<"Case "<<z<<": "<<read(n)%mod<<"\n";
	}
	return 0;
}
