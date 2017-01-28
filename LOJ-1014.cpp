#include<bits/stdc++.h>
using namespace std;
#define SIZE_N 47000
bool flag[SIZE_N+10];
int prime[SIZE_N+10];
int n,l,m;
vector<int>ans,rt;
map<int,int>mp;
void rec(int res,int p)
{
    if(p==rt.size())
    {
        if(res>l)ans.push_back(res);
        return ;
    }
    int a=1;
    for(int i=0; i<=mp[rt[p]]; i++)
    {
        rec(a*res,p+1);
        a*=rt[p];
    }
    return ;
}
int sieve()
{
	int i,j,total=0,val;

	for(i=4;i<=SIZE_N;i+=2) flag[i]=1;

    	val=sqrt(SIZE_N)+1;

	for(i=3;i<val;i+=2)
       	if(!flag[i])
            		for(j=i;j*i<=SIZE_N;j++)
                		flag[i*j]=1;

	for(i=2;i<=SIZE_N;i++)
       	if(!flag[i])
            		prime[total++]=i;

    	return total;
}
int main()
{
    int t;
    int lim=sieve();
    for(int i=0;i<25;i++)cout<<prime[i]<<endl;
    scanf("%d",&t);
    for(int z=1; z<=t; z++)
    {
        scanf("%d%d",&n,&l);
        if(l>=(n-l))
        {
            cout<<"Case "<<z<<": impossible\n";
            continue;
        }
        m=n-l;
        bool flag=1;
        cout<<"Case "<<z<<": ";
        for(int i=0; (prime[i]*prime[i])<=m && i<lim; i++)
        {
            if(m%prime[i]==0)rt.push_back(prime[i]);
            while(m%prime[i]==0)
            {
                m/=prime[i];
                mp[prime[i]]++;
            }
        }
        if(m>1)
        {
            mp[m]++;
            rt.push_back(m);
        }
        rec(1,0);
        sort(ans.begin(),ans.end());
        for(int i=0; i<ans.size(); i++)
        {
            if(i)cout<<" ";
            cout<<ans[i];
        }
        puts("");
        rt.clear();
        ans.clear();
        mp.clear();
    }
    return 0;
}
