#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<int> point;
#define F first
#define S second



int main()
{
	#ifdef NeverBeRed
		//freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);


	int n;
	cin >> n;

	map<string, int> mp;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		mp[s]++;
	}

	for(auto &el : mp){
		if(el.second > n - el.second){
			cout << el.first << endl;
			return 0;
		}
	}

	cout << "NONE\n";


	return 0;
}