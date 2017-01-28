#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n;
        scanf("%d",&n);
        int arr1[n],arr2[n];
        bool vis1[n],vis2[n];
        for(int i=0; i<n; i++) {
            scanf("%d",&arr1[i]);
            vis1[i]=false;
        }
        for(int i=0; i<n; i++) {
            scanf("%d",&arr2[i]);
            vis2[i]=false;
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);
        int sum=0;
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=0; j--) {
                if(!vis2[j]) {
                    if(arr2[j]<arr1[i]) {
                        vis2[j]=true;
                        sum+=2;
                        vis1[i]=true;
                        break;
                    }
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(!vis1[i]) {
                for(int j=n-1; j>=0; j--) {
                    if(!vis2[j] && arr1[i]==arr2[j]) {
                        sum++;
                        vis1[i]=true;
                        vis2[j]=true;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n",z,sum);
    }
    return 0;
}

