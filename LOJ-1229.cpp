#include<bits/stdc++.h>
using namespace std;
int dp[203],vis[203],l;
char s[203];
bool ok(){
    for(int i=0;i+2<l;i++){
        if(s[i]=='X' && s[i+1]=='X' && s[i+2]=='X')return 1;
    }
    for(int i=1;i<l;i++){
        if(s[i-1]=='X' && s[i]=='X')return 0;
        if(i+1<l && s[i-1]=='X' && s[i+1]=='X')return 0;
    }
    int cnt=0,x=0,ret=0;
    for(int i=0;i<l;i++){
        if(s[i]=='.')cnt++;
        else{
            if(cnt==0)x++;
            else{
                if(x>=1)ret^=(dp[max(0,cnt-4)]);
                else ret^=(dp[max(0,cnt-2)]);
                cnt=0;
                x=1;
            }
        }
    }
    if(cnt>0)ret^=dp[max(0,cnt-2)];
    return (ret==0);
}
int main(){
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=200;i++){
        for(int j=0;j<i;j++){
            vis[dp[max(0,j-2)]^dp[max(0,(i-j-1)-2)]]=i;
        }
        for(int j=0;;j++){
            if(vis[j]!=i){
                dp[i]=j;
                break;
            }
        }
    }
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf(" %s",s);
        l=strlen(s);
        bool ff=1;
        cout<<"Case "<<z<<":";
        for(int i=0;i<l;i++){
            if(s[i]=='.'){
                s[i]='X';
                if(ok()){
                    cout<<" "<<i+1;
                    ff=0;
                }
                s[i]='.';
            }
        }
        if(ff)cout<<" 0";
        cout<<"\n";
    }
    return 0;
}
