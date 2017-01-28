
#include <bits/stdc++.h>

using namespace std;

#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI         vector<int>
#define VVI        vector< VI >
#define VIit       VI::iterator
#define pi        pair<int,int>
#define ui64       unsigned long long int
#define i64        long long int
#define pb(a)      push_back(a)
#define mp         make_pair


#define SI(a)      scanf("%d",&a)
#define Si(a)      scanf("%d",&a)
#define SU(a)      scanf("%u",&a)
#define SHD(a)     scanf("%hd",&a)
#define SHU(a)     scanf("%hu",&a)
#define SLLD(a)    scanf("%lld",&a)
#define SLLU(a)    scanf("%llu",&a)
#define SF(a)      scanf("%f",&a)
#define SLF(a)     scanf("%lf",&a)
#define SC(a)      scanf("%c",&a)
#define SS(a)      scanf("%s",a)
#define read       freopen("in.txt","r",stdin)
#define write      freopen("out.txt","w",stdout)
#define PI         acos(-1.0)
#define eps        1e-9

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define fi          first
#define se          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())

int r , c ;
char G[11][11];
bool visited[11][11] ;
vector<int>ans[11][11] ;

int dirR[] = {  1 , 1 , 2 , 2 , -1 , -1 , -2 , -2  };
int dirC[] = {  2 , -2 , 1 , -1 , 2 , -2 , 1 , -1 };


void bfs(int a , int b ){

        int jump = G[a][b] - '0' ;

        zero( visited ) ;
        queue< pair< pair<int , int > , int > > Q ;
        Q.push(make_pair(make_pair(a,b), 0 ) );
        ans[a][b].pb(0);
        visited[a][b] = 1 ;

        while( !Q.empty() ){

            pair< pair<int , int > , int > src = Q.front() ; Q.pop() ;
            rep( i , 8 ){
                int R = src.first.first + dirR[i] ;
                int C = src.first.second + dirC[i] ;
                if( !visited[R][C] && R >= 0 && R<r && C >= 0 && C<c ){
                    visited[R][C] = 1 ;
                    Q.push( make_pair(make_pair(R , C ) , src.second+1 ) ) ;
                    ans[R][C].pb((int(ceil(double(src.second+1)/(double(jump))))));
                }
            }
        }

}




int main() {
    int cases , caseno = 1 ;
    cin >> cases ;
    while( cases -- ) {

        cin >> r >> c ;
        rep( i , r ) {
            cin >> G[i] ;
        }

        int cnt = 0 ;
        rep( i , r ){
            rep( j , c ){
                if( G[i][j] != '.'){
                    bfs( i , j ) ;
                    cnt ++ ;
                }
            }
        }

        int MAX = numeric_limits<int>::max()-1 ;
        rep( i , r ){
            rep( j , c ) {
                if( ans[i][j].size() == cnt ){
                    int sum = 0 ;
                    rep( k , ans[i][j].size() ){
                        sum += ans[i][j][k] ;
                    }
                    MAX = min( MAX , sum ) ;
                }
            }
        }

        if( MAX != numeric_limits<int>::max()-1 )printf("Case %d: %d\n",caseno++,MAX) ;
        else {
            printf("Case %d: -1",caseno++) ;
        }
    }

    return 0 ;
}
