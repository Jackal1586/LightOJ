#include<bits/stdc++.h>
using namespace std;
bool ok(int*match,int n,int*done) {
    for(int i=1; i<=n; i++) {
        if(match[i]==-1 && done[i]<n)return 1;
    }
    return 0;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n;
        scanf("%d",&n);
        int match[2*n+1],preference[2*n+1][n],done[2*n+1];
        for(int i=1; i<=(2*n); i++) {
            for(int j=0; j<n; j++) {
                scanf("%d",&preference[i][j]);
            }
        }
        memset(match,-1,sizeof(match));
        memset(done,0,sizeof(done));
        while(ok(match,n,done)) {
            for(int i=1; i<=n; i++) {
                if(match[i]==-1) {
                    int x=done[i];
                    if(x<n){
                        if(match[preference[i][x]]==-1){
                            match[i]=preference[i][x];
                            done[i]++;
                            match[preference[i][x]]=i;
                            continue;
                        }else{
                            bool f=0;
                            for(int j=0;j<n;j++){
                                if(preference[preference[i][x]][j]==i){
                                    f=1;
                                    break;
                                }else if(preference[preference[i][x]][j]==match[preference[i][x]])break;
                            }
                            if(f){
                                match[match[preference[i][x]]]=-1;
                                match[preference[i][x]]=i;
                                match[i]=preference[i][x];
                                done[i]++;
                            }else {
                                done[i]++;
                            }
                        }
                    }
                }
            }
        }
        cout<<"Case "<<z<<":";
        for(int i=1;i<=n;i++){
            cout<<" ("<<i<<" "<<match[i]<<")";
        }cout<<"\n";
    }
    return 0;
}

