#include<bits/stdc++.h>
using namespace std;
int nxt[2000020];
char s[1000010],t[1000010],ch[5];
int main(){
    int T,lim,q,m;
    scanf("%d",&T);
    getchar();
    ch[0]='^';
    ch[1]='\0';
    for(int z=1;z<=T;z++){
        gets(s);
        lim=strlen(s);
        for(int i=0,j=lim-1;i<lim;i++,j--){
            t[j]=s[i];
        }
        //cout<<t<<endl;
        t[lim]='\0';
        strcat(t,ch);
        strcat(t,s);
        memset(nxt,0,sizeof(nxt));
        q=0;
        m=(lim<<1)+1;
        //cout<<m<<endl;
        for(int i=1;i<m;i++){
            while(q>0 && t[i]!=t[q]){
                q=nxt[q-1];
            }
            if(t[i]==t[q])q++;
            nxt[i]=q;
        }
        //cout<<t<<endl;
        /*cout<<endl;
        for(int i=0;i<m;i++){
            cout<<nxt[i]<<" ";
        }cout<<endl;*/
        cout<<"Case "<<z<<": "<<m-1-nxt[m-1]<<"\n";
    }
    return 0;
}

