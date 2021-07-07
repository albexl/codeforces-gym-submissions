#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const ll oo = 0x3f3f3f3f3f3f3f3f;

	int n;
	ll a, b;
	cin >> n >> a >> b;

	vector<ll> v(n);

	for(int i = 0; i < n; i++)
		cin >> v[i];

	ll sum = 0, opt = -oo;

	if(a < 0){
		for(int i = 0; i < n; i++)
			v[i] = -v[i];
	}


	for(int i = 0; i < n; i++){
		sum += v[i];
		opt = max(opt, sum);
		if(sum < 0)
			sum = 0;
	}


	if(a < 0)
		opt = -opt;

//	cout << opt << endl;
	cout << opt * a + b << endl;

	return 0;
}