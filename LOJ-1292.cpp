#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n;
    scanf("%d",&n);
    pair<int,int>arr[n];
    for(int i=0;i<n;i++)scanf("%d%d",&arr[i].first,&arr[i].second);
    if(n<3){
        cout<<"Case "<<z<<": "<<n<<"\n";
        continue;
    }
    int mx=0;
    for(int i=0,k=0;i<n;i++,k=0){
        pair<int,int>ans[n-i];
        for(int j=i+1;j<n;j++){
            int a=arr[i].first-arr[j].first;
            int b=arr[i].second-arr[j].second;
            if(a<0){
                a=-a;
                b=-b;
            }else if(a==0 && b<0){
                b=-b;
            }
            int div=__gcd(abs(a),abs(b));
            a/=div;
            b/=div;
            ans[k++]=make_pair(b,a);
        }
        sort(ans,ans+k);
        int cnt=1;
        for(int j=1;j<k;j++){
            cnt=1;
            while(j<k && ans[j-1]==ans[j]){
                cnt++;j++;
            }
            mx=max(mx,cnt+1);
        }
    }cout<<"Case "<<z<<": "<<mx<<"\n";
}
return 0;
}
