
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)scanf("%d",&arr[i]);
        sort(arr,arr+n);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int low=j+1,high=n-1;
                while((high-low)>=4){
                    int mid=(low+high+1)/2;
                    if((arr[i]+arr[j])<=arr[mid])high=mid;
                    else low=mid+1;
                }for(;low<=high;low++){
                    if((arr[i]+arr[j])<=arr[low])break;
                }cnt+=(low-j-1);
            }
        }
        cout<<"Case "<<z<<": "<<cnt<<"\n";
    }
    return 0 ;
}
