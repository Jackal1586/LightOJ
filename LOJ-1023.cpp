#include<stdio.h>
#include<iostream>
using namespace std;
char sx[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ans[27];
int n,k,vis;
void rec(int idx){
    if(idx==n && k>0){
        ans[idx]='\0';
        puts(ans);
        k--;
    }if(k<=0)return ;
    for(int i=0;i<n;i++){
        if(!(vis&(1<<i))){
            vis|=(1<<i);
            ans[idx]=sx[i];
            rec(idx+1);
            vis&=(~(1<<i));
        }
    }
}
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%d%d",&n,&k);
    vis=0;
    cout<<"Case "<<z<<":\n";
    rec(0);
}
return 0;
}
