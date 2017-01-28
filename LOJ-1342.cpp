#include<bits/stdc++.h>
using namespace std;
int n,x,y,a,b;
double dp[5003];
int main(){
    for(int i=1;i<=5000;i++){
        dp[i]=dp[i-1]+(1.0/double(i));
    }
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        x=0,y=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            if(b==1)x+=a;
            else y+=a;
        }
        cout<<fixed<<setprecision(8)<<"Case "<<z<<": "<<x+dp[n]*double(y)<<"\n";
    }
    return 0;
}

