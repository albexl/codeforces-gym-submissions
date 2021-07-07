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
#define ii pair<ll,ll>


int main()
{
	//#ifdef Adrian
		freopen("intel.in", "r", stdin);
		freopen("intel.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	const ll Nmax=1e7;
	int n;
	ll xmax=-Nmax,xmin=Nmax,ymax=-Nmax,ymin=Nmax;

	cin>>n;
	vector<ii> poly;
	ll per=0;
	for(int i=0; i<n; i++)
	{
		ll x,y;
		cin>>x>>y;
		poly.push_back(ii(x,y));
		xmax=max(xmax,x);
		ymax=max(ymax,y);
		xmin=min(xmin,x);
		ymin=min(ymin,y);
	}

	for(int i=0; i<n; i++)
	{
		int nx=(i+1)%n;
		if(poly[nx].F == poly[i].F)
			per+=abs(poly[nx].S - poly[i].S);
		else
			per+=abs(poly[nx].F - poly[i].F);
	}

	cout<< per - 2*(ymax - ymin + xmax - xmin);

	return 0;
}