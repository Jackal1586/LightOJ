#include<bits/stdc++.h>
using namespace std;
inline int RI() {
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
bool comp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b) {
    return (a.first.second<b.first.second);
}
int tree[100003],mp[100005];
void update(int ii,int vv,int nn) {
    while(ii<=nn) {
        tree[ii]+=vv;
        ii+=((ii)&(-ii));
    }
    return;
}
int read(int ii) {
    int ret=0;
    while(ii>0) {
        ret+=tree[ii];
        ii-=((ii)&(-ii));
    }
    return ret;
}
int main() {
    int n,q,t;
    t=RI();
    //scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        n=RI();
        q=RI();
        //scanf("%d%d",&n,&q);
        int arr[n+1];
        for(int i=1; i<=n; i++) {
            arr[i]=RI();
            //scanf("%d",&arr[i]);
        }
        pair<pair<int,int>,int>p[q];
        for(int i=0; i<q; i++) {
            p[i].first.first=RI();
            p[i].first.second=RI();
            //scanf("%d %d",&p[i].first.first,&p[i].first.second);
            p[i].second=i;
        }
        sort(p,p+q,comp);
        int ans[q];
        int ee=0;
        memset(tree,0,sizeof(tree));
        memset(mp,0,sizeof(mp));
        for(int i=0; i<q; i++) {
            for(int j=ee+1; j<=p[i].first.second; j++) {
                if(mp[arr[j]]!=0) {
                    update(mp[arr[j]],-1,n);
                }
                mp[arr[j]]=j;
                update(j,1,n);
            }
            ee=p[i].first.second;
            ans[p[i].second]=read(p[i].first.second)-read(p[i].first.first-1);
        }
        cout<<"Case "<<z<<":\n";
        for(int i=0; i<q; i++) {
            cout<<ans[i]<<"\n";
        }
    }
    return 0;
}

