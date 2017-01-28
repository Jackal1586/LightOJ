#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n,m,a;
    scanf("%d%d",&n,&m);
    string s;
    deque<int>dq;
    cout<<"Case "<<z<<":\n";
    while(m--){
        cin>>s;
        if(s=="pushLeft"){
            cin>>a;
            if(dq.size()<n){
                dq.push_front(a);
                cout<<"Pushed in left: "<<a<<"\n";
            }else cout<<"The queue is full\n";
        }else if(s=="pushRight"){
            cin>>a;
            if(dq.size()<n){
                dq.push_back(a);
                cout<<"Pushed in right: "<<a<<"\n";
            }else cout<<"The queue is full\n";
        }else if(s=="popLeft"){
            if(!dq.empty()){
                cout<<"Popped from left: "<<dq.front()<<"\n";
                dq.pop_front();
            }else cout<<"The queue is empty\n";
        }else if(s=="popRight"){
            if(!dq.empty()){
                cout<<"Popped from right: "<<dq.back()<<"\n";
                dq.pop_back();
            }else cout<<"The queue is empty\n";
        }
    }
}
return 0;
}
