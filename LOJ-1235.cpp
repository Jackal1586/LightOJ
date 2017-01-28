#include<bits/stdc++.h>
using namespace std;
long long k,arr1[10],arr2[10];
int n,m;
vector<long long>a1,a2;
void rec(int idx,long long sum){
if(idx==n){
    if(sum<=k)a1.push_back(sum);
    return;
}
for(int i=0;i<3;i++){
    rec(idx+1,sum+arr1[idx]*i);
}
}
void rec1(int idx,long long sum){
if(idx==n){
    if(sum<=k)a2.push_back(sum);
    return;
}
for(int i=0;i<3;i++){
    rec1(idx+1,sum+arr2[idx]*i);
}
}
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%d%lld",&n,&k);
    if(n==1){
        long long a;
        scanf("%lld",&a);
        if(a==k || 2*a==k)cout<<"Case "<<z<<": Yes\n";
        else cout<<"Case "<<z<<": No\n";
        continue;
    }
    m=n/2;
    n-=m;
    bool flag=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&arr1[i]);
        if(arr1[i]==k || 2*arr1[i]==k)flag=1;
    }for(int i=0;i<m;i++){
        scanf("%lld",&arr2[i]);
        if(arr2[i]==k || 2*arr2[i]==k)flag=1;
    }if(!flag){
        rec(0,0);
        rec1(0,0);
        sort(a2.begin(),a2.end());
        int lim=a1.size();
        for(int i=0;i<lim;i++){
            if(a1[i]==k){flag=1;break;}
            int low=0,high=a2.size()-1;
            while((high-low)>=4){
                int mid=(low+high)/2;
                if((a1[i]+a2[mid])==k){flag=1;break;}
                else if((a1[i]+a2[mid])<k)low=mid+1;
                else high=mid-1;
            }if(flag)break;
            for(;low<=high;low++){
                if((a1[i]+a2[low])==k){flag=1;break;}
                else if((a1[i]+a2[low])>k)break;
            }if(flag)break;
        }
    }if(flag)cout<<"Case "<<z<<": Yes\n";
    else cout<<"Case "<<z<<": No\n";
    a1.clear();a2.clear();
}
return 0;
}
