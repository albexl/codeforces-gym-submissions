#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> tri;

const int oo = 1e9;

struct segment_tree{

	vector<tri> st;

	segment_tree(int n) : st(4 * n){ }

	void update(int node, int b, int e, int p, int v){
		if(b == e){
			st[node] = {v, {v, v}};
		}
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;

			if(p <= m)
				update(l, b, m, p, v);
			else
				update(r, m + 1, e, p, v);

			st[node].first = st[l].first + st[r].first;
			st[node].second.first = max(st[l].second.first, st[r].second.first);
			st[node].second.second = min(st[l].second.second, st[r].second.second);
		}
	}

	tri query(int node, int b, int e, int i, int j){
		if(b >= i && e <= j)
			return st[node];
		if(b > j || e < i)
			return {0, {-1, oo}};

		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;

		auto L = query(l, b, m, i, j);
		auto R = query(r, m + 1, e, i, j);


		int s = L.first + R.first;
		int mx = max(L.second.first, R.second.first);
		int mn = min(L.second.second, R.second.second);

		return {s, {mx, mn}};

	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	segment_tree st(n);

	for(int i = 1, x; i <= n; i++){
		cin >> x;
		st.update(1, 1, n, i, x);
	}

	while(q--){
		int t;
		cin >> t;
		if(t == 2){
			int p, v;
			cin >> p >> v;
			st.update(1, 1, n, p, v);
		}
		else{
			int l, r;
			cin >> l >> r;
			auto ans = st.query(1, 1, n, l, r);
			cout << ans.first - ans.second.first - ans.second.second << endl;
		}
	}


	return 0;
}