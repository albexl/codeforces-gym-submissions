#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second



signed main()
{
	//#ifdef DGC
		freopen("auxiliary.in", "r", stdin);
		freopen("auxiliary.out", "w", stdout);
//	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;

	vector<ll> dp(n + 1, -1);
	vector<pii> v = {{0, 6}, {1, 2}, {2, 5}, {3, 5}, {4, 4}, {5, 5}, {6, 6}, {7, 3}, {8, 7}, {9, 6}};

	dp[0] = 0;

	for(int i = 1; i <= n; i++){
		for(auto &x : v){
			if(i - x.second >= 0 && dp[i - x.second] != -1)
				dp[i] = max(dp[i], dp[i - x.second] + 1ll * x.first);
		}
	}

//	for(int i = 0; i <= 1000000; i++)
//		if(dp[i] == -1){
//			cout << "fddfdff" << endl;
//			return 0;
//		}

	cout << max(dp[n], 0ll) << endl;

	return 0;
}