#include<bits/stdc++.h>
using namespace std;
int c,d,h,s;
double dp[15][15][15][15][16];
//bool vis[15][15][15][15][16];
struct joke{
    int a,b,c,d;
    joke(){};
    joke(int _a,int _b,int _c,int _d){a=_a,b=_b,c=_c,d=_d;}
};
inline joke decode(int x){
    if(x==0)return joke(0,0,0,0);
    if(x==1)return joke(1,0,0,0);
    if(x==2)return joke(2,0,0,0);
    if(x==3)return joke(0,1,0,0);
    if(x==4)return joke(0,2,0,0);
    if(x==5)return joke(0,0,1,0);
    if(x==6)return joke(0,0,2,0);
    if(x==7)return joke(0,0,0,1);
    if(x==8)return joke(0,0,0,2);
    if(x==9)return joke(1,1,0,0);
    if(x==10)return joke(1,0,1,0);
    if(x==11)return joke(1,0,0,1);
    if(x==12)return joke(0,1,1,0);
    if(x==13)return joke(0,1,0,1);
    if(x==14)return joke(0,0,1,1);
}
inline int encode(int a,int b,int c,int d){
    if(a+b+c+d>2)return -1;
    if(a==2)return 2;
    if(a==1){
        if(b==1)return 9;
        if(c==1)return 10;
        if(d==1)return 11;
        return 1;
    }
    if(b==2)return 4;
    if(b==1){
        if(c==1)return 12;
        if(d==1)return 13;
        return 3;
    }
    if(c==2)return 6;
    if(c==1){
        if(d==1)return 14;
        return 5;
    }
    if(d==2)return 8;
    return 7;
}
double rec(int cc,int dd,int hh,int ss,int jj){
    joke x=decode(jj);
    int tt=x.a+x.b+x.c+x.d;
    if((cc+x.a)>=c && (dd+x.b)>=d && (hh+x.c)>=h && (ss+x.d)>=s)return 0.0;
    if(dp[cc][dd][hh][ss][jj]>(-1))return dp[cc][dd][hh][ss][jj];
    //vis[cc][dd][hh][ss][jj]=1;
    int den=54-(cc+dd+hh+ss+tt);
    double ret=0;
    if(cc<13){
        ret+=((1.0+rec(cc+1,dd,hh,ss,jj))*(double((double(13-cc))/den)));
    }
    if(dd<13){
        ret+=((1.0+rec(cc,dd+1,hh,ss,jj))*(double((double(13-dd))/den)));
    }
    if(hh<13){
        ret+=((1.0+rec(cc,dd,hh+1,ss,jj))*(double((double(13-hh))/den)));
    }
    if(ss<13){
        ret+=((1.0+rec(cc,dd,hh,ss+1,jj))*(double((double(13-ss))/den)));
    }
    if(tt<2){
        double rt;
        rt=(rec(cc,dd,hh,ss,encode(x.a+1,x.b,x.c,x.d)));
        rt=min(rt,rec(cc,dd,hh,ss,encode(x.a,x.b+1,x.c,x.d)));
        rt=min(rt,rec(cc,dd,hh,ss,encode(x.a,x.b,x.c+1,x.d)));
        rt=min(rt,rec(cc,dd,hh,ss,encode(x.a,x.b,x.c,x.d+1)));
        ret+=((rt+1.0)*(double((double(2-tt))/den)));
    }
    return dp[cc][dd][hh][ss][jj]=ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d%d%d",&c,&d,&h,&s);
        if((c+d+h+s)>54){
            cout<<"Case "<<z<<": "<<"-1\n";
            continue;
        }
        if((max(c-13,0)+max(d-13,0)+max(h-13,0)+max(s-13,0))>2){
            cout<<"Case "<<z<<": -1\n";
            continue;
        }
        if((c+d+h+s)==54){
            cout<<"Case "<<z<<": 54\n";
            continue;
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %.9lf\n",z,rec(0,0,0,0,0));
        //cout<<"Case "<<z<<": "<<rec(0,0,0,0,0)<<"\n";
    }
    return 0;
}

