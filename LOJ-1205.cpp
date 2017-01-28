#include<bits/stdc++.h>
using namespace std;
long long dp[18][2];
long long rec(char*s,int lim,int ii,bool ch){
    if(ii==((lim+1)/2)){
        if(ch)return 1;
        for(int i=ii,j=ii-1-(lim&1);i<lim;i++,j--){
            if(s[i]>s[j])return 1;
            if(s[i]<s[j])return 0;
        }
        return 1;
    }
    if(dp[ii][ch]!=-1)return dp[ii][ch];
    int bb=0,ee=9;
    if(ii==0 && lim>1)bb=1;
    if(!ch)ee=min(ee,s[ii]-48);
    long long ret=0;
    for(int i=bb;i<=ee;i++){
        if(ch || i<ee)ret+=rec(s,lim,ii+1,1);
        else ret+=rec(s,lim,ii+1,0);
    }
    return dp[ii][ch]=ret;
}
long long calc(char*s,int l){
    long long ret=0;
    char x[20];
    strcpy(x,"");
    for(int i=1;i<l;i++){
        strcat(x,"9");
        memset(dp,-1,sizeof(dp));
        ret+=rec(x,i,0,0);
    }
    memset(dp,-1,sizeof(dp));
    ret+=rec(s,l,0,0);
    return ret;
}
int main(){
    int t;
    char s[20];
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(a>b)swap(a,b);
        sprintf(s,"%lld",b);
        int l=strlen(s);
        long long ans=calc(s,l);
        sprintf(s,"%lld",a-1);
        l=strlen(s);
        if(a>0)ans-=calc(s,l);
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

