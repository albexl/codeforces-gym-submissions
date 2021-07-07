#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second
#define ii pair<int,int>


int main()
{
	#ifdef Adrian
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int c,d;
		cin>>c>>d;
		if(c==0 && d==0)
		{
			cout<<0<<'\n';
			continue;
		}
		int a = 1;
		for(int i=0; i<c; i++)
			a*=26;
		int b = 1;
		for(int j=0; j<d; j++)
			b*=10;
		cout<<a*b<<'\n';
	}

	return 0;
}