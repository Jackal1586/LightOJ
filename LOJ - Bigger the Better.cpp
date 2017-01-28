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
int main()
{
    int t,n,w;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&w);
        int max=-1,a;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a);
            if(a>max && a<=w)max=a;
        }
        printf("Case %d: %d\n",i,max);
    }
    return 0;
}
