#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    getchar();
    for(int l=1; l<=t; l++)
    {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        transform(s1.begin(),s1.end(),s1.begin(), ::tolower);
        transform(s2.begin(),s2.end(),s2.begin(), ::tolower);
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int flag=1,i,j;
        for(i=0,j=0;s1[i] && s2[j];)
        {
                while(s1[i]==' ')i++;
                while(s2[j]==' ')j++;
                if(s1[i]!=s2[j]){flag=0;break;}
                i++;j++;
        }
        if(flag && !(s1[i]) && !s2[j])printf("Case %d: Yes\n",l);
        else printf("Case %d: No\n",l);
    }
    return 0;
}
