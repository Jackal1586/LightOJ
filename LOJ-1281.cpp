#include<bits/stdc++.h>
using namespace std ;
#define inf (1<<28)
struct node{
    int u , w ;
    bool t ;
    node(int a, int c ,bool d ){
        u = a , w=c , t = d ;
    }
} ;
struct nd{
    int u , w ;
    int takesofar ;
    nd(int a, int c ,int d ){
        u = a , w=c , takesofar = d ;
    }
    bool operator<(const nd &b)const
    {
        if( w==b.w )return takesofar < b.takesofar ;
        return (w>b.w);
    }
} ;
vector<node> g[10001] ;
int vis[10001][12];
int n , m , k , d ;
int bfs(){
    priority_queue< nd > q ;
    q.push( nd( 0 , 0 , 0 )) ;
    vis[0][0] = 0 ;
    while( !q.empty() ){
        nd src = q.top() ;
        q.pop() ;
        for( int i = 0 ; i < g[src.u].size() ; i++ ){
            int dest = g[src.u][i].u ;
            int cost = g[src.u][i].w ;
            if(  src.takesofar+int(g[src.u][i].t)<=d  && vis[dest][src.takesofar+int(g[src.u][i].t)]>vis[src.u][src.takesofar]+cost) {
                vis[dest][src.takesofar+int(g[src.u][i].t)] = vis[src.u][src.takesofar]+cost ;
                q.push( nd(dest , vis[dest][src.takesofar+int(g[src.u][i].t)] , src.takesofar+int(g[src.u][i].t)) ) ; ;
            }
        }
    }
    int ret = inf ;
    for( int i = 0 ;i <= d ; i++ ){
        ret = min( ret , vis[n-1][i] ) ;
    }
    return ret ;
}
int main() {
    int t ;
    scanf("%d",&t ) ;
    for(int z=1;z<=t;z++) {
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for( int i = 0 ;i <= n ; i++ ){
            g[i].clear() ;
            for( int j = 0 ; j <= d ; j++ ){
                vis[i][j] = inf ;
            }
        }
        int u , v , w ;
        for( int i = 0 ; i < m; i++ ) {
            scanf("%d%d%d",&u,&v,&w) ;
            g[u].push_back( node( v , w , 0 ));
        }
        for( int i = 0 ; i < k; i++ ) {
            scanf("%d%d%d",&u,&v,&w) ;
            g[u].push_back( node( v , w , 1 ));
        }
        int ans = bfs() ;
        if( ans != inf )cout << "Case "<<z<<": "<< ans<<"\n" ;
        else cout << "Case "<<z<<": "<< "Impossible\n" ;
    }
    return 0 ;
}
