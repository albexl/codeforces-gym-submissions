#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

struct segment_tree{

	vector<int> st;

	segment_tree(int n) : st( 4 * n){ }

	void update(int node, int b, int e, int p, int v){
		if(b == e)
			st[node] = max(st[node], v);
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;

			if(p <= m)
				update(l, b, m, p, v);
			else
				update(r, m + 1, e, p, v);

			st[node] = max(st[l], st[r]);
		}
	}

	int query(int node, int b, int e, int i, int j){
		if(b >= i && e <= j)
			return st[node];
		if(b > j || e < i)
			return 0;
		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;

		int L = query(l, b, m, i, j);
		int R = query(r, m + 1, e, i, j);

		return max(L, R);

	}

};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int n = (int)a.size();
	int m = (int)b.size();

	segment_tree st(m);

	for(int i = 0; i < n; i++){

		vector<pii> to_update;

		for(int j = 0; j < m; j++){
			if(a[i] == b[j]){
				int mx = st.query(1, 0, m - 1, 0, j - 1);
				to_update.push_back({j, mx + 1});
			}
		}

		for(auto &e : to_update)
			st.update(1, 0, m - 1, e.first, e.second);
	}

	cout << st.query(1, 0, m - 1, 0, m - 1) << endl;


	return 0;
}