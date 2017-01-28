#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
char s[50];
scanf("%d",&t);
getchar();
for(int l=1;l<=t;l++){
    gets(s);
    int i=0,k=(strlen(s)-1),j=k;
    while(s[i]==s[j] && i<=k && j>=0){i++,j--;}
    if(i>k && j==-1)printf("Case %d: Yes\n",l);
    else printf("Case %d: No\n",l);
}
return 0;
}
