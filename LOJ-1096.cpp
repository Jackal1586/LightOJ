#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
template<int N> class matrix {
public:
    int  arr[N][N];
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
                    ret.arr[i][j]+=(((arr[i][k])*(in.arr[k][j]))%mod) ;
                    ret.arr[i][j]%=mod ;
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
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n,a,b,c;
        scanf("%d%d%d%d",&n,&a,&b,&c);
        if(n<3){
            printf("Case %d: 0\n",z);
            continue;
        }if(n==3){
            printf("Case %d: %d\n",z,c%mod);
            continue;
        }
        matrix<4>mul;
        mul.arr[0][0]=a%mod;
        mul.arr[0][2]=b%mod;
        mul.arr[0][3]=1;
        mul.arr[1][0]=1;
        mul.arr[2][1]=1;
        mul.arr[3][3]=1;
        mul=mul^(n-2);
        c%=mod;
        printf("Case %d: %d\n",z,(mul.arr[0][3]*c)%mod);
    }
    return 0;
}

