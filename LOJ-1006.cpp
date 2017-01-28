#include<bits/stdc++.h>
using namespace std;
int arr[10000+10];
int a, b, c, d, e, f;
#define MAX 10000007
int fn( int n )
{
    if(n<6)return arr[n];
    for(int i=6; i<=n; i++) {
        arr[i]=((arr[i-1]%MAX+arr[i-2]%MAX+arr[i-3]%MAX+arr[i-4]%MAX+arr[i-5]%MAX+arr[i-6]%MAX)%10000007);
    }
    return arr[n];
}
int main()
{
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
       // for(int i=0; i<=(10000+5); i++)arr[i]=-1;
        scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
