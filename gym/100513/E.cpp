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

	int n;
	cin>>n;
	vector<int> m(n), r(n);
	for(int i=0; i<n; i++)
		cin>>m[i]>>r[i];

	vector<int> win(n);
	for(int i=0; i<n; i++)
		win[i] = (m[i] > r[i]);

	int g = 0;
	for(int i=0; i<n; i++)
		g += win[i];

	vector<ii> ans;
	int tot = n;
	for(int i = 0; i<n-1 && 2 * g <= tot; i++)
	{
		if((win[i] + win[i+1] == 1 && m[i] + m[i+1] > r[i] + r[i+1]) || win[i] + win[i+1] == 0)
		{
			ans.push_back(ii(i+1,i+2));
			--tot;
			++i;
		}
	}

	if(2 * g > tot)
	{
		cout<<n - tot<<'\n';
		for(auto &i:ans)
			cout<<i.F<<" "<<i.S<<'\n';
	}
	else
		cout<<-1;
	return 0;
}