#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("drunkard.in", "r", stdin);
	freopen("drunkard.out", "w", stdout);

	int c = 2;
	for(int p2 = 1; p2 <= 128; c += p2, p2 *= 2);
	int b = c - 2 - 128;

	int p, q;
	while(cin >> p >> q && p + q)
	{
		cout << c << endl;
		for(int i = 1; i <= b; ++i)
			cout << i + i << " " << i + i + 1 << endl;

		for(int i = b; i < b + p; ++i)
			cout << c - 1 << " " << c - 1 << endl;
		for(int i = b + p; i < b + q; ++i)
			cout << c << " " << c << endl;
		for(int i = b + q; i < b + b + 1; ++i)
			cout << 1 << " " << 1 << endl;
	}

	return 0;
}