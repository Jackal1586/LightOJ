#include<bits/stdc++.h>
using namespace std;
char s[15][15];
int cost[15][15],n;
int dirr[]={-1,0,1,0};
int dirc[]={0,1,0,-1};
void bfs(pair<int,int>src,int cid){
    cost[src.first][src.second]=0;
    queue<pair<int,int> >q;
    q.push(src);
    while(!q.empty()){
        src=q.front();q.pop();
        for(int i=0;i<4;i++){
            pair<int,int>dest=make_pair(src.first+dirr[i],src.second+dirc[i]);
            if(dest.first<0 || dest.first >=n || dest.second<0 || dest.second>=n)continue;
            if(s[dest.first][dest.second]=='#' || s[dest.first][dest.second]>('A'+cid))continue;
            if(cost[dest.first][dest.second]>(cost[src.first][src.second]+1)){
                cost[dest.first][dest.second]=(cost[src.first][src.second]+1);
                q.push(dest);
            }
        }
    }
}
int main(){
int t;
cin>>t;
//scanf("%d",&t);
for(int z=1;z<=t;z++){
    cin>>n;
    //scanf("%d",&n);
    //getchar();
    vector<pair<char,pair<int,int> > >v;
    for(int i=0;i<n;i++){
        //getchar();
        for(int j=0;j<n;j++){
            cin>>s[i][j];
            //scanf("%c",&s[i][j]);
            if(isupper(s[i][j])){
                v.push_back(make_pair(s[i][j],make_pair(i,j)));
            }
        }
    }sort(v.begin(),v.end());
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<s[i][j];
//        }cout<<endl;
//    }
    long long sum=0;
    for(int i=0;i<(v.size()-1);i++){
                for(int i=0;i<n;i++)for(int j=0;j<n;j++)cost[i][j]=numeric_limits<int>::max();
                bfs(make_pair(v[i].second.first,v[i].second.second),i+1);
                sum+=cost[v[i+1].second.first][v[i+1].second.second];
    }if(sum>=numeric_limits<int>::max())cout<<"Case "<<z<<": Impossible\n";
    else cout<<"Case "<<z<<": "<<sum<<"\n";
    v.clear();
}
return 0;
}
