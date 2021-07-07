#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<vector<int>> graph;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const ll maxn = 1e5 + 5;

	ll n;
	cin >> n;
	vector<ll> freq(maxn), a(n);

	ll ans = -1, mx = -1;

	for(int i = 0; i < n; i++)
		cin >> a[i], freq[a[i]]++, mx = max(mx, a[i]);

	ans = freq[mx] * mx;

	for(int i = 0; i < n; i++){

//		cout << ans << " " << mx << endl;

		if(i != 0){
			if(a[i] > 0){

				freq[a[i]]--;
				a[i]--;
				freq[a[i]]++;

				freq[a[i - 1]]--;
				a[i - 1]++;
				freq[a[i - 1]]++;

				ll n_mx = mx;

				if(a[i - 1] > n_mx)
					n_mx = a[i - 1];

				if(freq[n_mx] == 0)
					ans = min(ans, (n_mx - 1) * freq[n_mx - 1]);
				else
					ans = min(ans, n_mx * freq[n_mx]);

				freq[a[i - 1]]--;
				a[i - 1]--;
				freq[a[i - 1]]++;

				freq[a[i]]--;
				a[i]++;
				freq[a[i]]++;

			}
		}

		if(i != n - 1){
			if(a[i] > 0){
				freq[a[i]]--;
				a[i]--;
				freq[a[i]]++;

				freq[a[i + 1]]--;
				a[i + 1]++;
				freq[a[i + 1]]++;

				ll n_mx = mx;

				if(a[i + 1] > n_mx)
					n_mx = a[i + 1];

				if(freq[n_mx] == 0)
					ans = min(ans, (n_mx - 1) * freq[n_mx - 1]);
				else
					ans = min(ans, n_mx * freq[n_mx]);

				freq[a[i + 1]]--;
				a[i + 1]--;
				freq[a[i + 1]]++;

				freq[a[i]]--;
				a[i]++;
				freq[a[i]]++;
			}
		}

	}

	cout << ans << endl;

	return 0;
}