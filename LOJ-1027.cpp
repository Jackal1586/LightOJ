#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
ios_base::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
for(int z=1;z<=t;z++){
    int n;
    cin>>n;
    long long a;
    long long even=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        even+=(a>0);
        ans+=(abs(a));
    }if(even==0)cout<<"Case "<<z<<": inf\n";
    else{
        long long x=__gcd(even,ans);
        cout<<"Case "<<z<<": "<<ans/x<<"/"<<even/x<<"\n";
    }
}
return 0;
}

