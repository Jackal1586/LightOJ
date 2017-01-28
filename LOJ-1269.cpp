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
struct trie{
    int ii;
    trie *next[2];
    trie(){
        for(int i=0;i<2;i++){
            next[i]=NULL;
        }
    }
}*root;
int n,arr[50002],_xor[50002];
void _insert(int n,int _ii){
    trie *cur=root;
    for(int i=31;i>=0;i--){
        int x=(n&(1<<i))?1:0;
        if(cur->next[x]==NULL){
            cur->next[x]=new trie();
        }
        cur=cur->next[x];
    }
    cur->ii=_ii;
    return;
}
int _search(int n,int ii,bool ff){
    trie *cur=root;
    int q=0;
    for(int i=31;i>=0;i--){
        int x=(n&(1<<i))?1:0;
        if(ff){
            if(cur->next[x]!=NULL);
            else x=1-x;
        }else{
            if(cur->next[1-x]!=NULL)x=1-x;
        }
        cur=cur->next[x];
        q=q*2+x;
    }
    int ret=-1;
    if(ff)ret=numeric_limits<int>::max();
        if(ff)ret=min(ret,_xor[ii]^q);
        else ret=max(ret,_xor[ii]^q);
    return ret;
}
void _delete(trie *cur){
    for(int i=0;i<2;i++){
        if(cur->next[i]!=NULL)_delete(cur->next[i]);
    }
    delete(cur);
    return;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        _xor[0]=0;
        n=RI();//scanf("%d",&n);
        int mx=-1,mn=numeric_limits<int>::max();
        for(int i=1;i<=n;i++){
            arr[i]=RI();//scanf("%d",&arr[i]);
            _xor[i]=_xor[i-1]^arr[i];
            mx=max(mx,_xor[i]);
            mn=min(mn,_xor[i]);
        }
        root=new trie();
        _insert(_xor[1],1);
        for(int i=2;i<=n;i++){
            mx=max(mx,_search(_xor[i],i,0));
            mn=min(mn,_search(_xor[i],i,1));
            _insert(_xor[i],i);
        }
        cout<<"Case "<<z<<": "<<mx<<" "<<mn<<"\n";
        _delete(root);
    }
    return 0;
}

