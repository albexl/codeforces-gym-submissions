#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex<ll> point;
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

	map<string,int> k,d;
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		string x;
		cin>>x;
		if(!k.count(x))
			k[x]=0;
		++k[x];
	}
	for(int i=0; i<n; i++)
	{
		string x;
		cin>>x;
		if(!d.count(x))
			d[x]=0;
		++d[x];
	}

	int ans=0;
	for(auto &i:k)
	{
		int temp=d[i.F];
		ans+=min(temp,i.S);
	}

	cout<<ans;

	return 0;
}