#include<bits/stdc++.h>
using namespace std;
int start,_end,Maxone,idealNumber,k;
pair<long long,long long>dp[30][2][30][30][3][7];
int vis[30][2][30][30][3][7],xx;
pair<long long,long long>rec(int nn,int ii,bool ff,int jj,int kk,int tt,int ss){
    if(kk>k)return make_pair(0LL,0LL);
    if(jj>Maxone)return make_pair(0LL,0LL);
    if(ii<0){
        if(tt==0 && ss!=0)return make_pair(1LL,0LL);
        return make_pair(0LL,0LL);
    }
    if(vis[ii][ff][jj][kk][tt][ss]==xx)return dp[ii][ff][jj][kk][tt][ss];
    vis[ii][ff][jj][kk][tt][ss]=xx;
    pair<long long,long long>ret=make_pair(0LL,0LL),temp;
    int lim=1;
    if(!ff && !(nn&(1<<ii)))lim--;
    for(long long i=0,j,l;i<=lim;i++){
        j=0,l=1;
        if((i==0 && (idealNumber&(1<<ii))) || (i==1 && !(idealNumber&(1<<ii))))j=1;
        if(!ff && i==lim)l=0;
        temp=rec(nn,ii-1,l,jj+i,kk+j,(tt*2+i)%3,(ss*2+i)%7);
        ret.first+=temp.first;
        ret.second+=(temp.second+temp.first*(1LL<<ii)*i);
    }
    return dp[ii][ff][jj][kk][tt][ss]=ret;
}
long long calc(int n){
    if(n<1)return 0;
    int ii=30;
    while(!(n&(1<<ii)))ii--;
    int x=0;
    if(idealNumber>n){
        for(int i=30;i>ii;i--){
            if(idealNumber&(1<<i))x++;
        }
    }
    //cout<<n<<" "<<x<<endl;
    xx++;//memset(dp,-1,sizeof(dp));
    return rec(n,ii,0,0,x,0,0).second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>start>>_end>>Maxone>>idealNumber>>k;
        cout<<"Case "<<z<<": "<<calc(_end)-calc(start-1)<<"\n";
    }
    return 0;
}

