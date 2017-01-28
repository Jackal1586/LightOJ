#include<bits/stdc++.h>
#define whatIs(x) cerr<<#x<<" is "<<x<<endl;
using namespace std;
int n;
double d,s[102];
bool ok(double mid){
    double x=0.0;
    for(int i=0;i<n;i++){
        double y=100.0*mid*s[i];
        y/=sqrt(1-mid*mid*s[i]*s[i]);
        x+=y;
    }
    return (x<d);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d %lf",&n,&d);
        for(int i=0;i<n;i++){
            scanf("%lf",&s[i]);
        }
        double low=0.0,high=1000.0,mid;
        for(int i=0;i<60;i++){
            mid=(low+high)/2.0;
            if(ok(mid))low=mid;
            else high=mid;
        }
        double ans=0.0;
        for(int i=0;i<n;i++){
            double x=100.0*low*s[i];
            x/=sqrt(1-low*low*s[i]*s[i]);
            x=sqrt(x*x+100.0*100.0);
            ans+=(x/s[i]);
        }
        //whatIs(low);
        printf("Case %d: %.8lf\n",z,ans);
    }
    return 0;
}

