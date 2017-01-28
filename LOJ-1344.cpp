#include<bits/stdc++.h>
using namespace std;
int n,k[52],a[52][52],dp[52][52][52],vis[52][52][52],chk,mn[52];
int rec(int ii,int jj,int kk) {
    if(kk<jj)return 0;
    if(kk==jj)return 1;
    if(vis[ii][jj][kk]==chk)return dp[ii][jj][kk];
    vis[ii][jj][kk]=chk;
    set<int>st;
//    cout<<ii<<" "<<jj<<" "<<kk<<endl;
    for(int i=jj; i<=kk; i++) {
        int x=-1,y=-1,z=0;
//        cout<<"i = "<<i<<endl;
        for(int j=jj; j<=kk; j++) {
            if(a[ii][j]<a[ii][i]) {
                if(x==-1)x=y=j;
                else y=j;
            } else {
                if(x!=-1)z^=(rec(ii,x,y));
                x=y=-1;
            }
//            cout<<"j = "<<j<<" "<<x<<" "<<y<<endl;
        }
        if(x!=-1)z^=(rec(ii,x,y));
        st.insert(z);
    }
    int ret=0;
    while(st.find(ret)!=st.end())ret++;
//    cout<<jj<<" "<<kk<<" = "<<ret<<endl;
    return dp[ii][jj][kk]=ret;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        int _xor=0;
        chk++;
        for(int i=0; i<n; i++) {
            scanf("%d",&k[i]);
            mn[i]=1<<28;
            for(int j=0; j<k[i]; j++) {
                scanf("%d",&a[i][j]);
                mn[i]=min(mn[i],a[i][j]);
            }
            _xor^=rec(i,0,k[i]-1);
        }
        cout<<"Case "<<z<<": ";
        if(_xor==0)cout<<"Genie\n";
        else {
            cout<<"Aladdin\n";
            vector<pair<int,int> >ans;
            for(int i=0; i<n; i++) {
                _xor^=rec(i,0,k[i]-1);
                for(int j=0; j<k[i]; j++) {
                    int x=-1,y=-1,qw=0;
                    for(int l=0; l<k[i]; l++) {
                        if(a[i][l]<a[i][j]) {
                            if(x==-1)x=y=l;
                            else y=l;
                        } else {
                            if(x!=-1)qw^=(rec(i,x,y));
                            x=y=-1;
                        }
                    }
                    if(x!=-1)qw^=(rec(i,x,y));
                    if((_xor^qw)==0)ans.push_back(make_pair(i+1,a[i][j]));
                }
                _xor^=rec(i,0,k[i]-1);
            }
            sort(ans.begin(),ans.end());
            ans.resize(unique(ans.begin(),ans.end())-ans.begin());
            for(int i=0;i<(int)ans.size();i++){
                cout<<"("<<ans[i].first<<" "<<ans[i].second<<")";
            }
            cout<<"\n";
        }
    }
    return 0;
}
