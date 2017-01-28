#include<bits/stdc++.h>
using namespace std;
int b,k,l;
char num[18];
int arr[18];
long long dp[1<<16+1][20];
map<char,int>mp;
inline void conv(){
        for(int i=0;i<l;i++){
                arr[i]=mp[num[i]];
        }
        return ;
}
long long rec(int mask,int sum){
        if(mask==((1<<l)-1)){
                if(sum==0)return 1;
                return 0;
        }
        if(dp[mask][sum]!=-1)return dp[mask][sum];
        long long ret=0;
        for(int i=0;i<l;i++){
                if(!(mask&(1<<i))){
                        ret+=rec(mask|(1<<i),(sum*b+arr[i])%k);
                }
        }
        return dp[mask][sum]=ret;
}
int main() {
    int t;
    scanf("%d",&t);
    mp['0']=0;
    mp['1']=1;
    mp['2']=2;
    mp['3']=3;
    mp['4']=4;
    mp['5']=5;
    mp['6']=6;
    mp['7']=7;
    mp['8']=8;
    mp['9']=9;
    mp['A']=10;
    mp['B']=11;
    mp['C']=12;
    mp['D']=13;
    mp['E']=14;
    mp['F']=15;
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&b,&k);
        getchar();
        gets(num);
        l=strlen(num);
        conv();
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<rec(0,0)<<"\n";
    }
    return 0;
}
