#include<bits/stdc++.h>
using namespace std ;

int n , m ;
vector<int>G[20001] ;
vector<int>GR[20001] ;
int visited[20001] ;
int I[20001] , O[20001] , C[20001] ;
int scc = 0 ;
stack<int> RPost ;


void dfs( int node ) {
    visited[node] = 1 ;
    for( int i = 0 ; i < G[node].size() ; i++ ) {
        if(visited[G[node][i]] == 0 ) {
            dfs( G[node][i] ) ;
        }
    }
    RPost.push( node ) ;
}

void dfs2( int node ) {
    visited[node] = 1 ;
    for( int i = 0 ; i < GR[node].size() ; i++ ) {
        if( !visited[GR[node][i]] ) {
            dfs2( GR[node][i] ) ;
        }
    }
    C[node] = scc ;
}

int main() {

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        scanf("%d%d",&n,&m ) ;
        for( int i = 0 ; i < m ; i++ ) {
            int u , v ;
            scanf("%d%d",&u,&v) ;
            G[u].push_back( v ) ;
            GR[v].push_back( u ) ;
        }

        for( int i  = 1 ; i <= n ; i++ ) {
            if( !visited[i] ) {
                dfs( i ) ;
            }
        }

        scc = 0 ;
        for( int i = 1 ; i <= n ; i++ )visited[i] = 0 ;

//        for( int i = 0 ; i < RPost.size() ; i++ )cout << RPost[i] << " " ;
//        cout << "\n" ;
//        cout << *(RPost.end()-1)<<endl ;

        while( !RPost.empty() ) {
            if( !visited[RPost.top()] ) {
                scc++ ;
                dfs2( RPost.top() ) ;
            }
            RPost.pop();
        }

        if( scc == 1 ) {
            printf("Case %d: 0\n",caseno++ ) ;
        } else {

            for( int i = 1 ; i <= n ; i++ ) {
                for( int j = 0 ; j < G[i].size() ; j++ ) {
                    if( C[i] != C[G[i][j]] ) {
                        I[C[G[i][j]]]++;
                        O[C[i]]++;
                    }
                }
            }

            int t1 ,t2 ;
            t1 = t2 = 0 ;

            for( int i = 1 ; i <= scc ; i++ ) {

                if( !I[i] )t1 ++ ;
                if( !O[i] )t2 ++ ;

            }

            printf("Case %d: %d\n",caseno ++ ,max( t1, t2 ) )  ;
        }
        for( int i = 1 ; i <= n ; i++ ) {
            G[i].clear() ;
            GR[i].clear() ;
            visited[i] = 0 ;
            I[i] = 0 ;
            O[i] = 0 ;
            C[i] = 0 ;
        }

    }

    return 0 ;

}
