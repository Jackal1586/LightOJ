#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define what_is(x) cerr<<#x<<" is "<<x<<"\n";
#endif // ONLINE_JUDGE
using namespace std;
inline long long int RI() {
    long long int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10LL + ip - 48LL ;
    return flag * ret;
}
struct point {
    long long x,y;
    point() {}
    point(long long _x,long long _y) {
        x=_x,y=_y;
    }
    point operator-(point p) {
        return (point(x-p.x,y-p.y));
    }
    long long cross(point a,point b) {
        a=a-*this;
        b=b-*this;
        //what_is((a.x*b.y))what_is((a.y*b.x))
        return (a.x*b.y)-(a.y*b.x);
    }
} arr[100005];
bool PIP(point *p ,point sample , int n ){
    bool f = 0 ,cnt=0;
    for( int i = 0 , j = n-1 ; i < n ; j = i++ ){
        f=0;
        int xmin = min( p[i].x,p[j].x ) ;
        int xmax = max( p[i].x,p[j].x ) ;
        int ymin = min( p[i].y,p[j].y ) ;
        int ymax = max( p[i].y,p[j].y ) ;
        if( xmin <= sample.x && sample.x <= xmax && ymin <= sample.y && sample.y <= ymax){
            if(sample.cross(p[i],p[j])==0)return true ;
        }
        if(sample.cross(p[i],p[j])< 0 ){
            f = 1 ;
        }
        if(!f && p[i].y >= sample.y && p[j].y < sample.y )cnt=!cnt ;
        else if(f && p[j].y >= sample.y && p[i].y < sample.y){cnt=!cnt;}
    }
    return cnt ;
}
int main() {
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n;
        n=RI();//scanf("%d",&n);
        long long x,y;
        for(int i=0; i<n; i++) {
            x=RI(),y=RI();//scanf("%lld%lld",&x,&y);
            arr[i]=point(x,y);
        }
        int q;
        q=RI();//scanf("%d",&q);
        point _ref=arr[0];
        cout<<"Case "<<z<<":\n";
        while(q--) {
            x=RI(),y=RI();//scanf("%lld%lld",&x,&y);
            point smp(x,y);
            int low=1,high=n-1,mid;
            while((high-low)>1) {
                mid=(low+high)>>1;
                if(_ref.cross(arr[mid],smp)>0)low=mid;
                else high=mid;
            }
            point a[3];
            a[0]=arr[0];
            a[1]=arr[low];
            a[2]=arr[high];
            if(PIP(a,smp,3))cout<<"y\n";
            else cout<<"n\n";
        }
    }
    return 0;
}
/**
1
6
0 0
2 0
4 2
0 6
-4 4
-4 2
8
0 -2
1 0
4 0
2 4
0 3
-2 4
-3 6
-3 -1

1
6
0 0
2 0
4 2
0 6
-4 4
-4 2
2
1 0
4 0

1
3
0 0
2 0
4 2
2
1 0
4 0
**/

