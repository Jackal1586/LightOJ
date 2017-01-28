#include<bits/stdc++.h>
using namespace std ;
int main()
{
	int cases , caseno = 1 ;
	long long n;
	long double Z;
	scanf("%d",&cases);
	while( cases -- )
	{
		scanf("%lld",&n);
		if(n==0)
		{
			printf("Case %d: 0\n",caseno++);
			continue;
		}
		Z = static_cast<long double>(n);
		long long int ans = 0,UP,LW,i,p;
		i = 1;
		p = 4;
		int bc = floor(log(n)/log(2));
		while(bc--)
		{
			ans += (n/p * i) ;
			UP = (ceil(Z/p)*p)-1;
			LW = UP - i + 1;
			if(n>=LW && n<=UP) ans += (n - LW + 1);
			p <<= 1;
			i <<= 1;
		}
		printf("Case %d: %lld\n",caseno++ ,ans) ;
	}
	return 0;
}
