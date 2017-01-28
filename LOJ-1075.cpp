#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
		int n;
		scanf("%d",&n);
		char ss1[340],ss2[340];
		string s1,s2;
		map<string,int>mp1,mp2;
		map<string,string>mp;
		for(int i=1;i<n;i++){
			scanf(" %s %s",ss1,ss2);
			s1=ss1;
			s2=ss2;
			mp[s1]=s2;
			mp1[s1]++;
			mp2[s2]++;
		}
		for(map<string,int>::iterator i=mp1.begin();i!=mp1.end();i++){
			if(i->second==1 && mp2[i->first]==0){
				s1=i->first;
				break;
			}
		}
		cout<<"Case "<<z<<":\n";
		for(int i=0;i<n;i++){
			cout<<s1<<"\n";
			s1=mp[s1];
		}
		puts("");
    }
    return 0;
}
