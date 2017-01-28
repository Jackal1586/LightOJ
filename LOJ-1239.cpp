#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define sq(x) ((x)*(x))
struct coord {
    double x,y;
    bool operator==(coord a) {
        return (x==a.x && y==a.y)?1:0;
    }
} inp[100000+10],point[100000+10],hull[100000+10];
double dot(coord r,coord a,coord b) {return ((a.x-r.x)*(b.x-r.x)+(a.y-r.y)*(b.y-r.y));}
bool isRight(coord r,coord a,coord b){ return ((b.y-r.y)*(a.x-r.x)<(b.x-r.x)*(a.y-r.y));}
double ABS(coord a,coord r){ return sqrt(sq(a.x-r.x)+sq(a.y-r.y));}
double angle(coord r,coord a,coord b) {return ((180.0*(acos(dot(r,a,b)/(ABS(a,r)*ABS(b,r)))))/PI);}
bool comp_pos(coord a,coord b) {
    return (a.y<b.y || (a.y==b.y && a.x<b.x));
}
bool comp_ang(coord a,coord b) {
    return (b.y-point[0].y)*(a.x-point[0].x)>(b.x-point[0].x)*(a.y-point[0].y);
}
int main() {
    int t,n;
    double d;
    scanf("%d",&t);
    for(int l=1; l<=t; l++) {
        scanf("%d%lf",&n,&d);
        for(int i=0; i<n; i++)scanf("%lf%lf",&inp[i].x,&inp[i].y);
        sort(inp,inp+n,comp_pos);
        int pointindex=0;
        point[pointindex++]=inp[0];
        for(int i=1; i<n; i++) {
            while(point[pointindex-1]==inp[i] && i<n)i++;
            point[pointindex++]=inp[i];
        }
        sort(point+1,point+pointindex,comp_ang);
        int hullindex=0;
        for(int i=0; i<3 && i<pointindex; i++) {
            hull[hullindex++]=point[i];
        }
        if(hullindex>2) {
            for(int i=3; i<pointindex; i++) {
                while(isRight(hull[hullindex-2],hull[hullindex-1],point[i]))hullindex--;
                hull[hullindex++]=point[i];
            }
        }
        double peri=0.0,ang;
        if(hullindex>2) {
            for(int i=0; i<hullindex; i++) {
                peri+=ABS(hull[i],hull[(i+1)%hullindex]);
                //ang=angle(hull[(i+1)%hullindex],hull[(i-1+hullindex)%hullindex],hull[i]);
//                double a=hypot(hull[(i+1)%hullindex].x-hull[(i+2)%hullindex].x,hull[(i+1)%hullindex].y-hull[(i+2)%hullindex].y);
//                double b=hypot(hull[(i+1)%hullindex].x-hull[(i)].x,hull[(i+1)%hullindex].y-hull[(i)].y);
//                double c=hypot(hull[(i)].x-hull[(i+2)%hullindex].x,hull[(i)].y-hull[(i+2)%hullindex].y);
//                double s=(a+b+c)/2.0;
                //cout<<a<<" "<<b<<" "<<c<<endl;
//                ang=acos((sq(b)-sq(c)+sq(a))/(2.0*b*a));
                //ang=asin((2.0/(b*c))*(sqrt(s*(s-a)*(s-b)*(s-c))));
                //ang=180.0-ang;
                //ang=fabs(ang);
                //peri+=(PI*d*ang/180.0);
            }
        } else if(hullindex==1)peri=0.0;//2*PI*d;
        else peri=(2*hypot(hull[0].x-hull[1].x,hull[0].y-hull[1].y));//+PI*2*d;//cout<<hypot(hull[0].x-hull[1].x,hull[0].y-hull[1].y)<<endl;}
        printf("Case %d: %.8f\n",l,peri+2*PI*d);
    }
    return 0;
}
