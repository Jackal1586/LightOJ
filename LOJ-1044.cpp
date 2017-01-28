#include<bits/stdc++.h>
using namespace std;
char s[1003];
int l;
bool palindrome[1002][1002];
int dp[1002];
int rec(int idx) {
    if(idx>=l)return 0;
    if(dp[idx]!=-1)return dp[idx];
    dp[idx]=INT_MAX;
    for(int i=idx; i<l; i++) {
        if(palindrome[idx][i])dp[idx]=min(dp[idx],1+rec(i+1));
    }
    return dp[idx];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    getchar();
    for(int z=1; z<=t; z++) {
        gets(s);
        l=strlen(s);
        memset(palindrome,0,sizeof(palindrome));
        memset(dp,-1,sizeof(dp));
        for(int i=0; s[i]; i++)palindrome[i][i]=1;
        for(int i=1; s[i]; i++) {
            if(s[i-1]==s[i]) {
                palindrome[i-1][i]=true;
            }
        }
        for(int i=2;i<l;i++) {
            for(int j=0;j<l;j++) {
                if((s[i+j]==s[j])&&palindrome[j+1][j+i-1])palindrome[j][i+j]=true;
            }
        }
        cout<<"Case "<<z<<": "<<rec(0)<<"\n";
    }
    return 0;
}

