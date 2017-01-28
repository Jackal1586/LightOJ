#include<bits/stdc++.h>
using namespace std;
int arr[1000000] ;
int main()
{
   int cases , caseno =1  ;
   scanf("%d\n",&cases ) ;
   while( cases -- ){

        int  n , p  ;
        scanf("%d",&n) ;
        for(int i = 0 ; i< n ; i++ ){
            scanf("%d" , &arr[i] ) ;
        }
        sort( arr , arr + n ) ;

        long long int ans = 0 ;

        for( int i = 0 ; i < n ;  ){
            int p = arr[i] ;
            int j = i+1 ;
            int cnt = 1 ;
            while( arr[j]== p && j < n )cnt ++ , j++;
            //cout << cnt << endl ;
            ans += (long long int )ceil((double)cnt/(double)(p+1))*(p+1);
            i = j ;
        }
        printf("Case %d: %lld\n",caseno++ , ans ) ;

   }
}
