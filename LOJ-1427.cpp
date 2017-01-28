#include<bits/stdc++.h>
using namespace std;
char text[1000006],pattern[502];
int n,freq[1000006],ans[502],tii;
struct trie{
  int level,_next[27],pr;
  vector<int>pIndex;
  trie(){
    level=0,pr=0;
    memset(_next,0,sizeof(_next));
    pIndex.clear();
  }
}tree[502*502+10];
void init(){
  for(int i=0;i<=tii;i++){
    tree[i]=trie();
  }
  tii=1;
  return;
}
void _insert(int ii){
  int root=0;
  for(int i=0;pattern[i];i++){
    int x=pattern[i]-'a';
    if(tree[root]._next[x]==0){
      tree[root]._next[x]=tii;
      tii++;
    }
    tree[tree[root]._next[x]].level=tree[root].level+1;
    root=tree[root]._next[x];
  }
  tree[root].pIndex.push_back(ii);
  return;
}
int parent(int src,int ii){
  src=tree[src].pr;
  while(src>0 && tree[src]._next[ii]==0){
    src=tree[src].pr;
  }
  return src;
}
void bfs(){
  queue<int>q;
  for(int i=0;i<26;i++){
    if(tree[0]._next[i]!=0){
      q.push(tree[0]._next[i]);
    }
  }
  while(!q.empty()){
    int src=q.front();q.pop();
    for(int i=0;i<26;i++){
      if(tree[src]._next[i]!=0){
        int dest=tree[src]._next[i];
        int _pr=parent(src,i);
        tree[dest].pr=tree[_pr]._next[i];
        q.push(dest);
      }
    }
  }
  return;
}
void query(){
  int root=0;
  memset(freq,0,sizeof(freq));
  for(int i=0;text[i];i++){
    int x=text[i]-'a',_pr;
    if(tree[root]._next[x]==0){
      _pr=parent(root,x);
      root=tree[_pr]._next[x];
    }
    else{
      root=tree[root]._next[x];
    }
    freq[root]++;
  }
  vector<pair<int,int> >v;
  for(int i=0;i<tii;i++){
    v.push_back(make_pair(tree[i].level,i));
  }
  sort(v.rbegin(),v.rend());
  for(int i=0;i<tii;i++){
    freq[tree[v[i].second].pr]+=freq[v[i].second];
  }
  for(int i=1;i<tii;i++){
    for(int j=0;j<(int)tree[i].pIndex.size();j++){
      ans[tree[i].pIndex[j]]=freq[i];
    }
  }
  return;
}
int main(){
  int t;
  scanf("%d",&t);
  for(int z=1;z<=t;z++){
    scanf("%d %s",&n,text);
    init();
    for(int i=0;i<n;i++){
      scanf(" %s",pattern);
      _insert(i);
    }
    bfs();
    query();
    cout<<"Case "<<z<<":\n";
    for(int i=0;i<n;i++){
      cout<<ans[i]<<"\n";
    }
  }
  return 0;
}

