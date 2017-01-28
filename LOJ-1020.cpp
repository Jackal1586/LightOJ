#include<stdio.h>
int main()
{
    int t,n,i;
    char s[30];
    scanf("%d",&t);
    t++;
    for( i=1;i<t;i++)
    {
        scanf("%d%s",&n,s);
        if(s[0]=='A')
        {
            if(n%3 == 1)printf("Case %d: Bob\n",i);
            else printf("Case %d: Alice\n",i);
        }
        else if(n%3 == 0)printf("Case %d: Alice\n",i);
        else printf("Case %d: Bob\n",i);
    }
    return 0;
}
