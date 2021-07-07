#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	n += n;

	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int mn = 2e9 + 1, mx = -1;

	int lo = 0, hi = n - 1;
	while(lo <= hi){
		int cnt = v[lo] + v[hi];
		mn = min(mn, cnt);
		mx = max(mx, cnt);
		lo++;
		hi--;
	}

	cout << mx - mn << endl;

	return 0;
}