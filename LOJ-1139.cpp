#include<bits/stdc++.h>
using namespace std;
map<vector<int>,int>mp;
int dirr[]={-1,0,1,0};
int dirc[]={0,-1,0,1};
void bfs(vector<int>v,int ii){
    queue<vector<int> >qv;
    queue<int>qi;
    mp[v]=0;
    qv.push(v);
    qi.push(ii);
    while(!qv.empty()){
        v=qv.front();qv.pop();
        ii=qi.front();qi.pop();
        for(int i=0;i<4;i++){
            int ni=(ii/3)+dirr[i];
            int nj=(ii%3)+dirc[i];
            if(ni<0 || nj<0 || nj>2 || ni>2)continue;
            vector<int>dest;
            dest=v;
            ni=(ni*3)+nj;
            swap(dest[ii],dest[ni]);
            if(mp.find(dest)==mp.end()){
                mp[dest]=mp[v]+1;
                qv.push(dest);
                qi.push(ni);
            }
        }
    }
    return;
}
int main(){
    vector<int>st;
    st.push_back(1);
    st.push_back(2);
    st.push_back(3);
    st.push_back(4);
    st.push_back(5);
    st.push_back(6);
    st.push_back(7);
    st.push_back(8);
    st.push_back(0);
    bfs(st,8);
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        vector<int>v;
        int ch;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>ch;
                v.push_back(ch);
            }
        }
        if(mp.find(v)!=mp.end())cout<<"Case "<<z<<": "<<mp[v]<<"\n";
        else cout<<"Case "<<z<<": impossible\n";
    }
    return 0;
}

