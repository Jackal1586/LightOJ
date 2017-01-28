#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    getchar();
    for(int z=1; z<=t; z++) {
        char s[100004];
        gets(s);
        cout<<"Case "<<z<<": ";
        int n=strlen(s);
        int cnt=0;
        for(int i=0;s[i];i++)if(s[i]=='9')cnt++;
        if(cnt==n){
            putchar('1');
            for(int i=1;i<n;i++)putchar('0');
            puts("1");
            continue;
        }
        int num[n+2];
        for(int i=0;s[i];i++)num[i]=(s[i]-48);
        int mid = n/2;
        bool flag = false;
        int i = mid - 1;
        int j = (n&1)? mid + 1 : mid;
        while (i >= 0 && num[i] == num[j])i--,j++;
        if ( i < 0 || num[i] < num[j])flag = true;
        while (i >= 0){
            num[j] = num[i];
            j++;
            i--;
        }
        if (flag == true){
            int carry = 1;
            i = mid - 1;
            if (n%2 == 1){
                num[mid] += carry;
                carry = num[mid] / 10;
                num[mid] %= 10;
                j = mid + 1;
            }else j = mid;
            while (i >= 0){
                num[i] += carry;
                carry = num[i] / 10;
                num[i] %= 10;
                num[j++] = num[i--];
            }
        }
        for(int i=0;i<n;i++)cout<<num[i];
        puts("");
    }
    return 0;
}

