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
	
	void update(int node, int b, int e, int pos){
		if(b == e)
			st[node]++;
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;
			
			if(pos <= m)
				update(l, b, m, pos);
			else
				update(r, m + 1, e, pos);
			
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

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<int> vals;
		vector<int> a(n);
		
		for(int i = 0; i < n; i++){
			cin >> a[i];
			vals.push_back(a[i]);
		}
		
		cin >> n;
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			cin >> b[i];
			vals.push_back(b[i]);
		}
		
		cin >> n;
		vector<int> c(n);
		for(int i = 0; i < n; i++){
			cin >> c[i];
			vals.push_back(c[i]);
		}
		
		sort(vals.begin(), vals.end());
		vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
		
		int N = vals.size();
		segment_tree st(N);
		
		vector<ll> L(b.size()), R(b.size());
		
		for(int i = 0; i < b.size(); i++){
			if(i < a.size()){
				int p = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
				st.update(1, 0, N - 1, p);
			}
			
			int p = lower_bound(vals.begin(), vals.end(), b[i]) - vals.begin();
			L[i] = 1ll * st.query(1, 0, N - 1, 0, p);
		}
		
		st = segment_tree(N);
		
		for(int i = (int)b.size(); i < (int)c.size(); i++){
			int p = lower_bound(vals.begin(), vals.end(), c[i]) - vals.begin();
			st.update(1, 0, N - 1, p);
		}
		
		for(int i = (int)b.size() - 1; i >= 0; i--){
			if(i < c.size()){
				int p = lower_bound(vals.begin(), vals.end(), c[i]) - vals.begin();
				st.update(1, 0, N - 1, p);
			}
			int p = lower_bound(vals.begin(), vals.end(), b[i]) - vals.begin();
			R[i] = 1ll * st.query(1, 0, N - 1, p, N - 1);
		}
		
		ll ans = 0;
		for(int i = 0; i < b.size(); i++)
			ans += L[i] * R[i];
		
		cout << ans << endl;
	}

	return 0;
}