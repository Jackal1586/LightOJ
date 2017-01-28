#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        int w[n],b,a=0;
        for(int i=0;i<n;i++)scanf("%d",&w[i]);
        for(int i=0;i<n;i++){
            scanf("%d",&b);
            a^=(b-w[i]-1);
        }
        if(a)cout<<"Case "<<z<<": white wins\n";
        else cout<<"Case "<<z<<": black wins\n";
    }
    return 0;
}

