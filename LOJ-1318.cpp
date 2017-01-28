#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
vector<int>prime;
void sieve() {
    prime.push_back(2);
    for(long long i=3; i<=100000; i+=2) {
        if(!vis[i]) {
            prime.push_back(i);
            for(long long j=i*i; j<=100000; j+=(i<<1)) {
                vis[j]=1;
            }
        }
    }
    return;
}
int BigMod(int b,int p,int m) {
    assert(p>=0);
    int ret=1;
    b%=m;
    while(p) {
        if(p&1)ret=(ret*b)%m;
        p>>=1;
        b=(b*b)%m;
    }
    return ret;
}
int frq[100005];
inline void ncrCalc(int x,int mul) {
    for(int i=0,y; i<(int)prime.size() && prime[i]<=x; i++) {
        y=x/prime[i];
        while(y) {
            frq[prime[i]]+=mul*y;
            y/=prime[i];
        }
    }
    return;
}
int main() {
    sieve();
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n,k,l,m;
        scanf("%d%d%d%d",&n,&k,&l,&m);
        if(k==1) {
            if(m==0)cout<<"Case "<<z<<": 2\n";
            else cout<<"Case "<<z<<": 1\n";
            continue;
        }
        int cnt;
        memset(frq,0,sizeof(frq));
        if(m>0) {
            if(k&1){
                cnt=(BigMod(k,l,n)*BigMod((k-1)/2,m,n))%n;
                frq[2]+=m-1;
            }
            else {
                cnt=(BigMod(k/2,l,n)*BigMod(k-1,m,n))%n;
                frq[2]+=l-1;
            }
        } else cnt=BigMod(k,l,n);
        ncrCalc(l,1);
        ncrCalc(l-m,-1);
        ncrCalc(m,-1);
        cnt=(cnt*BigMod(2,frq[2],n))%n;
        for(int i=3; i<100000; i+=2) {
            if(frq[i]>0) {
                cnt=(cnt*BigMod(i,frq[i],n))%n;
            }
        }
        cnt++;
        cout<<"Case "<<z<<": "<<cnt<<"\n";
    }
    return 0;
}

