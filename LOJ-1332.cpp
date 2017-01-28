#include<bits/stdc++.h>
using namespace std;
template<int N> class matrix {
public:
    unsigned  arr[N][N];
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
int main(){
    int x=0,y=0;
    matrix<36>mul;
    for(int i=0;i<10;i++){
        for(int j=i+2;j<10;j++){
            y=0;
            for(int k=0;k<10;k++){
                for(int l=k+2;l<10;l++){
                    if(abs(i-k)<=1 || abs(i-l)<=1 || abs(j-k)<=1 || abs(j-l)<=1);
                    else mul.arr[x][y]=1;
                    y++;
                }
            }
            x++;
        }
    }
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        matrix<36>ans;
        ans=mul^(n-1);
        unsigned cnt=0;
        /*cout<<"\n\nmatrix print\n\n";
            for(int i=0;i<36;i++){
                for(int j=0;j<36;j++){
                    cout<<mul.arr[i][j]<<" ";
                }cout<<endl;
        }cout<<"\n\nend\n\n";*/
        for(int i=0;i<36;i++){
            for(int j=0;j<36;j++){
                cnt+=ans.arr[i][j];
            }
        }
        cout<<"Case "<<z<<": "<<cnt<<"\n";
    }
    return 0;
}

