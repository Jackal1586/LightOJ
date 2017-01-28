#include<bits/stdc++.h>
using namespace std;
double n,c;
template<class T>inline T calc(T t){return (c*t-n*t*t);}
int main(){
        #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        #endif // ONLINE_JUDGE
        int t;
        scanf("%d",&t);
        for(int z=1;z<=t;z++){
                scanf("%lf%lf",&n,&c);
                if(n==0 || c==0 || n>=c){cout<<"Case "<<z<<": 0\n";continue;}
                long long x1=((long long)(ceil(c/(2*n))));
                long long x2=((long long)(floor(c/(2*n))));
                long long ans;
                if(calc(x2)>=calc(x1))ans=x2;
                else ans=x1;
                cout<<"Case "<<z<<": "<<ans<<"\n";
        }
        return 0;
}

