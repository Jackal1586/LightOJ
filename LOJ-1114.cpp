#include<bits/stdc++.h>
using namespace std;
string ss;
char s[100002];
map<string,int>mp;
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
		int n;
		//cin>>n;
		scanf("%d",&n);
		getchar();
		for(int i=0;i<n;i++){
			gets(s);
			//cin>>s;
			ss=s;
			//int sz=strlen(s);
			if(ss.size()>2){
				sort(ss.begin()+1,ss.end()-1);
			}
			mp[ss]++;
		}
		int m;
		scanf("%d",&m);
		getchar();
		//cin>>m;
		stringstream sss;
		cout<<"Case "<<z<<":\n";
		while(m--){
			//getchar();
			gets(s);
			//getline(cin,s);
			sss<<s;
			int ans=1;
			while(sss>>ss){
				if(ss.size()>2)sort(ss.begin()+1,ss.end()-1);
				if(mp[ss]>0)ans*=mp[ss];
				else {
					ans=0;
					break;
				}
			}
			ss.clear();
			sss.clear();
			cout<<ans<<"\n";
		}
		mp.clear();
    }
    return 0;
}
