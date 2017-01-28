#include<bits/stdc++.h>
using namespace std;
char s[105];
int vis[50004],wordID[50004];
map<string,int>mp;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        mp.clear();
        memset(vis,0,sizeof(vis));
        int wordcnt=0,tot=0;
        while(scanf(" %s",s)==1 && strcmp(s,"END")!=0){
            for(int i=0;s[i];i++){
                if(!isalpha(s[i]))s[i]=' ';
            }
            stringstream ss;
            ss<<s;
            string x;
            while(ss>>x) {
                //cout<<x<<"\n";
                if(mp.find(x)==mp.end()) {
                    wordcnt++;
                    mp[x]=wordcnt;
                }
                wordID[tot]=mp[x];
                tot++;
            }
        }
        int ii=0,jj=0,x=0,y=tot-1,cnt=0;
        for(;ii<tot && jj<tot;jj++){
            vis[wordID[jj]]++;
            if(vis[wordID[jj]]==1)cnt++;
            while(ii<jj && vis[wordID[ii]]>1){
                vis[wordID[ii]]--;
                ii++;
            }
            if(cnt==wordcnt && jj-ii<y-x){
                x=ii,y=jj;
            }
        }
        cout<<"Case "<<z<<": "<<1+x<<" "<<1+y<<"\n";
    }
    return 0;
}

