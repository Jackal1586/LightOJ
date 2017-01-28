#include<bits/stdc++.h>
using namespace std;
inline int RI() {
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
const int sz=1429450;
vector<int>v;
int tree[sz];
void update(int ii,int vv){
    while(ii<=sz){
        tree[ii]+=vv;
        ii+=((ii)&(-ii));
    }
    return;
}
int read(int ii){
    int ret=0;
    while(ii>0){
        ret+=tree[ii];
        ii-=((ii)&(-ii));
    }
    return ret;
}
int calc(int x){
    int low=0,high=sz,mid;
    while((high-low)>=4){
        mid=(low+high)>>1;
        if(read(mid)>=x)high=mid;
        else low=mid;
    }
    for(;low<=high;low++){
        if(read(low)==x)return low;
    }
}
int main(){
    int t;
    for(int i=1;i<=sz;i+=2)update(i,1);
    int ii=2;
    while(read(sz)>100001){
        //cout<<ii<<" "<<read(sz)<<"\n";
        int x=calc(ii);
        //if(ii==2||ii==3)cout<<x<<"\n";
        for(int i=x;i<=sz;i+=x){
            v.push_back(calc(i));
        }
        for(int i=0;i<v.size();i++)update(v[i],-1);
        v.clear();
        ii++;
    }
    t=RI();
    //scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n=RI();
        //scanf("%d",&n);
        cout<<"Case "<<z<<": "<<calc(n)<<"\n";
    }
    return 0;
}

