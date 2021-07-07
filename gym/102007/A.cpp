#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	vector<int> v(n);
	for(auto &el : v) cin >> el;

	sort(v.begin(), v.end());

	int ans = 1;
	for(int i = 1; i < n; ++i)
		if(v[i] + v[i - 1] <= x)
			ans = i + 1;

	cout << ans << endl;

	return 0;
}