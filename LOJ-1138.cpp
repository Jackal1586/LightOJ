#include<bits/stdc++.h>
using namespace std;
long long n;
/*long long*/bool ok(long long x){
    long long cnt=0;
    while(x){
        cnt+=(x/5);
        x/=5;
    }
    return ((cnt<n));
}
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%lld",&n);
    bool flag=0;
    long long low=1,high=400000020;
    while((high-low)>=4){
        long long mid=(low+high+1)/2,ans=ok(mid);
        if(ans==1)low=mid+1;
        else high=mid;
    }
    if(!flag){
        for(;low<=high;low++){
        long long x=low,cnt=0;
        while(x){
            cnt+=(x/5);
            x/=5;
        }if(cnt==n){
            flag=true;
            break;
        }
    }
    }
    if(flag)cout<<"Case "<<z<<": "<<low<<"\n";
   else cout<<"Case "<<z<<": impossible\n";
}
return 0;
}
