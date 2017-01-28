#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
char s1[10005],s2[10005];
int ch1[10005],ch2[10005],n,aa[10005],bb[10005];
vector<int>g1[10005],g2[10005];
vector<int>v1,v2;
//bool vis1[10005],vis2[10005];
int dfs(int src){
    if(aa[src]!=-1)return aa[src];
    aa[src]=1;
    for(int i=0;i<g1[src].size();i++){
        aa[src]+=dfs(g1[src][i]);
    }
    return aa[src];
}
int dfs1(int src){
    if(bb[src]!=-1)return bb[src];
    bb[src]=1;
    for(int i=0;i<g2[src].size();i++){
        bb[src]+=dfs1(g2[src][i]);
    }
    return bb[src];
}
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    for(int z=1;z<=t;z++){
        v1.clear();
        v2.clear();
        for(int i=0;i<10002;i++){
            g1[i].clear();
            g2[i].clear();
            ch1[i]=ch2[i]=aa[i]=bb[i]=-1;
        }
        gets(s1);
        gets(s2);
        n=strlen(s1);
        int pr=-1,nd=0,nw=1,x;
        for(int i=0;s1[i];i++){
            if(s1[i]=='1'){
                pr=nd;
                nd=nw;
                ch1[nd]=pr;
                g1[pr].push_back(nd);
                nw++;
            }else{
                nd=pr;
                pr=ch1[pr];
            }
        }
        x=nw;
        pr=-1,nd=0,nw=1;
        for(int i=0;s2[i];i++){
            if(s2[i]=='1'){
                pr=nd;
                nd=nw;
                ch2[nd]=pr;
                g2[pr].push_back(nd);
                nw++;
            }else{
                nd=pr;
                pr=ch2[pr];
            }
        }
        dfs(0);
        dfs1(0);
        for(int i=0;aa[i]!=-1;i++){
            v1.push_back(aa[i]);
            //cout<<v1[i]<<" ";
        }//cout<<endl;
        for(int i=0;bb[i]!=-1;i++){
            v2.push_back(bb[i]);
            //cout<<v2[i]<<" ";
        }//cout<<endl;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        bool f=1;
        int l1=v1.size(),l2=v2.size();
        if(l1!=l2){
            printf("Case %d: Different\n",z);
            continue;
        }
        for(int i=0;i<l1;i++){
            if(v1[i]!=v2[i]){
                f=0;
                break;
            }
        }
        if(f){
            printf("Case %d: Same\n",z);
        }else printf("Case %d: Different\n",z);
    }
    return 0;
}

