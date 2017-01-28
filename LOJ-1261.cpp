#include <bits/stdc++.h>
using namespace std;
int posarr[30+1][30+1] ;
int negarr[30+1][30+1] ;
int sol[30+1] ;
int per[30+1] ;
int sim[30+1] ;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n , m , k ;
        scanf("%d%d%d",&n,&m,&k);
        memset(posarr,0,sizeof(posarr));
        memset(negarr,0,sizeof(negarr));
        int p ;
        int flg = 0 ;
        for(int i=1;i<=n;i++){
            for(int j=0;j<k;j++){
                scanf("%d",&p);
                if( p >=0 ) posarr[i][p] = 1 ;
                else negarr[i][-p] = 1 ;
            }
            sol[i] = 0  ;
        }
        for(int i=1;i<=m;i++)sim[i] = 0 ;
        int q ;
        scanf("%d",&p);
        for(int i=0;i<p;i++){
            scanf("%d",&q);
            sim[q] = 1 ;
        }
        for(int i=1;i<=m;i++){
            if( sim[i] == 1 ){
                for(int j=1;j<=n;j++){
                    if( posarr[j][i] == 1 )sol[j] = 1 ;
                }
            }
            else{
                for(int j=1;j<=n;j++){
                    if( negarr[j][i] == 1 ) sol[j] = 1 ;
                }
            }
        }
        int flag = 0 ;
        for(int i=1;i<=n;i++){
            if( sol[i] == 0 )flag = 1 ;
        }
        if( !flag )cout<<"Case "<<z<<": Yes\n";
        else cout<<"Case "<<z<<": No\n";
    }
    return 0;
}

