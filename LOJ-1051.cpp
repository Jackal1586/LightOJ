#include<bits/stdc++.h>
using namespace std;
#define IV(a) ((a=='A' || a=='E' || a=='I' || a=='O' || a=='U')?'1':'0')
int n;
char dp[52][4][6];
char s[53];
bool rec(int ii,int v,int c){
    if(v==3)return 0;
    if(c==5)return 0;
    if(ii==n)return 1;
    if(dp[ii][v][c]!=-1)return dp[ii][v][c];
    if(s[ii]=='1')return dp[ii][v][c]=rec(ii+1,v+1,0);
    if(s[ii]=='0')return dp[ii][v][c]=rec(ii+1,0,c+1);
    return dp[ii][v][c]=(rec(ii+1,v+1,0)|rec(ii+1,0,c+1));
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
        n=strlen(s);
        bool flag=0;
        int cnt=0;
        for(int i=0; s[i]; i++) {
            if(s[i]=='?') {
                cnt++;
                continue;
            } else s[i]=IV(s[i]);
        }
        int c=0,v=0;
        for(int i=0; i<n; i++) {
            if(s[i]=='?'){
                v=0;c=0;
                continue;
            }
            if(s[i]=='0'){
                c++;
                v=0;
            }
            else if(s[i]=='1'){
                v++;
                c=0;
            }
            if(c==5 || v==3) {
                flag=1;
                break;
            }
        }
        //cout<<"ok\n";
        /*if(cnt==0 && !flag){
            cout<<"Case "<<z<<": GOOD\n";
            continue;
        }
        //cout<<"ok\n";
        if(flag) {
            cout<<"Case "<<z<<": BAD\n";
            continue;
        }
        //cout<<"ok\n";*/
        c=0,v=0;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                x++;
                y++;
            }else if(s[i]=='1'){
                v++;
                c=x=0;
            }else {
                c++;
                v=y=0;
            }
            if((c+x)==5 || (v+y)==3){
                flag=1;
                break;
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=rec(0,0,0);
        cout<<ans<<endl;
        if(flag){
            if(ans>=1)cout<<"Case "<<z<<": MIXED\n";
            else cout<<"Case "<<z<<": BAD\n";
        }else if(ans>=1){
            cout<<"Case "<<z<<": GOOD\n";
        }else {
            cout<<"Case "<<z<<": BAD\n";
        }
    }
    return 0;
}

