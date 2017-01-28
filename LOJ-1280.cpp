#include<bits/stdc++.h>
using namespace std;
int n,d;
double high,low,mid,ans;
struct point {
    double xx,yy;
    bool operator<(const point&p)const {
        return ((xx-mid*yy)>(p.xx-mid*p.yy));
    }
} arr[20002];
bool ok() {
    double neu=0,den=0;
    sort(arr,arr+n);
    for(int i=0; i<(n-d); i++) {
        neu+=arr[i].xx;
        den+=arr[i].yy;
    }
    return (mid*den<neu);
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&n,&d);
        for(int i=0; i<n; i++) {
            scanf("%lf %lf",&arr[i].xx,&arr[i].yy);
        }
        low=0.0,high=1.0,ans=0.0;
        for(int i=0;i<40;i++){
			mid=(low+high)/2.0;
			if(ok()){
				low=mid;
				ans=max(ans,mid);
			}else high=mid;
        }
        printf("Case %d: %.9f\n",z,ans*100.0);
    }
    return 0;
}

