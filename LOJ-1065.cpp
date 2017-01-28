#include<bits/stdc++.h>
using namespace std;
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
                    ret.arr[i][j]+=(arr[i][k])*(in.arr[k][j]) ;
                    ret.arr[i][j]%=10000 ;
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
        int a,b,n,m;
        int mod[]={10,100,1000,10000};
        scanf("%d%d%d%d",&a,&b,&n,&m);
        matrix<2>mul;
        mul.arr[0][0]=mul.arr[0][1]=mul.arr[1][0]=1;
        mul=mul^(n-1);
        printf("Case %d: %d\n",z,(b*mul.arr[0][0]+a*mul.arr[0][1])%mod[m-1]);
        //cout<<"Case "<<z<<": "<<(b*mul.arr[0][0]+a*mul.arr[0][1])%mod[m-1]<<"\n";
    }
    return 0;
}

