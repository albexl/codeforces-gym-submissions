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
	
	vector<ll> st;
	
	segment_tree(int n) : st(4 * n){ }
	
	void update(int node, int b, int e, int pos, ll val){
		if(b == e)
			st[node] = val;
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;
			
			if(pos <= m)
				update(l, b, m, pos, val);
			else
				update(r, m + 1, e, pos, val);
			
			st[node] = st[l] + st[r];
		}
	}
	
	ll query(int node, int b, int e, int i, int j){
		if(b >= i && e <= j)
			return st[node];
		if(b > j || e < i)
			return 0;
		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
		
		ll L = query(l, b, m, i, j);
		ll R = query(r, m + 1, e, i, j);
		
		return L + R;
	}
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, q;
	cin >> n >> m >> q;
	
	vector<string> v(n);
	segment_tree st(n);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	map<string, ll> bar;
	for(int i = 0; i < m; i++){
		string s;
		ll x;
		cin >> s >> x;
		bar[s] = x;
	}
	
	for(int i = 0; i < n; i++)
		st.update(1, 0, n - 1, i, bar[v[i]]);
	
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int pos;
			cin >> pos;
			pos--;
			string s;
			cin >> s;
			st.update(1, 0, n - 1, pos, bar[s]);
		}
		else{
			int l, r;
			cin >> l >> r;
			l--, r--;
			ll ans = st.query(1, 0, n - 1, l, r);
			
			//cout << ans << endl;
			
			if(ans <= 1ll * (r - l + 1) * 30)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}

	return 0;
}