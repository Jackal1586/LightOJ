#include<bits/stdc++.h>
using namespace std;
char s[102];
int n,dp[102][3][3],vis[102][3][3],chk;
int rec(int ii,int ll,int rr) {
    if(ii<=0)return 0;
    if(vis[ii][ll][rr]==chk)return dp[ii][ll][rr];
    vis[ii][ll][rr]=chk;
    int l=1,r=ii;
    if(ll==1)l++;
    if(rr==1)r--;
    bool vis1[128]={0};
    for(int i=l; i<=r; i++) {
        vis1[(rec(i-1,ll,1)^rec(ii-i,1,rr))]=1;
    }
    l=1,r=ii;
    if(ll==2)l++;
    if(rr==2)r--;
    for(int i=l; i<=r; i++) {
        vis1[(rec(i-1,ll,2)^rec(ii-i,2,rr))]=1;
    }
    int ret=0;
    while(vis1[ret])ret++;
//    cout<<ii<<" "<<jj<<" "<<ll<<" "<<rr<<" "<<ret<<endl;
    return dp[ii][ll][rr]=ret;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf(" %s",s);
        n=strlen(s);
        chk++;
        int ii=-1,jj=-1,_xor=0,ll=0,rr=0;
        for(int i=0; i<n; i++) {
            if(s[i]=='.') {
                if(ii==-1) {
                    ii=jj=i;
                } else jj=i;
            } else if(ii!=-1) {
                if(ii>0) {
                    if(s[ii-1]=='.')ll=0;
                    if(s[ii-1]=='O')ll=1;
                    if(s[ii-1]=='X')ll=2;
                } else ll=0;
                if(jj+1<n) {
                    if(s[jj+1]=='.')rr=0;
                    if(s[jj+1]=='O')rr=1;
                    if(s[jj+1]=='X')rr=2;
                } else rr=0;
                _xor^=rec(jj-ii+1,ll,rr);
                ii=jj=-1;
            }
        }
        if(ii!=-1) {
            if(ii>0) {
                if(s[ii-1]=='.')ll=0;
                if(s[ii-1]=='O')ll=1;
                if(s[ii-1]=='X')ll=2;
            } else ll=0;
            if(jj+1<n) {
                if(s[jj+1]=='.')rr=0;
                if(s[jj+1]=='O')rr=1;
                if(s[jj+1]=='X')rr=2;
            } else rr=0;
            _xor^=rec(jj-ii+1,ll,rr);
        }
        bool ff=0;
        for(int i=0;i<n;i++){
            if(s[i]!='.')ff^=1;
        }
        if((_xor==0) ^ (ff))cout<<"Case "<<z<<": No\n";
        else cout<<"Case "<<z<<": Yes\n";
    }
    return 0;
}
