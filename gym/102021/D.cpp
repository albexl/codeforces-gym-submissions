#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a; cin >> n;

	int x = 0, y = 1000000000;
	while(n--)
	{
		cin >> a;

		y = min(y, a);
		if(y < x)
		{
			cout << 0 << endl;
			return 0;
		}
		swap(x, y);
		x = a - x;
		y = a - y;
	}

	cout << y - x + 1 << endl;

	return 0;
}