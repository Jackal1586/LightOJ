#include<bits/stdc++.h>
using namespace std;
int phi[1000105];
int ans[1000105];
void PHI(){
    phi[1]=0;
    for(int i=2;i<=1000100;i++)phi[i]=i;
    for(int i=2;i<=1000100;i++){
		if(phi[i]==i){
			phi[i]--;
			for(int j=i+i;j<=1000100;j+=i){
				phi[j]=(phi[j]/i)*(i-1);
			}
		}
    }
    int xx=1;
    for(int i=1;i<=1000100;i++){
		if(phi[i]>=xx){
			ans[xx++]=i;
			i--;
		}
    }
    return;
}
int main() {
    int t;
    PHI();
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        long long cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		cnt+=ans[a];
        }
        cout<<"Case "<<z<<": "<<cnt<<" Xukha\n";
        //printf("Case %d: %lld Xukha\n",z,cnt);
    }
    return 0;
}
