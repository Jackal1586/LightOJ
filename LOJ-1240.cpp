#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
#define sq(x) ((x)*(x))
#define dis(x,y,z) (sqrt(sq(x)+sq(y)+sq(z)))
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
int t,l,i;
scanf("%d",&t);
double x1,x2,x,y1,y2,y,z1,z2,z;
for(l=1;l<=t;l++){
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&x2,&y2,&z2,&x,&y,&z);
    for(i=0;i<58;i++){
        if((sq(((2*x1+x2)/3)-x)+sq(((2*y1+y2)/3)-y)+sq(((2*z1+z2)/3)-z))<=(sq(((x1+2*x2)/3)-x)+sq(((y1+2*y2)/3)-y)+sq(((z1+2*z2)/3)-z))){
            x2=((x1+2*x2)/3),y2=((y1+2*y2)/3),z2=((z1+2*z2)/3);
        }else x1=((2*x1+x2)/3),y1=((2*y1+y2)/3),z1=((2*z1+z2)/3);
    }cout<<"Case "<<l<<": ";printf("%.10lf\n",l,dis(x1-x,y1-y,z1-z));
}
return 0;
}
