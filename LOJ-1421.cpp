#include<bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
inline void LisNlogK(int* Sequence,int n,int* L) {
    int i;
    int I[n+1];
    I[0] = -inf;
    for( i = 1; i <= n; i++ )I[i] = inf;
    int LisLength = 0;
    for( i = 0; i < n; i++ ) {
        int low, high, mid;
        low = 0;
        high = LisLength;
        while( low <= high ) {
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )low = mid + 1;
            else high = mid - 1;
        }
        I[low] = Sequence[i];
        if( LisLength < low )
            LisLength = low;
	L[i]=LisLength;
    }
    return ;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	int n;
	scanf("%d",&n);
	int arr1[n+1],arr2[n+1],l1[n+1],l2[n+1];
	for(int i=0;i<n;i++){
		scanf("%d",&arr1[i]);
		arr2[n-i-1]=arr1[i];
		l1[i-1]=l1[i]=l2[i-1]=l2[i]=0;
	}
	LisNlogK(arr1,n,l1);
	LisNlogK(arr2,n,l2);
	int mx=-1;
	for(int i=0;i<n;i++){
		mx=max(mx,min(l1[i],l2[n-i]));
	}
	cout<<"Case "<<z<<": "<<2*mx-1<<"\n";
    }
    return 0;
}
