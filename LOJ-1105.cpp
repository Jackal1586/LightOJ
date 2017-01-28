#include<bits/stdc++.h>
using namespace std;
int main() {
    int fib[44];
    fib[0]=1;
    fib[1]=2;
    for(int i=2; i<44; i++) {
        fib[i]=fib[i-1]+fib[i-2];
    }
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
	int n;
	scanf("%d",&n);
	cout<<"Case "<<z<<": ";
	//long long mask=0;
	bool f=0;
	while(n){
		for(register char i=43;i>=0;i--){
			if(fib[i]==n){
				//mask|=(1LL<<i);
				n=0;
				putchar('1');
				for(int j=0;j<i;j++)putchar('0');
				break;
			}else if(fib[i]<n){
				putchar('1');
				f=1;
				//mask|=(1LL<<i);
				n-=fib[i];
			}else{
				if(f)putchar('0');
			}
		}
	}
//	int st=44;
//	while(!(mask&(1LL<<st)))st--;
//
//	for(int i=st;i>=0;i--)cout<<((mask&(1LL<<i))?'1':'0');
	puts("");
    }
    return 0;
}
