#include<bits/stdc++.h>
using namespace std;
char s[22];
unsigned long long n,l,f[21],frq[27];
void fact(){
        f[0]=1;
        for(unsigned long long i=1;i<=20;i++)f[i]=i*f[i-1];
        return;
}
void path(int mask,int ii,unsigned long long lim){
        if(ii==l)return;
        if(lim==1){
                for(int i=0;i<l;i++){
                        if(!(mask&(1<<i)))cout<<s[i];
                }return;
        }
        unsigned long long x=f[l-ii-1];
        int mark=0;
        for(int i=0;i<l;i++){
                if(!(mask&(1<<i)) && !(mark&(1<<i))){
                        x/=f[frq[s[i]-'a']];
                        mark|=(1<<i);
                }
        }
        unsigned long long a=lim/x;
        mark=0;
        int p=0;
        if((a*x)==lim){
                for(int i=l-1;i>=0;i--){
                        if(!(mask&(1<<i))){
                                cout<<s[i];
                        }
                }
                return;
        }
        for(int i=0;i<l;i++){
                if(!(mask&(1<<i))){
                        if(p==a){
                                cout<<s[i];
                                path(mask|(1<<i),ii+1,lim-a*x);
                                return;
                        }
                        p++;
                }
        }
        return;
}
int main() {
    int t;
    fact();
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        getchar();
        scanf("%s %llu",s,&n);
        l=strlen(s);
        sort(s,s+l);
        memset(frq,0,sizeof(frq));
        for(int i=0;i<l;i++)frq[s[i]-'a']++;
        unsigned long long x=f[l];
        for(int i=0;i<26;i++)x/=f[frq[i]];
        if(n>x){
                cout<<"Case "<<z<<": Impossible\n";
                continue;
        }
        path(0,0,n);
        puts("");
    }
    return 0;
}
