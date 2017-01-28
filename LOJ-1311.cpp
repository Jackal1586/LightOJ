#include<bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        double v1,v2,v3,a1,a2;
        cin>>v1>>v2>>v3>>a1>>a2;
        double t1=(v1/a1),t2=(v2/a2),t=max(t1,t2),d=((sq(v1)/(2.0*a1))+(sq(v2)/(2.0*a2)));
        printf("Case %d: %.8f %.8f\n",z,d,v3*t);
    }
    return 0;
}
