#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        register char s1[52],s2[52],s3[52];
        cin>>s1>>s2>>s3;
        register char l1=strlen(s1),l2=strlen(s2),l3=strlen(s3);
        register char dp[l1+1][l2+1][l3+1];
        #define mx(a,b) ((a<b)?b:a)
        for(register char i=0; i<=l1; i++) {
            for(register char j=0; j<=l2; j++) {
                for(register char k=0; k<=l3; k++) {
                    if(i==0 || j==0 || k==0) {
                        dp[i][j][k]=0;
                    }
                    else if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1]) {
                        dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    }
                    else dp[i][j][k]=mx(dp[i-1][j][k],mx(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
        cout<<"Case "<<z<<": "<<int(dp[l1][l2][l3])<<"\n";
    }
    return 0;
}

