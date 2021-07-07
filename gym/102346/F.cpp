#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int, int> pii;

struct rectangle
{
	ll xl, yl, xh, yh;
};

ll rectangle_area(vector<rectangle> &rs)
{
	vector<ll> ys; // coordinate compression
	for (auto r : rs)
	{
		ys.push_back(r.yl);
		ys.push_back(r.yh);
	}
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());

	int n = ys.size(); // measure tree
	vector<ll> C(8 * n), A(8 * n);
	function<void(int, int, int, int, int, int)> aux =
			[&](int a, int b, int c, int l, int r, int k)
			{
				if ((a = max(a,l)) >= (b = min(b,r))) return;
				if (a == l && b == r) C[k] += c;
				else
				{
					aux(a, b, c, l, (l+r)/2, 2*k+1);
					aux(a, b, c, (l+r)/2, r, 2*k+2);
				}
				if (C[k]) A[k] = ys[r] - ys[l];
				else A[k] = A[2*k+1] + A[2*k+2];
			};

	struct event
	{
		ll x, l, h, c;
	};
	// plane sweep
	vector<event> es;
	for (auto r : rs)
	{
		int l = lower_bound(ys.begin(), ys.end(), r.yl) - ys.begin();
		int h = lower_bound(ys.begin(), ys.end(), r.yh) - ys.begin();
		es.push_back({ r.xl, l, h, +1 });
		es.push_back({ r.xh, l, h, -1 });
	}
	sort(es.begin(), es.end(), [](event a, event b)
			{return a.x != b.x ? a.x < b.x : a.c > b.c;});
	ll area = 0, prev = 0;
	for (auto &e : es)
	{
		area += (e.x - prev) * A[0];
		prev = e.x;
		aux(e.l, e.h, e.c, 0, n, 0);
	}
	return area;
}

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<pii, pii>> segs;

	for(int i = 0; i < n; i++){
		int xo, yo, xi, yi;
		cin >> xo >> yo >> xi >> yi;
		segs.push_back({{xo, yo}, {xi, yi}});
	}

	int p;
	cin >> p;

	int L, D, R, U;
	cin >> L >> D >> R >> U;

	ll area = 1ll * (R - L) * (U - D);

	int lo = 1, hi = 2e5 + 5, ans = -1;

	while(lo <= hi){
		int rr = (lo + hi) >> 1;

		// cout << rr << " :" << endl;

		vector<rectangle> rects;

		for(auto &s : segs){

			int xo = s.first.first;
			int yo = s.first.second;
			int xi = s.second.first;
			int yi = s.second.second;

			// cout << xo << " " << yo << " " << xi << " " << yi << endl;
			// cout << L << " " << D << " " << R << " " << U << endl;
			
			int l = min(xo, xi) - rr;
			int r = max(xo, xi) + rr;
			int d = min(yo, yi) - rr;
			int u = max(yo, yi) + rr;

			// cout << l << " " << d << " " << r << " " << u << endl;

			l = max(l, L);
			r = min(r, R);
			d = max(d, D);
			u = min(u, U);

			// cout << "daaaa" << endl;

			// cout << l << " " << d << " " << r << " " << u << endl;

			if(r <= l || u <= d)
				continue;

			rects.push_back({1ll * l, 1ll * d, 1ll * r, 1ll * u});

		}

		// for(auto &s : rects){
		// 	cout << s.xl << " " << s.yl << " " << s.xh << " " << s.yh << endl;
		// }
		// cout << endl;

		ll ur = rectangle_area(rects);

		// cout << area << " " << ur << endl;

		if(100ll * ur >= 1ll * p * area){
			ans = rr;
			hi = rr - 1;
		}
		else lo = rr + 1;

	}


	cout << ans << endl;

	return 0;
}