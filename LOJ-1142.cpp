#include<bits/stdc++.h>
using namespace std;
class matrix {
public:
    vector<vector<int> >arr;
    matrix(){}
    matrix(int N) {
        vector<int>y;
        for( int i = 0 ; i < N ; i ++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                y.push_back(0);
            }
            arr.push_back(y);
        }
    }
    matrix operator *(const matrix &in) {
        matrix ret ;
        int N=this->arr.size();
        ret=matrix(N);
        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < N ; j++ )
                for( int k = 0 ; k < N ; k++ ) {
                    ret.arr[i][j]+=(arr[i][k])*(in.arr[k][j]) ;
                    ret.arr[i][j]%=10 ;
                }
        }
        return ret ;
    }
    matrix operator ^( long long int POW) {
        matrix ret;
        int N=this->arr.size();
        ret=matrix(N);
        for( int i = 0 ; i < N ; i++ ) {
            ret.arr[i][i] = 1 ;
        }
        matrix ME = *this ;
        while( POW ) {
            if( POW&1 ) {
                ret = ret * ME ;
            }
            ME = ME * ME ;
            POW >>= 1 ;
        }
        return ret ;
    }
    matrix operator +(const matrix &x) {
        matrix ret;
        int N=this->arr.size();
        ret=matrix(N);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                ret.arr[i][j]=(arr[i][j]+x.arr[i][j])%10;
            }
        }
        return ret;
    }
};
matrix rec(matrix a,long long k,int n) {
    matrix b=matrix(n),c=b,d=c,e=d,f=e,ret=f,g=f,h=g;
    for(int i=0; i<n; i++) {
        ret.arr[i][i]=1;
    }
    if(k==0)return ret;
    if(k==1)return a;
    b=a^(k/2);
    c=ret+b;
    d=rec(a,k/2,n);
    e=c*d;
    if(k&1) {
        f=a^k;
        g=f+e;
        return g;
    }
    return e;
}
int main() {
    int t;
    int n;
    long long k;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%lld",&n,&k);
        matrix mul;
        mul=matrix(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d",&mul.arr[i][j]);
            }
        }
        cout<<"Case "<<z<<":\n";
        //mul=mul*mul*mul;
        mul=rec(mul,k,n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<mul.arr[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
/**
100
10 1000000000
1 0 0 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0
1 0 0 1 0 0 0 0 0 0
1 0 0 0 1 0 0 0 0 0
1 0 0 0 0 1 0 0 0 0
1 0 0 0 0 0 1 0 0 0
1 0 0 0 0 0 0 1 0 0
1 0 0 0 0 0 0 0 1 0
1 0 0 0 0 0 0 0 0 1
**/
