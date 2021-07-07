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



int main()
{
	#ifdef Adrian
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n,d;
	cin>>n>>d;
	vector<int>arr(n);
	int cant=0;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		cant+=arr[i];
	}
	d/=cant;
	for(int i=0; i<n; i++)
		cout<<arr[i]*d<<"\n";


	return 0;
}