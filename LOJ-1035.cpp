#include<bits/stdc++.h>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109};
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n;
    map<int,int>mp;
    scanf("%d",&n);
    for(int i=0;prime[i]<=n && i<25;i++){
        int m=n;
        while(m){
            mp[prime[i]]+=(m/prime[i]);
            m/=prime[i];
        }
    }
    printf("Case %d: %d = ",z,n);
    for(map<int,int>::iterator i=mp.begin();i!=mp.end();i++){
        if(i->first==2){
            printf("%d (%d)",i->first,i->second);
        }else printf(" * %d (%d)",i->first,i->second);
    }puts("");
}
return 0;
}
