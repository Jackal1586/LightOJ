#include<bits/stdc++.h>
using namespace std;
int nx[1000009],n,m;
char pp[1000009],tt[1000009];
void input(char *s){
    char c=getchar_unlocked();
    while(c<'a' || c>'z'){
        c=getchar_unlocked();
    }
    register int ii=0;
    do{
        s[ii]=c;
        ii++;
        c=getchar_unlocked();
    }while(c>='a' && c<='z');
    s[ii]='\0';
}
void fail(){
    int q=0,k;
    nx[0]=0;
    for(int i=1;i<m;i++){
        while(q>0 && pp[i]!=pp[q]){
            q=nx[q-1];
        }
        if(pp[i]==pp[q])q++;
        //if(pp[i]==pp[q])nx[i]=nx[q];
        nx[i]=q;
    }
}
int match(){
    int q=0,k,ret=0;
    for(int i=0;i<n;i++){
        while(q>0 && tt[i]!=pp[q]){
            q=nx[q-1];
        }
        if(pp[q]==tt[i])q++;
        if(q==m){
            ret++;
            q=nx[q-1];
        }
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        input(tt);
        input(pp);
        //scanf(" %s %s",tt,pp);
        n=strlen(tt);
        m=strlen(pp);
        fail();
        cout<<"Case "<<z<<": "<<match()<<"\n";
    }
    return 0;
}
