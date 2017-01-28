#include<bits/stdc++.h>
using namespace std;
struct joke{
            int val,ii;
            joke(){}
            joke(int a,int b){val=a,ii=b;}
            bool operator<(const joke&p)const{
                return (val<=p.val);
            }
    };
char n,arr[101],dp[101][101][101];
int rec(register int ii,register int ll,register int rr){
    //if(rr<ll)return 0;
    if(ii>=n)return 0;
    if(dp[ii][ll][rr]!=-1)return dp[ii][ll][rr];
    int ret=0;
    if(arr[ii]>=ll && arr[ii]<=rr)ret=max(max(ret,1+rec(ii+1,ll,arr[ii])),1+rec(ii+1,arr[ii],rr));
    //if(arr[ii]<=rr)ret=max(ret,1+rec(ii+1,ll,arr[ii]));
    ret=max(ret,rec(ii+1,ll,rr));
    return dp[ii][ll][rr]=ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    register int t;
    scanf("%d",&t);
    for(register int z=1;z<=t;z++){
        scanf("%d",&n);
        //vector<pair<int,int> >v;
        register int a;
        joke ax[n];
        memset(dp,-1,sizeof(dp));
        for(register int i=0;i<n;i++){
            scanf("%d",&a);
            ax[i]=joke(a,i);
        }
        sort(ax,ax+n);
        arr[ax[0].ii]=0;
        for(register int i=1,j=0;i<n;i++){
            if(ax[i].val!=ax[i-1].val)j++;
            arr[ax[i].ii]=j;
        }
        cout<<"Case "<<z<<": "<<rec(0,0,100)<<"\n";
    }
    return 0;
}
