#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n;
    scanf("%d",&n);
    bool flag=0;
    int x,cnt=0;
    for(int i=0;i<40;i++){
        if(n&(1<<i)){
            flag=1;
            cnt++;
        }else if(flag && (!(n&(1<<i)))){
            x=i;
            break;
        }
    }cnt--;
    n=(n|(1<<(x)));
    n=(n&(~((1<<(x))-1)));
    n=n|((1<<cnt)-1);
    cout<<"Case "<<z<<": "<<n<<"\n";
}
return 0;
}
