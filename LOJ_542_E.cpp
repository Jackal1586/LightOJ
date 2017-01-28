#include<bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
const double eps = 1e-11;
struct point{
    double x,y;
};
struct edge{
    point p1,p2;
};
double dist(edge a){
    return sqrt(sq(a.p1.x-a.p2.x)+sq(a.p1.y-a.p2.y));
}
bool comp(edge a,edge b){
    return (dist(a)+eps)<dist(b);
}
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n;
    double s;
    scanf("%d%lf",&n,&s);
    edge arr[n];
    for(int i=0;i<n;i++){
        scanf("%lf%lf%lf%lf",&arr[i].p1.x,&arr[i].p1.y,&arr[i].p2.x,&arr[i].p2.y);
    }sort(arr,arr+n,comp);
    int i=0;
    while(s>=eps){
        if(s>=(dist(arr[i])+eps)){
            s-=dist(arr[i++]);
        }else break;
    }
    printf("Case %d: %d\n",z,i);
}
return 0;
}
