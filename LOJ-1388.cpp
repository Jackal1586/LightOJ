#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    double ax,ay,bx,by,b,c,d;
    scanf("%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&b,&c,&d);
    double mf=c/(hypot(ax-bx,ay-by));
    double a=hypot(ax-bx,ay-by);
    double ss=a-c;
    double bad=((ss*ss+d*d-b*b)/(2.0*ss*d));
    double sbad=sqrt(1-bad*bad);
    double dx1=((d*(bx-ax))/a);
    double dy1=((d*(by-ay))/a);
    //cout<<dx1<<" "<<dy1<<endl;
    //cout<<bad<<" "<<sbad<<endl;
    double dx=dx1*bad-dy1*sbad+ax;
    double dy=dx1*sbad+dy1*bad+ay;
    double cx=mf*(bx-ax)+dx;
    double cy=mf*(by-ay)+dy;
    printf("Case %d:\n%.10lf %.10lf %.10lf %.10lf\n",z,cx,cy,dx,dy);
    //cout<<"Case "<<z<<":\n"<<cx<<" "<<cy<<" "<<dx<<" "<<dy<<"\n";
}
return 0;
}
