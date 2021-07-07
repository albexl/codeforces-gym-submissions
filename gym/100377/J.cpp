#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<vector<int>> mat;

typedef complex<ll> point;

ll cross(point a, point b) { return imag(conj(a) * b); }

ll dot(point a, point b) { return real(conj(a) * b); }

ll area2(point a, point b, point c) { return cross(b - a, c - a); }

namespace std
{
	bool operator<(const point &a, const point &b)
	{
		return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
	}
}

const ll oo = 0x3f3f3f3f3f3f3f3f;


struct hull : vector<point>
{
	void add_point(point p)
	{
		for (int s = size(); s > 1; --s)
			if (area2(at(s - 2), at(s - 1), p) > 0) break;
			else pop_back();
		push_back(p);
	}

	ll max_dot(point p)
	{
		int lo = 0, hi = (int) size() - 1, mid;

		while (lo < hi)
		{
			mid = (lo + hi) / 2;

			if (dot(at(mid), p) <= dot(at(mid + 1), p))
				lo = mid + 1;
			else hi = mid;
		}

		return dot(at(lo), p);
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pii> a(n);

	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	vector<pii> b;

	for(int i = 0; i < n; i++){
		while(b.size() && b.back().second <= a[i].second)
			b.pop_back();
		b.push_back(a[i]);
	}

//	for(auto &rect : b)
//		cout << rect.first << " " << rect.second << endl;

	hull uh;

	int m = b.size();
	vector<ll> dp(m + 1);

	dp[0] = 0;


	for(int i = 1; i <= m; i++){
		uh.add_point(point(dp[i - 1], b[i - 1].second));

//		cout << i << " :" << endl;
//
//		for(auto &p : uh)
//			cout << p << endl;
//		cout << endl;
//
//		cout << "insert " << dp[i - 1] << " " << b[i - 1].second << endl;

		dp[i] = -uh.max_dot(point(-1, -b[i - 1].first));

//		cout << dp[i] << endl;
	}

	cout << dp[m] << endl;

	return 0;
}