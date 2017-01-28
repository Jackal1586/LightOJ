#include<bits/stdc++.h>
using namespace std;
double pw(double x,int p){
    double ret=1.0;
    while(p--){
        ret*=x;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int k;
        double a,b;
        scanf("%d%lf%lf",&k,&a,&b);
        if(fabs(a-b)<(1e-8)){
            printf("Case %d: %.9lf\n",z,pw(b,k));
            continue;
        }
        double sum=pw(b,k+1)-pw(a,k+1);
        sum/=double(k+1);
        //cout<<sum<<endl;
        if(fabs(b-a)>(1e-8))sum/=(b-a);
        printf("Case %d: %.9lf\n",z,sum);
    }
    return 0;
}

