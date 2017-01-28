#include<bits/stdc++.h>
using namespace std;
string s[16];
int arr[20][20];
int dp[16][(1<<15)+10],n;
int kmp(string pattern,int len) {
    int jump[pattern.size()];
    jump[0]=0;
    for(int i=1,q=0;i<(int)pattern.size();i++){
        while(q>0 && pattern[i]!=pattern[q])q=jump[q-1];
        if(pattern[i]==pattern[q])q++;
        if(q==len)return 0;
        jump[i]=q;
    }
    return len-jump[pattern.size()-1];
}
int rec(int ii,int mask) {
    if(__builtin_popcount(mask)==n) return 0;
    int&ret=dp[ii][mask],cc;
    if(ret!=-1) return ret;
    ret=12345678;
    for(int i=0; i<n; i++) {
        if(!(mask&(1<<i))) {
            cc=arr[ii][i];
            if(cc>0)ret=min(ret,rec(i,mask|(1<<i))+cc);
            else ret=min(ret,rec(ii,mask|(1<<i)));
        }
    }
    return ret;
}
void calc(int ii,int mask) {
    if(__builtin_popcount(mask)==n) return;
    int ret=dp[ii][mask],sol,cc,nxt,st;
    string cur="ZZZ", now;
    for(int i=0; i<n; i++) {
        if(!(mask&(1<<i))) {
            cc=arr[ii][i];
            nxt=i;
            if(cc==0)nxt=ii;
            if(ret==(rec(nxt, mask|(1<<i))+cc)) {
                now=s[i].substr(s[i].size()-cc);
                if((now<cur)) {
                    cur=now;
                    st=nxt;
                    sol=i;
                }
            }
        }
    }
    cout<<cur;
    calc(st,mask|(1<<sol));
    return;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>s[i];
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j)continue;
                arr[i][j]=kmp(s[j]+"#"+s[i],s[j].size());
            }
        }
        int st,len=12345678,cur;
        string now="ZZZZ";
        memset(dp, -1, sizeof dp);
        for(int i=0; i<n; i++) {
            cur=rec(i,(1<<i))+s[i].size();
            //cout<<i<<" "<<cur<<endl;
            if((cur<len) || ((cur==len) && (s[i]<now))) {
                now=s[i];
                len=cur;
                st=i;
            }
        }
        //cout<<st<<endl;
        cout<<"Case "<<z<<": ";
        cout<<s[st];
        calc(st,(1<<st));
        cout<<"\n";
    }
    return 0;
}
