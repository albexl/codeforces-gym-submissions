#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct segment_tree{
	
	vector<int> st;
	
	segment_tree(int n) : st(4 * n){}
	
	void update(int node, int b, int e, int p, int x){
		if(b == e)
			st[node] += x;
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;
			if(p <= m)
				update(l, b, m, p, x);
			else
				update(r, m + 1, e, p, x);
			st[node] = st[l] + st[r];
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
		return L + R;
	}
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	string s;
	int p, q;
	
	cin >> p >> q >> s;
	int n = s.size();
	
	vector<int> vals;
	
	int sum = 0;
	vals.push_back(-p);
	for(int i = 1; i <= n; i++){
		sum += (s[i - 1] == '1');
		vals.push_back(q * sum - p * (i + 1));
		vals.push_back(q * sum - p * i - p);
	}
	
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	
	int N = vals.size();
	
	int pos = lower_bound(vals.begin(), vals.end(), -p) - vals.begin();
	
	segment_tree st(N + 5);
	st.update(1, 0, N, pos, 1);
	
	ll ans = 0;
	sum = 0;
	for(int i = 1; i <= n; i++){
		sum += (s[i - 1] == '1');
		int v = q * sum - p * i - p;
		int vv = q * sum - p * (i + 1);
		pos = lower_bound(vals.begin(), vals.end(), v) - vals.begin();
		ans += st.query(1, 0, N, 0, pos - 1);
		pos = lower_bound(vals.begin(), vals.end(), vv) - vals.begin();
		st.update(1, 0, N, pos, 1);
	}
	
	cout << ans << endl;

	return 0;
}