#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
unsigned int ncr[52][52],x;
template<int N> class matrix {
public:
    unsigned int  arr[N][N];
    matrix() {
        for( int i = 0 ; i < N ; i ++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                arr[i][j] = 0 ;
            }
        }
    }
    matrix<N> operator *(const matrix<N> &in) {
        matrix<N> ret ;
        for( int i = 0 ; i < x ; i++ ) {
            for( int j = 0 ; j < x ; j++ )
                for( int k = 0 ; k < x ; k++ ) {
                    ret.arr[i][j]+=(arr[i][k])*(in.arr[k][j]) ;
                }
        }
        return ret ;
    }
    matrix<N> operator ^(long long int POW ) {
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
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int i=0;i<=50;i++)ncr[i][0]=ncr[0][i]=1;
    for(int i=1;i<=50;i++){
        ncr[i][1]=i;
        for(int j=2;j<=i;j++){
            ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
        }
    }
    for(int z=1; z<=t; z++) {
        long long n;
        unsigned int k;
        scanf("%lld%u",&n,&k);
        x=k+2;
        matrix<52>mul;
        mul.arr[0][0]=1;
        for(int i=0;i<=k;i++)mul.arr[0][i+1]=ncr[k][i];
        for(int i=1;i<=(k+1);i++){
            for(int j=i;j<=(k+1);j++){
                mul.arr[i][j]=ncr[k-i+1][j-i];
            }
        }
        mul=mul^(n-1);
        unsigned int ans=0;
        for(int i=0;i<(k+2);i++)ans+=mul.arr[0][i];
        printf("Case %d: %u\n",z,ans);
        //cout<<"Case "<<z<<": "<<(b*mul.arr[0][0]+a*mul.arr[0][1])%mod[m-1]<<"\n";
    }
    return 0;
}

