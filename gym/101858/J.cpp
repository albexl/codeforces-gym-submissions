#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

struct segment_tree{
	
	vector<int> st;
	
	segment_tree(int n) : st(4 * n){
		
	}
	
	void update(int node, int b, int e, int p){
		if(b == e){
			st[node]++;
		}
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;
			if(p <= m)
				update(l, b, m, p);
			else
				update(r, m + 1, e, p);
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
	
	const int N = 1e6 + 5;
	
	segment_tree st(N);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cout << n - st.query(1, 0, N - 2, x, N - 2) << endl;
		st.update(1, 0, N - 2, x);
	}
	
	

	return 0;
}