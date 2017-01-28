#include<bits/stdc++.h>
using namespace std;
long long arr[100010];
long long tree[5*100010];
long long query(int node,int b,int e,int i,int j){
if(i>e||j<b)return 0;
if(b>=i&&e<=j)return tree[node];
int l=node*2,r=l+1,mid=(b+e)/2;
return (query(l,b,mid,i,j)+query(r,mid+1,e,i,j));
}
void update(int node,int b,int e,int i,int val){
if(i>e||i<b)return;
if(b>=i&&e<=i){
    tree[node]=val;
    return;
}int l=node*2,r=l+1,mid=(b+e)/2;
update(l,b,mid,i,val);
update(r,mid+1,e,i,val);
tree[node]=tree[l]+tree[r];
}
void init(int node,int b,int e){
if(b==e){
    tree[node]=arr[b];return;
}
int l=node*2,r=l+1,mid=(b+e)/2;
init(l,b,mid);init(r,mid+1,e);
tree[node]=tree[l]+tree[r];
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
        int a,b,c;
        /**for(int i=1;i<=5;i++){
            cout<<tree[i]<<" ";
        }cout<<endl;**/
        scanf("%d%d",&a,&b);
        if(a!=1)scanf("%d",&c);
        if(a==1){
            cout<<arr[b+1]<<"\n";
            arr[b+1]=0;
            update(1,1,n,b+1,0);
        }else if(a==2){
            arr[b+1]+=c;
            update(1,1,n,b+1,arr[b+1]);
        }else{
            cout<<query(1,1,n,b+1,c+1)<<"\n";
        }
    }
    if(z<t)memset(tree,0,sizeof(tree));
}
return 0;
}
