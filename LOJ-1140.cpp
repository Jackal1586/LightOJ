#include<bits/stdc++.h>
using namespace std ;
int l ;
pair<long long,long long> dp[22][2][2] ;
char str[22] ;
pair<long long,long long> rec( int ii , bool pp , int ld ){
    if( ii == l && ld ) return make_pair(1,1) ;
    else if( ii == l ) return make_pair(1,0);
    if(dp[ii][pp][ld].first!=-1) return dp[ii][pp][ld] ;
    pair<long long,long long> ret = make_pair(0,0);
    pair<long long,long long> tmp ;
    int lim = (pp==0)?(str[ii]-'0'):9;
    for( int i = 0 ; i <= lim ; i++ ){
        tmp = rec( ii+1 , (i<(str[ii]-'0')) || pp , ( !i && ld ) ) ;
        ret.first += tmp.first ;
        ret.second += tmp.second ;
        if( !i && !ld ) ret.second += tmp.first ;
    }
    return dp[ii][pp][ld] = ret ;
}
int main(){
    int t;
    scanf("%d",&t) ;
    for(int z=1;z<=t;z++){
        long long n1 , n2 ;
        scanf("%lld%lld",&n1,&n2) ;
        n1-- ;
        sprintf(str,"%lld",n2 ) ;
        l = strlen( str );
        memset(dp,-1,sizeof(dp));
        pair<long long,long long> ans = rec( 0 , 0 , 1 ) ;
        sprintf(str,"%lld",n1 ) ;
        l = strlen( str );
        memset(dp,-1,sizeof(dp));
        pair<long long,long long> ans1 = rec( 0 , 0 , 1 ) ;
        cout <<"Case " <<z<< ": " << ans.second - ans1.second << "\n" ;
    }
    return 0;
}
