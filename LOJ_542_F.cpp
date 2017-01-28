#include<bits/stdc++.h>
using namespace std;
int main(){
long long t;
scanf("%lld",&t);
for(long long z=1;z<=t;z++){
    long long arr[10010];
    memset(arr,0,sizeof(arr));
    long long n,q;
    scanf("%lld%lld",&n,&q);
    long long a;
    while(n--){
        scanf("%lld",&a);
        arr[a]++;
    }
    cout<<"Case "<<z<<":";
    while(q--){
        scanf("%lld",&a);
        if(arr[a])cout<<" "<<arr[a];
        else cout<<" No";
    }puts("");
}
return 0;
}
