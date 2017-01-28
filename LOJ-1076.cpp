#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long arr[n],high=0,low=-1;
    for(register int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        high+=arr[i];
        low=max(arr[i],low);
    }while((high-low)>=4){
        long long mid=(low+high+1)/2,k=1,sum=0;
        for(int i=0;i<n;i++){
            if((sum+arr[i])<=mid){
                sum+=arr[i];
            }else{
                sum=arr[i];
                k++;
            }
        }
        if(k<=m)high=mid;
        else low=mid+1;
    }for(;low<=high;low++){
        long long k=1,sum=0;
        for(int i=0;i<n;i++){
            if((sum+arr[i])<=low){
                sum+=arr[i];
            }else{
                sum=arr[i];
                k++;
            }
        }if(k<=m)break;
    }cout<<"Case "<<z<<": "<<low<<"\n";
}
return 0;
}
