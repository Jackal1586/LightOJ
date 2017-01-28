#include <bits/stdc++.h>
using namespace std;
#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)
bool CHECK(int num,int pos){ return num&(1<<(pos)); }
int SET(int &num,int pos){ return num|=(1<<(pos));}
int main()
{
    int t ;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n , m ;
        scanf("%d%d",&n,&m);
        int limit = 0 ;
        for( int i = 1 ; i <= m ; i++ ){
            limit = SET( limit , i );
        }
        list<int>Li;
        for(int i=0;i<n;i++)Li.push_back( i+1 ) ;
        int flag[21] ;
        int fw[21] ;
        memset(flag,0,sizeof(flag));
        memset(fw,0,sizeof(fw));
        int cnt = 0 ;
        int index = 1 ;
        while( 1 ){
            if( index == m+1 )
                index = index % m ;
            if( fw[index] == -1 ){
                if( !Li.empty()){
                    for( list<int>::iterator it = Li.begin() ; it != Li.end() ; it++ ){
                         //cout << *it << endl ;
                        if( !CHECK( flag[*it] , index ) ){
                            fw[index] = *it ;
                            Li.erase( it ) ;
                            break ;
                        }
                    }
                }
            }else{
                int temp = fw[index] ;
                flag[temp] = SET( flag[temp] , index ) ;
                fw[index] = -1 ;
                if( !Li.empty()){
                    for( list<int>::iterator it = Li.begin() ; it != Li.end() ; it++ ){
                        if( !CHECK( flag[*it] , index ) ){
                            fw[index] = *it ;
                            Li.erase( it ) ;
                            break ;
                        }
                    }
                }
                if( flag[temp] != limit ) Li.push_back( temp  ) ;
            }
            cnt ++ ;
            int fg = 1 ;
            for( int i = 1 ; i <= n ; i++ ){
                if( flag[i] != limit ){
                    fg = 0 ;
                    break ;
                }
            }
            if( fg )
                break ;
            index++ ;
        }
        cout<<"Case "<<z<<": "<<5*cnt<<"\n";
    }
    return 0;
}
