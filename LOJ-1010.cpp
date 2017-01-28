#include<bits/stdc++.h>
using namespace std;
//template<class T>void swp(T a,T b){T temp=a;a=b;b=temp;}
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n,m;
    scanf("%d%d",&n,&m);
    if(m==1 || m==2)swap(n,m);
    if(n==1)printf("Case %d: %d\n",z,m);
    else if(n==2){int ans=((m/4)+1)*4;if((m%4)==1)ans-=2;if(m%4==0)ans-=4;printf("Case %d: %d\n",z,ans);}
    else printf("Case %d: %d\n",z,(n*m+1)/2);
}
return 0;
}
