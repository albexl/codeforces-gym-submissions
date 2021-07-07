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

	vector<int> v(n), w(n);
	for(auto &el : v) cin >> el;
	for(auto &el : w) cin >> el;

	function<bool(int)> won = [&](int d)
	{
		for(int i = 1; i < n; ++i)
		{
			if(v[i] + d < w[i]) return false;
			if(v[i] + d > w[i]) return true;
		}
		return true;
	};

	if(v.front() > w.front())
		cout << 0 << endl;
	else
	{
		if(won(w.front() - v.front()))
			cout << w.front() - v.front() << endl;
		else
			cout << w.front() - v.front() + 1 << endl;
	}

	return 0;
}