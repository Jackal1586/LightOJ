#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long n,w;
    scanf("%lld%lld",&n,&w);
    if(n==1){
        long long a;
        scanf("%lld",&a);
        if(a<=w)cout<<"Case "<<z<<": 2\n";
        else cout<<"Case "<<z<<": 1\n";
        continue;
    }
    long long m=(n/2);
    n-=m;
    //cout<<n<<" "<<m<<endl;
    //swap(n,m);
    long long arr1[n],arr2[m];
    for(int i=0;i<n;i++)scanf("%lld",&arr1[i]);
    for(int i=0;i<m;i++)scanf("%lld",&arr2[i]);
    //sort(arr,arr+n);
    vector<long long int>a1,a2;
   // long long m=(n/2);
    //if(n&1)m++;
    //n-=m;
    for(int i=0;i<(1<<(n));i++){
        long long sum=0;
        for(int j=0;j<(n);j++){
            if(i&(1<<j))sum+=arr1[j];
        }/*if(sum<=w)*/a1.push_back(sum);
    }//cout<<endl<<endl<<a1.size()<<endl<<endl;
    for(int i=0;i<(1<<(m));i++){
        long long sum=0;
        for(int j=0;j<(m);j++){
            if(i&(1<<j))sum+=arr2[j];
        }/*if(sum<=w)*/a2.push_back(sum);
    }long long cnt=0;/*cout<<endl;
    for(auto &x:a1)cout<<x<<" ";
    cout<<endl;
    for(auto&x:a2)cout<<x<<" ";
    cout<<endl;*/
    sort(a2.begin(),a2.end());
    for(int i=0;i<a1.size();i++){
        long long low=0,high=a2.size()-1;
        while((high-low)>=4){
            long long mid=(low+high+1)/2;
            if((a1[i]+a2[mid])<=w)low=mid;
            else high=mid-1;
        }for(;low<=high;low++){
            if((a2[low]+a1[i])>w)break;
        }cnt+=(low);
    }cout<<"Case "<<z<<": "<<cnt<<"\n";
}
return 0;
}
