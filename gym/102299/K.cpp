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
#define ii pair<ll,ll>


int main()
{
	#ifdef Adrian
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector <ll> v(n);
	for (int i=0; i<n; i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	ll sum=0;
	for(int i=0; i<n; i++)
	{
		if(sum+1<v[i])
		{
			cout<<sum+1;
			return 0;
		}
		sum+=v[i];
	}
	cout<<sum+1;


	return 0;
}