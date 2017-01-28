#include<bits/stdc++.h>
using namespace std;
int mod;
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
        int a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2;
        scanf("%d%d%d",&a1,&b1,&c1);
        scanf("%d%d%d",&a2,&b2,&c2);
        scanf("%d%d%d",&f0,&f1,&f2);
        scanf("%d%d%d",&g0,&g1,&g2);
        scanf("%d",&mod);
        //scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2,&f0,&f1,&f2,&g0,&g1,&g2,&mod);
        matrix<6>mul;
        mul.arr[0][0]=a1%mod;
        mul.arr[0][1]=b1%mod;
        mul.arr[0][5]=c1%mod;
        mul.arr[1][0]=mul.arr[2][1]=mul.arr[4][3]=mul.arr[5][4]=1;
        mul.arr[3][3]=a2%mod;
        mul.arr[3][4]=b2%mod;
        mul.arr[3][2]=c2%mod;
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",z);
        while(q--){
            int n;
            scanf("%d",&n);
            if(n==0){
                printf("%d %d\n",f0%mod,g0%mod);
                continue;
            }if(n==1){
                printf("%d %d\n",f1%mod,g1%mod);
                continue;
            }if(n==2){
                printf("%d %d\n",f2%mod,g2%mod);
                continue;
            }
            if(n==3){
                printf("%d %d\n",((a1*f2)%mod+(b1*f1)%mod+(c1*g0)%mod)%mod,((a2*g2)%mod+(b2*g1)%mod+(c2*f0)%mod)%mod);
                continue;
            }matrix<6>ans;
            ans=mul;
            ans=ans^(n-2);
            printf("%d %d\n",((ans.arr[0][0]*f2)%mod+(ans.arr[0][1]*f1)%mod+(ans.arr[0][2]*f0)%mod+(ans.arr[0][3]*g2)%mod+(ans.arr[0][4]*g1)%mod+(ans.arr[0][5]*g0)%mod)%mod,((ans.arr[3][0]*f2)%mod+(ans.arr[3][1]*f1)%mod+(ans.arr[3][2]*f0)%mod+(ans.arr[3][3]*g2)%mod+(ans.arr[3][4]*g1)%mod+(ans.arr[3][5]*g0)%mod)%mod);
        }
    }
    return 0;
}

