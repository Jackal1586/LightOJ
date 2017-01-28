#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long int n;
    bool sign=0;
    scanf("%lld",&n);
    if(n<0){n*=-1;sign=1;}
    long long int m,cnt,lim=sqrt(n);
    bool flag=0;
    for(int i=2;i<=lim;i++){
        m=n,cnt=0;
        while(m%i==0){
            cnt++;
            m/=i;
        }if(m==1){
            if(sign && !(cnt&1)){
                while(!(cnt&1))cnt/=2;
            }
            cout<<"Case "<<z<<": "<<cnt<<"\n";
            flag=1;
            break;
        }
    }if(!flag){
        cout<<"Case "<<z<<": 1\n";
    }
}
return 0;
}

