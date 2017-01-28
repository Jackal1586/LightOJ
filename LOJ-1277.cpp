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
int n,q,arr[100003],l[100003],I[100003],m,lim;
int LIS(){
    I[0]=(1<<30);
    for(int i=1;i<=n;i++)I[i]=-(1<<30);
    int lisLength=0;
    for(int i=n-1;i>=0;i--){
        int low=0,high=lisLength,mid;
        while(low<=high){
            mid=(low+high)>>1;
            if(I[mid]>arr[i])low=mid+1;
            else high=mid-1;
        }
        I[low]=arr[i];
        l[i]=low;
        lisLength=max(lisLength,low);
    }
    return lisLength;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        n=RI(),q=RI();//scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++){
            arr[i]=RI();//scanf("%d",&arr[i]);
        }
        lim=LIS();
        cout<<"Case "<<z<<":\n";
        while(q--){
            m=RI();//scanf("%d",&m);
            if(m>lim){
                puts("Impossible");
                continue;
            }
            int y=0,e,r;
            for(;y<n;y++){
                if(l[y]>=m){
                    cout<<arr[y];
                    m--;
                    break;
                }
            }
            for(int i=y+1;i<n && m;i++){
                if(l[i]>=m && arr[i]>arr[y]){
                    cout<<" "<<arr[i];
                    y=i;
                    m--;
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}

