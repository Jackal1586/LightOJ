#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
template<int N> class matrix {
public:
    long long arr[N][N];
    matrix() {
        for( int i = 0 ; i < N ; i ++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                arr[i][j] = 0 ;
            }
        }
    }
    matrix<N> operator *(const matrix<N> &in) {
        matrix<N> ret ;
        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < N ; j++ )
                for( int k = 0 ; k < N ; k++ ) {
                    ret.arr[i][j]+=(arr[i][k])*(in.arr[k][j]) ;
                    ret.arr[i][j]%=mod;
                }
        }
        return ret ;
    }
    matrix<N> operator ^( int POW ) {
        matrix<N> ret ;
        for( int i = 0 ; i < N ; i++ ) {
            ret.arr[i][i] = 1 ;
        }
        matrix<N> ME = *this ;
        while( POW ) {
            if( POW&1 ) {
                ret = ret * ME ;
            }
            ME = ME * ME ;
            POW >>= 1 ;
        }
        return ret ;
    }
};
int mask[35],mark[128];
int main(){
    matrix<35>mul;
    memset(mark,-1,sizeof(mark));
    for(int i=15,j=0;i<128;i++){
        if(__builtin_popcount(i)==4){
            mask[j]=i;
            mark[i]=j;
            j++;
        }
    }
    for(int i=0;i<35;i++){
        int xx=0;
        vector<int>v;
        for(int j=0;j<7;j++){
            if(mask[i]&(1<<j)){
                v.push_back(j);
            }
        }
        for(int j=0;j<16;j++){
            xx=0;
            for(int k=0;k<4;k++){
                if(j&(1<<k)){
                    if(v[k]-1>=0){
                        xx|=(1<<(v[k]-1));
                    }
                }else{
                    if(v[k]+1<7){
                        xx|=(1<<(v[k]+1));
                    }
                }
            }
            if(__builtin_popcount(xx)==4 && mark[xx]!=-1)mul.arr[i][mark[xx]]++;
        }
    }
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        long long n;
        int a,init=0;
        scanf("%d",&n);
        for(int i=0;i<7;i++){
            scanf("%d",&a);
            if(a!=0)init|=(1<<i);
        }
        matrix<35>ans=mul^(n-1);
        long long cnt=0;
        for(int i=0;i<35;i++){
            cnt=(cnt+ans.arr[mark[init]][i])%mod;
        }
        cout<<"Case "<<z<<": "<<cnt<<"\n";
    }
    return 0;
}
