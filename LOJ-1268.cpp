#include<bits/stdc++.h>
using namespace std;
class matrix {
public:
    vector<vector<unsigned int> >arr;
    matrix() {}
    matrix(int N) {
        vector<unsigned int>y;
        for(int i=0; i<N; i++)y.push_back(0);
        for( int i = 0 ; i < N ; i ++ ) {
            arr.push_back(y);
        }
    }
    matrix(int N,vector<vector<unsigned int> >q) {
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
                    //ret.arr[i][j]%=mod ;
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
                ret.arr[i][j]=(arr[i][j]+x.arr[i][j]);//%mod;
            }
        }
        return ret;
    }
};
int jump[55];
int kmp(string s){
    jump[0]=0;
    for(int i=1,q=0;i<(int)s.size();i++){
        while(q>0 && s[i]!=s[q])q=jump[q-1];
        if(s[i]==s[q])q++;
        jump[i]=q;
    }
    return jump[s.size()-1];
}
matrix mul;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        char ss[55];
        long long n;
        scanf("%d",&n);
        scanf(" %s",ss);
        string tt=ss;
        scanf(" %s",ss);
        string s=ss;
        string temp=s+"#";
        mul=matrix(s.size());
        for(int i=0;i<(int)s.size();i++){
            for(int j=0;j<(int)tt.size();j++){
                string ttemp=temp+tt[j];
                int x=kmp(ttemp);
                if(x<s.size())mul.arr[i][x]++;
            }
            temp.push_back(s[i]);
        }
        unsigned int ans=0;
        mul=mul^(n);
        for(int i=0;i<(int)s.size();i++){
            ans+=mul.arr[0][i];
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
