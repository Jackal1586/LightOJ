#include<bits/stdc++.h>
using namespace std;
int main(){
int t,r1,r2,c1,c2;
scanf("%d",&t);
for(int i=1;i<=t;i++){
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    int x=abs(abs(r1-r2)-abs(c1-c2));
    if(abs(r1-r2)==abs(c1-c2))printf("Case %d: 1\n",i);
    else if(!(x&1))printf("Case %d: 2\n",i);
    else printf("Case %d: impossible\n",i);
}
return 0;
}
