#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n,m;
    scanf("%d%d",&n,&m);
    long long int arr[n][m],dp1[n][m],dp2[n][m];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%lld",&arr[i][j]);
        }
    }
    dp1[0][0]=arr[0][0];
    for(int i=1;i<m;i++){
        dp1[0][i]=dp1[0][i-1]+arr[0][i];
        dp2[0][i]=01;
    }
    for(int i=1;i<n;i++){
        dp1[i][0]=dp1[i-1][0]+arr[i][0];
        dp2[i][0]=10;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(dp1[i-1][j]>dp1[i][j-1]){
                dp2[i][j]=10;
                dp1[i][j]=dp1[i-1][j]+arr[i][j];
            }else {
                dp2[i][j]=01;
                dp1[i][j]=dp1[i][j-1]+arr[i][j];
            }
        }
    }
    int x=n-1,y=m-1;
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp2[i][j]<<"  ";
        }cout<<endl;
    }cout<<endl;
    while(x!=0 && y!=0){
        arr[x][y]=0;
        x-=dp2[x][y]/10;
        y-=dp2[x][y]%10;
    }arr[0][0]=0;cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<"  ";
        }cout<<endl;
    }cout<<endl;
    memset(dp2,0,sizeof(dp2));
     dp2[0][0]=0;
    for(int i=m-2;i>=0;i--){
        dp2[n-1][i]=dp2[0][i+1]+arr[0][i];
    }
    for(int i=n-2;i>=0;i--){
        dp2[i][0]=dp1[i+1][0]+arr[i][0];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
                dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+arr[i][j];
        }
    }
    printf("Case %d: %lld \n",z,dp1[n-1][m-1]+dp2[0][0]);
}
return 0;
}
