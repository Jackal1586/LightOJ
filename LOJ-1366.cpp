#include<bits/stdc++.h>
using namespace std;
struct triplet{
    long long a,b,c;
    triplet(){}
    triplet(int _a,int _b,int _c){a=_a,b=_b,c=_c;}
};
vector<triplet>v;
int main(){
    for(int i=1;i<=500;i++){
        for(int j=i+1;j<=500;j++){
            int x=sqrt(i*i+j*j);
            if(x*x==(i*i+j*j)){
                v.push_back(triplet(i,j,x));
            }
        }
    }
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        long long h,w,ans=0,x,y,r,c,r1,r2;
        scanf("%lld %lld",&h,&w);
        for(int i=1;i*2<=h;i++){
            for(int j=i;j*2<=w;j++){
                if(h>=(2*(i+j)) && w>=max(2*i,2*j))x=(h-2*(i+j)+1)*(w-2*max(i,j)+1);
                else x=0;
                if(w>=(2*(i+j)) && h>=max(2*i,2*j))y=(w-2*(i+j)+1)*(h-2*max(i,j)+1);
                else y=0;
                if(i==j)ans+=(x+y);
                else ans+=2*(x+y);
            }
        }
        for(int i=0;i<(int)v.size();i++){
            for(int j=1;2*j<=v[i].c;j++){
                c=v[i].c+v[i].b;
                r=v[i].c+v[i].a;
                c=max(c,(v[i].c-j)*2);
                r=max(r,(v[i].c-j)*2);
                if(h>=c && w>=r)x=(h-c+1)*(w-r+1);
                else x=0;
                if(h>=r && w>=c)y=(h-r+1)*(w-c+1);
                else y=0;
                if((2*j)==v[i].c)ans+=2*(x+y);
                else ans+=4*(x+y);
            }
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

