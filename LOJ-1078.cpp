#include<bits/stdc++.h>
using namespace std;
int main(){
register int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
        register int n,d;
        scanf("%d%d",&n,&d);
        register int x=0,y=0;
        for(y=1;;y++){
                x=(10*x+d)%n;
                if(x==0)break;
        }
        cout<<"Case "<<z<<": "<<y<<"\n";
}
return 0;
}
