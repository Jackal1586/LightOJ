#include<bits/stdc++.h>
using namespace std;
struct node {
    int tt;
    node *next[4];
    node() {
        tt=0;
        for(int i=0; i<4; i++) {
            next[i]=NULL;
        }
    }
}*root;
char s[55];
long long ans;
void insert() {
    node* pr=root;
    for(int i=0; s[i]; i++) {
        int ii;
        if(s[i]=='A')ii=0;
        else if(s[i]=='C')ii=1;
        else if(s[i]=='G')ii=2;
        else ii=3;
        if(pr->next[ii]==NULL) {
            pr->next[ii]=new node();
        }
        pr=pr->next[ii];
        pr->tt++;
        ans=max(ans,((long long)((i+1)*pr->tt)));
    }
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        root=new node();
        ans=-1;
        int n;
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; i++) {
            gets(s);
            insert();
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

