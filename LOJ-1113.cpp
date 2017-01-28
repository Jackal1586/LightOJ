#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        string s;
        stack<string>b,f;
        string cur="http://www.lightoj.com/";
        cout<<"Case "<<z<<":\n";
        while(cin>>s){
            if(s[0]=='V'){
                string temp;
                cin>>temp;
                b.push(cur);
                cur=temp;
                cout<<cur<<"\n";
                stack<string>bb;
                swap(f,bb);
            }
            else if(s[0]=='B'){
                if(!b.empty()){
                    f.push(cur);
                    cur=b.top();
                    b.pop();
                    cout<<cur<<"\n";
                }else cout<<"Ignored\n";
            }
            else if(s[0]=='F'){
                if(!f.empty()){
                    b.push(cur);
                    cur=f.top();
                    f.pop();
                    cout<<cur<<"\n";
                }else  cout<<"Ignored\n";
            }
            else if(s[0]=='Q')break;
        }
    }
    return 0;
}
