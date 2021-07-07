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

const int oo = 1e6;

struct segment_tree{
	
	vector<int> st;
	segment_tree(int n) : st(4 * n, oo){ }
	
	void update(int node, int b, int e, int pos, int val){
		if(b == e)
			st[node] = min(st[node], val);
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;
			
			if(pos <= m)
				update(l, b, m, pos, val);
			else
				update(r, m + 1, e, pos, val);
			
			st[node] = min(st[l], st[r]);
		}
	}
	
	int query(int node, int b, int e, int i, int j){
		if(b >= i && e <= j)
			return st[node];
		if(b > j || e < i)
			return oo;
		
		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
		
		int L = query(l, b, m, i, j);
		int R = query(r, m + 1, e, i, j);
		
		return min(L, R);
	}
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int tc;
	cin >> tc;
	
	while(tc--){
		int n;
		cin >> n;
		
		vector<pair<int, pii>> v(n);
		
		for(int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second.first >> v[i].second.second;
		
		sort(v.begin(), v.end());
		
		segment_tree st(n);
		
		int ans = 0;
		
		for(int i = 0; i < n; i++){
			int a = v[i].first;
			int b = v[i].second.first;
			int c = v[i].second.second;
			
			if(st.query(1, 1, n, 1, b - 1) > c)
				ans++;
			
			st.update(1, 1, n, b, c);
			
		}
		
		cout << ans << endl;
		
	}

	return 0;
}