#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second
const double EPS=1e-8,oo=1e9;

int main()
{
	freopen("cubes.in", "r", stdin);

	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int j=0; j<n; j++)
			cin>>v[j];

		sort(v.rbegin(), v.rend());

		vector<int> ans(n);
		int l=0, r=n-1;
		for(int j=0; j<n; j++)
		{
			if(j&1)
				ans[l++] = v[j];
			else
				ans[r--] = v[j];
		}
		cout<<"Case "<<i<<":"<<'\n';
		for(int j=0; j<n; j++)
			cout<<ans[j]<<" \n"[j==n-1];
	}

	return 0;
}