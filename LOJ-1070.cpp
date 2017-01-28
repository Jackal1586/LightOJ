#include<bits/stdc++.h>
using namespace std;
template<int N> class matrix {
public:
    unsigned long long int arr[N][N];
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
                    ret.arr[i][j]+=(((arr[i][k])*(in.arr[k][j]))) ;
                    ret.arr[i][j];
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
        unsigned long long p,q,n;
        scanf("%llu%llu%llu",&p,&q,&n);
        matrix<2>mul;
        mul.arr[0][0]=p;
        mul.arr[0][1]=-q;
        mul.arr[1][0]=1;
        if(n==0){
            printf("Case %d: 2\n",z);
            continue;
        }if(n==1){
            printf("Case %d: %llu\n",z,p);
            continue;
        }
        if(n==2){
            printf("Case %d: %llu\n",z,p*p-2*q);
            continue;
        }
        mul=mul^(n-1);
        printf("Case %d: %llu\n",z,mul.arr[0][0]*p+mul.arr[0][1]*2);
    }
    return 0;
}

