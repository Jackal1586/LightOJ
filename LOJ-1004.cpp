#include<bits/stdc++.h>
using namespace std;
//template<class T>T mx(T a,T b){if(a==0)return b;if(b==0)return a;return (a>b)?a:b;}
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long int n;
    scanf("%lld",&n);
    long long int arr[2*n-1][n],sol[2*n-1][n];
    memset(arr,0,sizeof(arr));
    memset(sol,0,sizeof(sol));
    for(int i=0;i<n;i++)for(int j=0;j<=i;j++)scanf("%lld",&arr[i][j]);
    for(int i=n;i<(2*n-1);i++)for(int j=0;j<(2*n-i-1);j++)scanf("%lld",&arr[i][j]);
    sol[0][0]=arr[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0)sol[i][j]+=(sol[i-1][j]+arr[i][j]);
            else sol[i][j]+=(max(sol[i-1][j-1],sol[i-1][j])+arr[i][j]);
        }
    }
    for(int i=n;i<(2*n-1);i++)for(int j=0;j<(2*n-i-1);j++)sol[i][j]+=(max(sol[i-1][j+1],sol[i-1][j])+arr[i][j]);
    printf("Case %d: %lld\n",z,sol[2*(n-1)][0]);
}
return 0;}
