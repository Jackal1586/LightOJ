#include<bits/stdc++.h>
using namespace std;
vector<pair<long long , int > >V ;
long long n,k;
bool vis[1000010];
long long sz,prime[78500];
void sieve() {
    vis[0]=vis[1]=true;
    prime[sz++]=2;
    for(long long i=4; i<=1000000; i+=2)vis[i]=true;
    for(long long i=3; i<=1000000; i+=2) {
        if(!vis[i]) {
            prime[sz++]=i;
            for(long long j=i*i; j<=1000000; j+=(i<<1)) {
                vis[j]=true;
            }
        }
    }
}
void PF(long long n) {
    int lim = int(sqrt(n)) ;
    for(long long i=0; i<sz && prime[i]<=lim; i++) {
        if( n%prime[i] == 0 ) {
            int freq = 0 ;
            while( n%prime[i] == 0 ) {
                n/=prime[i] ;
                freq++ ;
            }
            V.push_back(make_pair(prime[i],freq)) ;
            lim=sqrt(n);
        }
    }
    if( n > 1 ) {
        V.push_back(make_pair(n , 1 ) ) ;
    }
}
//long long bfs() {
//
//    queue< pair<long long ,int>  > Q;
//    Q.push( make_pair(1 , 0 ));
//    long long cnt = 0 ;
//
//    while( !Q.empty() ) {
//
//        pair<long long , int > src = Q.front() ;
//        Q.pop() ;
//
//        if( src.second==V.size()) {
//            if(src.first<k)cnt++;
//            continue;
//        }
//
//        long long p = 1 ;
//        for(int  i = 0 ; i < V[src.second].second; i++ ) {
//            if((p*src.first)<k) {
//                Q.push(make_pair(p*src.first,src.second+1));
//            } else break;
//            p*=V[src.second].first ;
//        }
//    }
//    return cnt ;
//}
long long int dfs(long long int ans , int idx){
   if( idx == V.size() ){
        if( ans >= k && ans<sqrt(n) )return 1 ;
        else return 0 ;
   }
    long long int p = 1,r = 0 ;
    for( int i = 0 ; i <= V[idx].second ; i++ ){
        r +=dfs(ans*p,idx+1) ;
        p*=V[idx].first ;
    }
    return r ;
}
int main() {
    sieve();
    for(int i=0;i<25;i++)cout<<prime[i]<<endl;
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%lld%lld",&n,&k);
        PF(n) ;
        printf("Case %d: %lld\n",z,dfs(1,0));
        V.clear() ;
    }
    return 0;
}
