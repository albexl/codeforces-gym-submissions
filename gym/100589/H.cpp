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

struct segment_tree{
	
	vector<int> st;
	
	segment_tree(int n) : st(4 * n){ }
	
	void update(int node, int b, int e, int pos, int x){
		if(b == e)
			st[node] += x;
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;
			
			if(pos <= m)
				update(l, b, m, pos, x);
			else
				update(r, m + 1, e, pos, x);
			
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

	//mt19937 rng(5);
	//srand(time(0));
	
	int n;
	ll k;
	cin >> n >> k;
	
	
	vector<int> a(n), vals(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		vals[i] = a[i];
	}
	
	if(k == 0){
		cout << 1ll * n * (n + 1) / 2ll << endl;
		return 0;
	}

	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	int N = vals.size();
	
	segment_tree st(N);
	ll ans = 0, inv = 0;
	int hi = 0;
	for(int i = 0; i < n; i++){
		while(inv < k && hi < n){
			int p = lower_bound(vals.begin(), vals.end(), a[hi]) - vals.begin();
			st.update(1, 0, N - 1, p, +1);
			inv += 1ll * st.query(1, 0, N - 1, p + 1, N - 1);
			hi++;
		}
		
		if(inv >= k)
			ans += n - hi + 1;
		
		int p = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
		st.update(1, 0, N - 1, p, -1);
		inv -= 1ll * st.query(1, 0, N - 1, 0, p - 1);
	}
	
	cout << ans << endl;
	
	return 0;
}