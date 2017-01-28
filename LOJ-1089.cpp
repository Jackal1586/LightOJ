#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n,q,t,p;
    int st[50000+2],en[50000+2];
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)scanf("%d%d",&st[i],&en[i]);
        sort(st,st+n);
        sort(en,en+n);
        cout<<"Case "<<z<<":\n";
        while(q--){
            scanf("%d",&p);
            int low=0,high=n-1,mid;
            while((high-low)>=4){
                mid=(low+high)/2;
                if(st[mid]<=p)low=mid;
                else high=mid;
            }
            for(;low<=high;low++){
                if(st[low]>p)break;
            }
            if(low>=n)low=n-1;
            if(st[low]>p){
                low--;
            }
            int x=low;
            low=0,high=n-1;
            while((high-low)>=4){
                mid=(low+high)>>1;
                if(en[mid]<p)low=mid;
                else high=mid;
            }
            for(;low<=high;low++){
                if(en[low]>=p)break;
            }
            if(low>=n)low=n-1;
            if(en[low]>=p)low--;
            x-=low;
            cout<<x<<"\n";
        }
    }
    return 0;
}

