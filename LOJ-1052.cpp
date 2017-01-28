#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
class matrix {
public:
    vector<vector<long long int> >arr;
    matrix() {}
    matrix(int N) {
        vector<long long int>y;
        for(int i=0; i<N; i++)y.push_back(0);
        for( int i = 0 ; i < N ; i ++ ) {
            arr.push_back(y);
        }
    }
    matrix(int N,vector<vector<long long> >q) {
        //vector<long long int>y;
        for( int i = 0 ; i < N ; i ++ ) {
            arr.push_back(q[i]);
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
                    ret.arr[i][j]%=mod ;
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
                ret.arr[i][j]=(arr[i][j]+x.arr[i][j])%mod;
            }
        }
        return ret;
    }
};
void calc(long long a1,long long b1,long long c1,long long a2,long long b2,long long c2,long long&x,long long&y) {
    long long dx=(c1*b2-c2*b1);
    long long dy=(a1*c2-a2*c1);
    long long d=(a1*b2-a2*b1);
    if(d==0) {
        x=-1,y=-1;
        return;
    }
    if(dx%d!=0 || dy%d!=0) {
        x=-1,y=-1;
        return;
    }
    x=dx/d,y=dy/d;
    if(x<0 || y<0) {
        x=-1,y=-1;
        return;
    }
    x%=mod,y%=mod;
    return;
}
long long _calc(matrix aa,long long xx,long long yy) {
    return ((aa.arr[0][0]*xx)%mod+(aa.arr[0][1]*yy)%mod)%mod;
}
int main() {
    int t;
    scanf("%d",&t);
    vector<long long int>w;
    w.push_back(1);
    w.push_back(1);
    vector<vector<long long int> >q;
    q.push_back(w);
    w.pop_back();
    w.push_back(0);
    q.push_back(w);
    for(int z=1; z<=t; z++) {
        long long n,x,m,y,k;
        scanf("%lld%lld%lld%lld%lld",&n,&x,&m,&y,&k);
        if(n>m) {
            swap(n,m);
            swap(x,y);
        }
        matrix aa(2,q),bb(2,q),cc(2,q);
        aa=aa^(n-1);
        bb=bb^(m-1);
        long long a1,a2,b1,b2,c1,c2,xx,yy;
        a1=aa.arr[0][0],b1=aa.arr[0][1],c1=x;
        a2=bb.arr[0][0],b2=bb.arr[0][1],c2=y;
        calc(a1,b1,c1,a2,b2,c2,xx,yy);
        if(x<0 || y<0) {
            cout<<"Case "<<z<<": Impossible\n";
            continue;
        }
        cc=cc^(k-1);
        if(_calc(cc,xx,yy)<=0 || yy>xx) {
            cout<<"Case "<<z<<": Impossible\n";
            continue;
        }
        cout<<"Case "<<z<<": "<<_calc(cc,xx,yy)<<"\n";
    }
    return 0;
}

