#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define pi 2*acos(0.0)
inline int b2d(char *s)
{
    int b=0,a=strlen(s);
    for(int i=a-1;i>=0;i--)
        b+=((s[i]-48)*pow(2,i));
    return b;
}
int main()
{
    int a[4],t;
    char s[100];
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
        getchar();
        scanf("%s",s);
        int flag=1,l=0;
        for(int j=0;j<4;j++)
        {
            int b=0;
            for(int k=7;k>=0;k--,l++)
               b+=((s[l]-48)*pow(2,k));
            l++;
            if(b!=a[j])flag=0;
        }
        if(flag)printf("Case %d: Yes\n",i);
        else printf("Case %d: No\n",i);
    }
    return 0;
}
