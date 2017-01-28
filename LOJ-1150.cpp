#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int dirr[]= {-1,0,1,0};
int dirc[]= {0,-1,0,1};
class ghost{
public:
    int vis[150][150],source=121,sink=122,cap[150][150],pr[150],n,m;
    vector<int>c,p,g[150];
    int cn(int a) {
        return (a+52);
    }
    void BG(int lim) {
        memset(cap,0,sizeof(cap));
        for(int i=0;i<150;i++)g[i].clear();
        for(int i=0; i<p.size(); i++) {
            g[source].push_back(i);
            g[i].push_back(source);
            cap[source][i]=1;
        }
        for(int i=0; i<c.size(); i++) {
            g[cn(i)].push_back(sink);
            g[sink].push_back(cn(i));
            cap[cn(i)][sink]=1;
        }
        for(int i=0; i<p.size(); i++) {
            for(int j=0; j<c.size(); j++) {
                if(vis[j][i]<=lim) {
                    g[i].push_back(cn(j));
                    g[cn(j)].push_back(i);
                    cap[i][cn(j)]=1;
                }
            }
        }
    }
    void APSP(vector<string>park) {
        for(int i=0;i<c.size();i++){
            int cost[30][30];
            for(int j=0;j<30;j++){
                for(int k=0;k<30;k++){
                    cost[j][k]=1<<25;
                }
            }
            int sr=(c[i]-1)/m,sc=(c[i]-1)%m;
            cost[sr][sc]=0;
            queue<pair<int,int> >q;
            q.push(make_pair(sr,sc));
            while(!q.empty()){
                pair<int,int>src=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    pair<int,int>dest=make_pair(src.first+dirr[j],src.second+dirc[j]);
                    if(dest.first<0 || dest.first>=n || dest.second<0 || dest.second>=m)continue;
                    if(park[dest.first][dest.second]=='#')continue;
                    if(cost[dest.first][dest.second]>cost[src.first][src.second]+1){
                        cost[dest.first][dest.second]=cost[src.first][src.second]+1;
                        q.push(dest);
                    }
                }
            }
            for(int j=0;j<p.size();j++){
                int rr=(p[j]-1)/m,cc=(p[j]-1)%m;
                vis[i][j]=cost[rr][cc];
            }
        }
    }
    bool bfs() {
        memset(pr,-1,sizeof(pr));
        pr[source]=-2;
        queue<int>q;
        q.push(source);
        while(!q.empty()) {
            int src=q.front();
            q.pop();
            for(int i=0; i<g[src].size(); i++) {
                if(pr[g[src][i]]==-1 && cap[src][g[src][i]]>0) {
                    pr[g[src][i]]=src;
                    if(g[src][i]==sink) {
                        return 0;
                    }
                    q.push(g[src][i]);
                }
            }
        }
        return 1;
    }
    bool ok() {
        int ret=0;
        while(true) {
            if(bfs())break;
            ret++;
            int y=sink;
            while(pr[y]!=-2) {
                cap[pr[y]][y]--;
                cap[y][pr[y]]++;
                y=pr[y];
            }
        }
        return (ret<p.size());
    }
    int minTime(vector <string> park) {
        n=park.size(),m=park[0].size();
        //cout<<n<<" "<<m<<endl;
        for(int i=0; i<150; i++)for(int j=0; j<150; j++)vis[i][j]=1<<25;
        for(int i=0; i<n; i++) {
            //cout<<park[i]<<endl;
            for(int j=0; j<m; j++) {
                int x=i*m+j+1;
                if(park[i][j]=='G')c.push_back(x);
                else if(park[i][j]=='H')p.push_back(x);
            }
        }
        if(p.size()>c.size())return -1;
        if(c.size()==0)return 0;
        //cout<<p.size()<<" x "<<c.size()<<endl;
        /*for(int i=0;i<p.size();i++){
            cout<<p[i]<<endl;
        }
        for(int i=0;i<c.size();i++){
            cout<<c[i]<<endl;
        }*/
        APSP(park);
        //cout<<vis[p[0]][c[0]]<<endl;
        int low=0,high=1<<25,mid;
        /*BG(15);
        cout<<ok()<<endl;
        BG(16);
        cout<<ok()<<endl;
        */
        while(high-low>=4) {
            mid=(high+low)>>1;
            BG(mid);
            if(ok())low=mid;
            else high=mid;
            //cout<<low<<endl;
        }
        for(; low<=high; low++) {
            BG(low);
            if(ok());
            else break;
        }
        return (low>=(1<<24))?-1:low;
    }
};
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        vector<string>v;
        char s[30];
        for(int i=0;i<n;i++){
            scanf(" %s",s);
            v.push_back(s);
        }
        ghost a;
        int ans=a.minTime(v);
        cout<<"Case "<<z<<": ";
        if(ans==-1){
            puts("Vuter Dol Kupokat");
        }else {
            cout<<2*(ans+1)<<"\n";
        }
    }
    return 0;
}

