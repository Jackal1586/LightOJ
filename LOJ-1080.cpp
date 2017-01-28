#include<bits/stdc++.h>
using namespace std;
bool arr[100010];
int tree[100010],limit;
void update(int i,int v) {
    while(i<=limit) {
        tree[i]+=v;
        i+=(i&(-i));
    }
}
int read(int i) {
    int sum=0;
    while(i>0) {
        sum+=tree[i];
        i-=(i&(-i));
    }
    return sum;
}
int main() {
    char s[100010];
    int t;
    scanf("%d",&t);
    getchar();
    for(int z=1; z<=t; z++) {
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        scanf("%s",s);
        limit=strlen(s);
        for(int i=0; s[i]; i++)arr[i+1]=(s[i]-48);
        int k;
        scanf("%d",&k);
        printf("Case %d:\n",z);
        while(k--) {
            char c,c1;
            int a,b;
            getchar();
            scanf("%c%c%d",&c,&c1,&a);
            if(c=='I') {
                scanf("%d",&b);
                update(a,1);
                update(b+1,-1);
            } else printf("%d\n",(arr[a]^(read(a)&1)));
        }
    }
    return 0;
}
