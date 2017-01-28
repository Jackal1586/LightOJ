#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
map<string,int>mp;
mp["January"]=0;
mp["February"]=1;
mp["March"]=2;
mp["April"]=3;
mp["May"]=4;
mp["June"]=5;
mp["July"]=6;
mp["August"]=7;
mp["September"]=8;
mp["October"]=9;
mp["November"]=10;
mp["December"]=11;
scanf("%d",&t);
for(int z=1;z<=t;z++){
	int d1,m1,y1,d2,m2,y2;
	string s1,s2;
	char c;
	cin>>s1>>d1>>c>>y1;
	cin>>s2>>d2>>c>>y2;
	m1=mp[s1];
	m2=mp[s2];
	if(m1>1)y1++;
	if(m2==0 || (m2==1 && d2<29))y2--;
	y1--;
	int ans=y2/4-y1/4;
	ans-=(y2/100-y1/100);
	ans+=(y2/400-y1/400);
	cout<<"Case "<<z<<": "<<ans<<"\n";
}
return 0;
}
