#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n,t,ans,lim;
    pair<long long int,long long int>arr[701];
    vector<long long int>v;
#define sq(x) ((x)*(x))
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        for(int i=0; i<n; i++) {
            scanf("%lld%lld",&arr[i].first,&arr[i].second);
        }
        if(n==1){
            cout<<"Case "<<z<<": 1\n";
            continue;
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                v.push_back(sq(arr[i].first-arr[j].first)+sq(arr[i].second-arr[j].second));
            }
        }
        ans=2;
        sort(v.begin(),v.end());
        lim=v.size();
        for(int i=1;i<lim;i++){
            if(v[i-1]!=v[i])ans++;
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
        v.clear();
    }
    return 0;
}

