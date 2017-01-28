#include<bits/stdc++.h>
using namespace std;
inline int RI() {
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
int arr[2005],aa[2005];
int histogram(int n) {
    stack<int>st;
    int ret=0,x,mx;
    for(int i=0; i<n; i++) {
        while(!st.empty()) {
            if(arr[i]<=arr[st.top()]) {
                st.pop();
            } else break;
        }
        if(st.empty())x=-1;
        else x=st.top();
        aa[i]=i-x-1;
        st.push(i);
    }
    while(!st.empty()) {
        st.pop();
    }
    mx=-1;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty()) {
            if(arr[i]<=arr[st.top()]) {
                st.pop();
            } else break;
        }
        x=n;
        if(!st.empty()) {
            x=st.top();
        }
        x=x-i-1;
        mx=max(mx,arr[i]*(x+aa[i]+1));
        st.push(i);
    }
    while(!st.empty()) {
        st.pop();
    }
    return ret=mx;
}
int main() {
    int t=RI();
    //scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int m=RI(),n=RI();
        char a;
        //scanf("%d%d",&m,&n);
        memset(arr,0,sizeof(arr));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(a=getchar_unlocked();a!=48 && a!=49;a=getchar_unlocked());
                //scanf(" %c",&a);
                if(a=='1')arr[j]=0;
                else arr[j]++;
            }
            ans=max(ans,histogram(n));
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

