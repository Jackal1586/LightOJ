#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        char s1[102],s2[102];
        cin>>s1>>s2;
        int l1=strlen(s1),l2=strlen(s2);
        int dp[l1+1][l2+1];
        string dps[l1+1][l2+1];
        for(int i=0; i<=l1; i++) {
            for(int j=0; j<=l2; j++) {
                if(i==0 || j==0){
		dp[i][j]=0;
		dps[i][j]="";
                }
                else if(s1[i-1]==s2[j-1]){
		dp[i][j]=dp[i-1][j-1]+1;
		dps[i][j]=dps[i-1][j-1]+s1[i-1];
                }
                else if(dp[i-1][j]>dp[i][j-1]){
		dp[i][j]=dp[i-1][j];
		dps[i][j]=dps[i-1][j];
                }
                else if(dp[i][j-1]>dp[i-1][j]){
		dp[i][j]=dp[i][j-1];
		dps[i][j]=dps[i][j-1];
                }
                else{
		dp[i][j]=dp[i-1][j];
		dps[i][j]=min(dps[i-1][j],dps[i][j-1]);
                }
            }
        }
        int lim=dp[l1][l2];
        if(lim==0) {
            cout<<"Case "<<z<<": :(\n";
            continue;
        }
        cout<<"Case "<<z<<": "<<dps[l1][l2]<<"\n";
    }
    return 0;
}
/**
1000
asdfghjkl
zxcvasdfdgbnnghh
**/
