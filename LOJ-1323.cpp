#include<bits/stdc++.h>
using namespace std;
struct point {
    int x,y;
    char dir[3];
    point() {};
    point(int _x,int _y,char*s) {
        x=_x,y=_y,dir[0]=s[0],dir[1]=s[1],dir[2]='\0';
    }
    void fd(int ss) {
        if(dir[0]=='N')y+=ss;
        else y-=ss;
        if(dir[1]=='W')x-=ss;
        else x+=ss;
    }
    bool operator<(const point&p)const{
        return (x<p.x || (x==p.x && y<p.y));
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    int l,w,n,k,a,b;
    char s[3];
    point arr[1002];
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d%d%d",&l,&w,&n,&k);
        for(int i=0; i<n; i++) {
            scanf("%d %d %s",&a,&b,s);
            arr[i]=point(a,b,s);
            arr[i].fd(k);
            arr[i].x%=(2*l);
            arr[i].y%=(2*w);
            arr[i].x=abs(arr[i].x);
            arr[i].y=abs(arr[i].y);
            if(arr[i].x>l) {
                arr[i].x=2*l-arr[i].x;
            }
            if(arr[i].y>w) {
                arr[i].y=2*w-arr[i].y;
            }
        }
        sort(arr,arr+n);
        cout<<"Case "<<z<<":\n";
        for(int i=0;i<n;i++){
            cout<<arr[i].x<<" "<<arr[i].y<<"\n";
        }
    }
    return 0;
}

