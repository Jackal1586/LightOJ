#include<bits/stdc++.h>
using namespace std;
int main()
{
        int t,n,p,q;
        cin>>t;
        for(int l=1;l<=t;l++)
        {
                cin>>n>>p>>q;
                int weight=0,cnt=0,a;
                for(int i=0;i<n;i++)
                {
                        cin>>a;
                        weight+=a;
                        if(weight<=q && cnt<p)cnt++;
                }
                printf("Case %d: %d\n",l,cnt);
        }
        return 0;
}
