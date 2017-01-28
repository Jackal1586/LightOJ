#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
for(int z=1;z<=t;z++){
    int n,a,sum=0;
    cin>>n;
    while(n--){cin>>a;if(a>=0)sum+=a;}
    printf("Case %d: %d\n",z,sum);
}
return 0;
}
