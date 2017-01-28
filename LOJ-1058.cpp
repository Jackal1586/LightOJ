#include<bits/stdc++.h>
using namespace std;
struct point{
long long x,y;
point(){}
point(long long a,long long b){x=a,y=b;}
bool operator<(const point&p)const{if(x<p.x)return x<p.x;else if(x==p.x)return y<p.y;else return 0;}
bool operator==(const point&p)const{return ((x==p.x)&&(y==p.y));}
};
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n;
    scanf("%d",&n);
    point arr[n];
    for(int i=0;i<n;i++)scanf("%lld%lld",&arr[i].x,&arr[i].y);
    vector<point>v;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)v.push_back(point(arr[i].x+arr[j].x,arr[i].y+arr[j].y));
    sort(v.begin(),v.end());
    long long ans=0,cnt=1;
    for(int i=1;i<v.size();i++){
        //cout<<v[i-1].x<<" "<<v[i-1].y<<" <> "<<v[i].x<<" "<<v[i].y<<endl;
        if(v[i]==v[i-1])cnt++;
        else{ans+=((cnt*(cnt-1))/2);cnt=1;}
    }cout<<"Case "<<z<<": "<<ans+((cnt*(cnt-1))/2)<<"\n";
}
return 0;
}
