#include<bits/stdc++.h>
using namespace std;
bool vis[10000005];
vector<int>prime;
void sieve(){
    vis[0]=vis[1]=1;
    for(int i=2;i*i<=10000000;i++){
        if(!vis[i])
        for(int j=i+i;j<=10000000;j+=i){
            vis[j]=1;
        }
    }
    for(int i=0;i<=10000000;i++){
        if(!vis[i])prime.push_back(i);
    }
}
int main(){
sieve();
//freopen("outp.txt","w",stdout);
for(int i=0;i<=32768;i++)cout<<vis[i]<<",";
int t,n;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%d",&n);
    int sum=0;
    for(int i=0;prime[i]<=(n/2);i++)sum+=!vis[n-prime[i]];
    printf("Case %d: %d\n",z,sum);
}
return 0;
}
