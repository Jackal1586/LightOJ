#include<stdio.h>
#include<math.h>
//using namespace std;
#define sq(x) ((x)*(x))
#define dist(x,y) (sqrt(sq(x)+sq(y)))
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
int i,t,z;
scanf("%d",&t);
double ax,ay,bx,by,cx,cy,dx,dy,ans;
for(z=1;z<=t;z++){
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
    for(i=0;i<65;i++){
        if((sq(((2*ax+bx)/3)-((2*cx+dx)/3))+sq(((2*ay+by)/3)-((2*cy+dy)/3)))<=(sq(((ax+2*bx)/3)-((cx+2*dx)/3))+sq(((ay+2*by)/3)-((cy+2*dy)/3)))){
            bx=((ax+2*bx)/3),dx=((cx+2*dx)/3),by=((ay+2*by)/3),dy=((cy+2*dy)/3);
        }else ax=((2*ax+bx)/3),cx=((2*cx+dx)/3),ay=((2*ay+by)/3),cy=((2*cy+dy)/3);
    }
    ans=dist(ax-cx,ay-cy);
    printf("Case %d: %.10lf\n",z,((ans<(1e-9))?0:ans));
}
return 0;
}
