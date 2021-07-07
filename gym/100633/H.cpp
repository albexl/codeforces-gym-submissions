#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, s, t;
	cin >> n >> s >> t;

	if(s > t)
		s = n - s + 1, t = n - t + 1;

	if(s + 1 == t && (s == 1 || t == n))
		cout << 1 << endl;
	else if(s + 1 >= t)
		cout << -1 << endl;
	else
	{
		int a = 0;
		if(s > 1) ++a, ++s;
		if(t < n) ++a, --t;

		int d = t - s;
		a += (d + 2) / 3;
		if(d % 3 == 2) ++a;

		cout << a << endl;
	}

	return 0;
}