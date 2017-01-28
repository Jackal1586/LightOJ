#include<bits/stdc++.h>
using namespace std;
struct trie {
    int cnt, next[10],l;
};
trie tree[100005];
int last;
bool flag;
void insert(char *s,int len) {
    int t,i,j;
    for(i=j=0; s[i]; i++) {
        t=s[i]-'0';
        if(tree[j].next[t]==-1) {
            tree[j].next[t]= ++last;
            memset(tree[last].next,-1,10*sizeof(int));
            tree[last].cnt=0;
            tree[last].l=0;
        }
        j=tree[j].next[t];
        tree[j].cnt++;
        if(i+1==len) {
            tree[j].l=1;
        }
        if(tree[j].l==1 && tree[j].cnt==2)
            flag=1;
    }
}
int main() {
    int i,n,t,cas=1;
    char a[20];
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        last=flag=0;
        memset(tree[0].next,-1,10*sizeof(int));
        scanf("%d",&n);
        for(i=0; i<n; i++) {
            scanf("%s",&a);
            if(flag==0)
                insert(a,strlen(a));
        }
        if(flag==0)cout<<"Case "<<z<<": YES\n";
        else cout<<"Case "<<z<<": NO\n";
    }
    return 0;
}
