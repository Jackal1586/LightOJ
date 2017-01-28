#include<bits/stdc++.h>
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
struct point{
    long long x,y;
    point(){}
    point(long long _x,long long _y){x=_x,y=_y;}
    void calc(point p,long long d,long long mid){
        long long q=sqrt(d*d-(mid+p.y)*(mid+p.y));
        x=p.x-q;
        y=p.x+q;
        return;
    }
    bool operator<(const point&p)const{return (y<p.y);}
}a[10003],b[10003];
long long int n,s,d,k,x,y;
bool ok(int mid){
    for(int i=0;i<n;i++){
        if(mid+a[i].y>d)return 0;
        b[i].calc(a[i],d,mid);
    }
    sort(b,b+n);
    long long int ee=b[0].x-1,cnt=0;
    for(int i=0;i<n;i++){
        if(b[i].x>ee){
            cnt++;
            ee=b[i].y;
        }
        if(cnt>s)return 0;
    }
    return 1;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        k=RI(),n=RI(),s=RI(),d=RI();//scanf("%lld%lld%lld%lld",&k,&n,&s,&d);
        for(int i=0;i<n;i++){
            x=RI(),y=RI();//scanf("%lld%lld",&x,&y);
            y-=k;
            a[i]=point(x,y);
        }
        long long low=0,high=d,mid;
        bool f=0;
        while((high-low)>=4){
            mid=(high+low)>>1;
            if(ok(mid))low=mid;
            else high=mid;
        }
        for(;low<=high;low++){
            if(!ok(low))break;
        }
        low--;
        if(low<=0 && !ok(0)){
            cout<<"Case "<<z<<": impossible\n";
            continue;
        }
        cout<<"Case "<<z<<": "<<low<<"\n";
    }
    return 0;
}

