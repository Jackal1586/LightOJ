#include<bits/stdc++.h>
using namespace std;
char t[50004],p[50004];
int jump[50004],a[50004],tl,pl,b[50004],temp[50004];
void kmpPreprocess(){
    jump[0]=0;
    temp[0]=1;
    for(int i=1,q=0;i<pl;i++){
        while(q>0 && p[i]!=p[q])q=jump[q-1];
        if(p[i]==p[q])q++;
        jump[i]=q;
        if(q>0)temp[i]=temp[q-1]+1;
        else temp[i]=1;
    }
    return;
}
void kmp(){
    kmpPreprocess();
    for(int i=0,q=0;i<tl;i++){
        while(q>0 && t[i]!=p[q])q=jump[q-1];
        if(t[i]==p[q])q++;
        if(q==pl)q=jump[q-1];
        if(q>0)a[i]=temp[q-1];
        else a[i]=0;
    }
    return;
}
int main(){
    int tt;
    scanf("%d",&tt);
    for(int z=1;z<=tt;z++){
        scanf(" %s %s",t,p);
        tl=strlen(t);
        pl=strlen(p);
        kmp();
        for(int i=0;i<tl;i++)b[i]=a[tl-i-1];
        reverse(t,t+tl);
        reverse(p,p+pl);
        kmp();
        long long ans=0;
        for(int i=0;i+1<tl;i++){
            ans+=((long long)(a[i]*b[i+1]));
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

