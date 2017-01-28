#include<bits/stdc++.h>
using namespace std;
long long arr[100010];
long long tree[5*100010];
long long query(int node,int b,int e,int i,int j){
if(i>e||j<b)return numeric_limits<int>::max();
if(b>=i&&e<=j)return tree[node];
int l=node*2,r=l+1,mid=(b+e)/2;
return min(query(l,b,mid,i,j),query(r,mid+1,e,i,j));
}
/*void update(int node,int b,int e,int i,int val){
if(i>e||i<b)return;
if(b>=i&&e<=i){
    tree[node]=val;
    return;
}int l=node*2,r=l+1,mid=(b+e)/2;
update(l,b,mid,i,val);
update(r,mid+1,e,i,val);
tree[node]=min(tree[l],tree[r]);
}*/
void init(int node,int b,int e){
if(b==e){
    tree[node]=arr[b];return;
}
int l=node*2,r=l+1,mid=(b+e)/2;
init(l,b,mid);init(r,mid+1,e);
tree[node]=min(tree[l],tree[r]);
}
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
    }cout<<"Case "<<z<<":\n";
    init(1,1,n);
    while(q--){
        int a,b;
        /**for(int i=1;i<=9;i++){
            cout<<tree[i]<<" ";
        }cout<<endl;**/
        scanf("%d%d",&a,&b);
        cout<<query(1,1,n,a,b)<<"\n";
    }
    if(z<t)memset(tree,0,sizeof(tree));
}
return 0;
}

