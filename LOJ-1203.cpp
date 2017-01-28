#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define sq(x) ((x)*(x))
#define isRight(r,a,b) ((b.y-r.y)*(a.x-r.x)<(b.x-r.x)*(a.y-r.y))
#define ABS(a,r) (sqrt(sq(a.x-r.x)+sq(a.y-r.y)))
#define angle(r,a,b) ((180.0*(acos(dot(r,a,b)/(ABS(a,r)*ABS(b,r)))))/PI)
#define dot(r,a,b) ((a.x-r.x)*(b.x-r.x)+(a.y-r.y)*(b.y-r.y))
struct coord
{
    double x,y;
    bool operator==(coord a)
    {
        return (x==a.x && y==a.y)?1:0;
    }
} inp[100000+10],point[100000+10],hull[100000+10];
bool comp_pos(coord a,coord b)
{
    return (a.y<b.y || (a.y==b.y && a.x<b.x));
}
bool comp_ang(coord a,coord b)
{
    return (b.y-point[0].y)*(a.x-point[0].x)>(b.x-point[0].x)*(a.y-point[0].y);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int l=1; l<=t; l++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%lf%lf",&inp[i].x,&inp[i].y);
        sort(inp,inp+n,comp_pos);
        int pointindex=0;
        point[pointindex++]=inp[0];
        for(int i=1; i<n; i++)
        {
            while(point[pointindex-1]==inp[i] && i<n)i++;
            point[pointindex++]=inp[i];
        }
        sort(point+1,point+pointindex,comp_ang);
        if(pointindex<3)
        {
            printf("Case %d: 0\n",l);
            continue;
        }
        hull[0]=point[0];
        hull[1]=point[1];
        hull[2]=point[2];
        int hullindex=3;
        for(int i=3; i<pointindex; i++)
        {
            while(isRight(hull[hullindex-2],hull[hullindex-1],point[i]))hullindex--;
            hull[hullindex++]=point[i];
        }
        double minang=361.0;
        for(int i=0; i<hullindex; i++) minang=min(angle(hull[(i+1)%hullindex],hull[i],hull[(i+2)%hullindex]),minang);
        printf("Case %d: %.10lf\n",l,minang);
    }
    return 0 ;
}
