#include<bits/stdc++.h>
using namespace std;
struct point{
    int xxx,yyy,iii;
    point(){};
    point(int _x,int _y,int _i){xxx=_x,yyy=_y,iii=_i;}
    inline int dist(point r){return (xxx-r.xxx)*(xxx-r.xxx)+(yyy-r.yyy)*(yyy-r.yyy);}
};
point arr[2002];
inline bool comp_ang(point a,point b)
{
    if((b.yyy-arr[0].yyy)*(a.xxx-arr[0].xxx)>(b.xxx-arr[0].xxx)*(a.yyy-arr[0].yyy))return 1;
    if((b.yyy-arr[0].yyy)*(a.xxx-arr[0].xxx)==(b.xxx-arr[0].xxx)*(a.yyy-arr[0].yyy)){
        return a.dist(arr[0])<b.dist(arr[0]);
    }return 0;
}
inline bool joke(point a,point b,point r)
{
    return (b.yyy-r.yyy)*(a.xxx-r.xxx)==(b.xxx-r.xxx)*(a.yyy-r.yyy);
}
int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        int xx=1<<20,yy=1<<20,ii=0;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            arr[i]=point(x,y,i);
            if(y<yy || (y==yy && x<xx)){
                yy=y;
                xx=x;
                ii=i;
            }
        }
        swap(arr[0],arr[ii]);
        //sort(arr,arr+n,comp_pos);
        sort(arr+1,arr+n,comp_ang);
        bool f=0;
        int tmp=0;
        for(int i=n-2;i>0;i--){
            if(!joke(arr[n-1],arr[i],arr[0])){
                tmp=i;
                break;
            }
        }
        cout<<"Case "<<z<<":\n";
        if(tmp==0){
            puts("Impossible");
            continue;
        }
        //reverse(arr+tmp+1,arr+n);
        for(int i=0;i<=tmp;i++){
            cout<<((i>0)?" ":"")<<arr[i].iii;
        }
        for(int i=(n-1);i>tmp;i--){
            cout<<" "<<arr[i].iii;
        }
        puts("");
    }
    return 0;
}

