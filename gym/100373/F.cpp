#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	if(n == 1){
		cout << 0 << endl;
		return 0;
	}

	if(n == 2){


		ll d = a[1] - a[0];

		if(d >= 0){
			if(k <= d)
				a[0] += k;
			else{
				a[0] += d, k -= d;
				if(k % 2)
					a[1]++;
			}
		}
		else{
			if(k <= abs(d))
				a[1] += k;
			else{
				a[1] += abs(d), k -= abs(d);
				if(k % 2)
					a[1]++;
			}
		}

		cout << abs(a[1] - a[0]) << endl;

//		ll lo = 0, hi = k;
//		ll t = a[1] - a[0];
//
//		cout << t << endl;
//
//		ll s1 = -1, s2 = -1;
//
//		while(lo <= hi){
//			ll mid = (lo + hi) >> 1ll;
//			ll val = t - 2 * mid + k;
//
//			cout << mid << " " << val << endl;
//
//			if(val >= 0){
//				s1 = val;
//				hi = mid - 1;
//			}
//			else lo = mid + 1;
//		}
//
//		cout << endl;
//
//		lo = 0, hi = k;
//		while(lo <= hi){
//			ll mid = (lo + hi) >> 1ll;
//			ll val = t - 2 * mid + k;
//			if(val >= 0){
//				s2 = val;
//				lo = mid + 1;
//			}
//			else hi = mid - 1;
//		}
//
//		cout << s1 << " " << s2 << endl;
//
//		cout << min(abs(s1), abs(s2)) << endl;
	}
	else{
		ll sum = 0;

		for(int i = 0; i + 1 < n; i++ )
			sum += a[i + 1] - a[i];

		if(sum < 0){
			if(abs(sum) >= k)
				a[n - 1] += k;
			else
				a[n - 1] += abs(sum), k -= abs(sum), a[n - 2] += k;
		}
		else{
			if(abs(sum) >= k)
				a[0] += k;
			else
				a[0] += abs(sum), k -= abs(sum), a[1] += k;
		}

		sum = 0;
		for(int i = 0; i + 1 < n; i++)
			sum += a[i + 1] - a[i];

		cout << abs(sum) << endl;
	}


	return 0;
}