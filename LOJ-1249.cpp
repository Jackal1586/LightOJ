#include<bits/stdc++.h>
using namespace std;
int main(){
int t,n;
cin>>t;
for(int l=1;l<=t;l++){
    string name,thief,suffer;
int a,b,c,mx=-1,vol,mn=10000000;
cin>>n;
getchar();
while(n--){
    cin>>name>>a>>b>>c;
    if((a*b*c)>mx){
        mx=a*b*c;
        thief=name;
    }
    if((a*b*c)<mn){
        mn=a*b*c;
        suffer=name;
    }
}
if(mx!=mn){cout<<"Case "<<l<<": "<<thief<<" took chocolate from "<<suffer<<endl;}
else printf("Case %d: no thief\n",l);
}
return 0;
}
