#include<bits/stdc++.h>
#define sq(x) ((x)*(x))
using namespace std;
int main() {
    double l,w;
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
            scanf("%lf%lf",&l,&w);
                //double x1=(4.0*(l+w) + sqrt(16*sq(l+w) - 48*l*w))/24;
                double x2=(4.0*(l+w) - sqrt(16*sq(l+w) - 48*l*w))/24;
                //cout<<x1<<" "<<x2<<"\n";
                //double x=min(x1,x2);
                cout<<"Case "<<z<<": "<<setprecision(12)<<((l-2*x2)*(w-2*x2)*x2)<<"\n";
                //printf("Case %d: %.10f\n",z,);
    }
    return 0;
}

