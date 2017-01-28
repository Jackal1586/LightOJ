#include<bits/stdc++.h>
using namespace std;
int n,_left[102],_right[102],arr[102],check[102];
bool vis[102];
vector<int>g[102];
bool dfs(int src) {
    if(vis[src])return false;
    vis[src]=true;
    for(int i=0; i<(int)g[src].size(); i++) {
        if(check[g[src][i]]==0 && _right[g[src][i]]==-1) {
            _right[g[src][i]]=src;
            _left[src]=g[src][i];
            return true;
        }
    }
    for(int i=0; i<(int)g[src].size(); i++) {
        if(check[g[src][i]]==0 && dfs(_right[g[src][i]])) {
            _right[g[src][i]]=src;
            _left[src]=g[src][i];
            return true;
        }
    }
    return false;
}
int BPM() {
    memset(_left,-1,sizeof(_left));
    memset(_right,-1,sizeof(_right));
    bool done=false;
    while(!done) {
        done=true;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++) {
            if(check[i]==0 && _left[i]==-1 && dfs(i)) {
                done=false;
            }
        }
    }
    int ret=0;
    for(int i=0; i<n; i++)ret+=(_left[i]!=-1 && check[i]==0);
    return ret;
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(nullptr);
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        for(int i=0;i<102;i++){
            g[i].clear();
        }
        scanf("%d",&n);
        //cin>>n;
        for(int i=0; i<n; i++) {
            scanf("%d",&arr[i]);
            //cin>>arr[i];
        }
        sort(arr,arr+n);
        n=unique(arr,arr+n)-arr;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(arr[j]%arr[i]==0) {
                    g[i].push_back(j);
                }
            }
        }
        memset(check,0,sizeof(check));
        int ans=n-BPM();
        cout<<"Case "<<z<<":";
        //cout<<ans<<"\n";
        for(int i=0,cnt=0,k=0; k<ans && i<n; i++) {
            if(check[i]>0)continue;
            for(int j=0; j<(int)g[i].size(); j++) {
                if(check[g[i][j]]==0)cnt++;
                check[g[i][j]]++;
            }
            int x=n-cnt-BPM();
            //cout<<BPM()<<" "<<x<<" "<<cnt<<" "<<n<<endl;
            if(x==ans) {
                cout<<" "<<arr[i];
                k++;
            } else {
                for(int j=0; j<(int)g[i].size(); j++) {
                    check[g[i][j]]--;
                    if(check[g[i][j]]==0)cnt--;
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}

