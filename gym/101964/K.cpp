#include <bits/stdc++.h>
 
using namespace std;
 
// #define endl '\n'
 
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int maxl = 20;
const int oo = 2e9;
 
struct segment_tree{
 
	vector<vector<int>> st;
	int n;
 
	void rebuild(vector<pii> &v){
 
		n = (int)v.size();
		st = vector<vector<int>>(4 * n);
 
		build(1, 0, n - 1, v);
	}
 
	void build(int node, int b, int e, vector<pii> &values){
		if(b == e)
			st[node].push_back(values[b].second);
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;
 
			build(l, b, m, values);
			build(r, m + 1, e, values);
 
			st[node].resize(e - b + 1);
 
			merge(st[l].begin(), st[l].end(), st[r].begin(), st[r].end(), st[node].begin());
 
		}
	}
 
	int query(int node, int b, int e, int i, int j, int lo, int hi){
		if(b >= i && e <= j){
			int R = upper_bound(st[node].begin(), st[node].end(), hi) - st[node].begin();
			int L = lower_bound(st[node].begin(), st[node].end(), lo) - st[node].begin();
			return R - L;
		}
 
		if(b > j || e < i)
			return 0;
 
		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
 
		int L = query(l, b, m, i, j, lo, hi);
		int R = query(r, m + 1, e, i, j, lo, hi);
 
		return L + R;
	}
 
};
 
 
struct data{
 
	vector<pair<segment_tree, vector<pii> > > d;
	int s;
 
	data() : d(maxl){ s = 0; }
 
	void insert(pii val){
 
		// cout << "insert " << val.first << " " << val.second << endl;
 		
 		s++;

 		int p = __lg(s & -s);

 		// cout << "s " << s << endl;
 		// cout << (s & -s) << endl;
 		// cout << "p " << p << endl;

		d[p].second.push_back(val);

		// cout << "here" << endl;
 
		for(int i = 0; i < p; i++){

			// cout << i << " insert" << endl;
			
			for(auto &el : d[i].second)
				d[p].second.push_back(el);
 
			d[i].second.clear();
		}

		d[p].first.rebuild(d[p].second);
	}
 
	int query(int xl, int xr, int yl, int yr){
 
		// cout << "query " << xl << " " << xr << " " << yl << " " << yr << " :" << endl;


 
		int ans = 0;
		for(auto &el : d){
 
			if(!el.second.empty()){
 
				int lo = lower_bound(el.second.begin(), el.second.end(), pii(xl, -1)) - el.second.begin();
				int hi = upper_bound(el.second.begin(), el.second.end(), pii(xr, oo)) - el.second.begin();
				hi--;
 
				// cout << "xxxxxxxxxxxx" << endl;
				// for(auto &p : el.second)
				// 	cout << p.first << " " << p.second << endl;
 
				// cout << "------------" << endl;
				// cout << lo << " " << hi << endl;
 
				if(lo <= hi){
					ans += el.first.query(1, 0, el.first.n - 1, lo, hi, yl, yr);
				}
			}
		}
 
		return ans;
	}
 
};
 
 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	int q;
	cin >> q;
 
 
	data UL, UR, DL, DR, P;
 
	ll ans = 0;
	int rect = 0;
 
 
	for(int i = 0; i < q; i++){
		int t;
		cin >> t;
 
		int xo = -1, yo = -1, xi = -1, yi = -1;
		cin >> xo >> yo;
 
		if(t == 2)
			cin >> xi >> yi;
 
		if(t == 1){
 
			int not_touch = 0;
 
			not_touch -= UR.query(xo + 1, oo, yo + 1, oo);
			not_touch -= UL.query(-oo, xo - 1, yo + 1, oo);
			not_touch -= DL.query(-oo, xo - 1, -oo, yo - 1);
			not_touch -= DR.query(xo + 1, oo, -oo, yo - 1);
 
			not_touch += UR.query(xo + 1, oo, -oo, oo);
			not_touch += UR.query(-oo, oo, yo + 1, oo);
			not_touch += DL.query(-oo, xo - 1, -oo, oo);
			not_touch += DL.query(-oo, oo, -oo, yo - 1);
 
			// cout << "contains rectangles" << endl;
			// cout << rect - not_touch << endl;
 
			P.insert({xo, yo});
 
			ans += 1ll * (rect - not_touch);
 
		}
		else{
 
			UR.insert({xo, yo});
			DL.insert({xi, yi});
			DR.insert({xo, yi});
			UL.insert({xi, yo});
			rect++;
 
			// cout << "contains points" << endl;
			// cout << P.query(xo, xi, yo, yi) << endl;
 
			ans += 1ll * P.query(xo, xi, yo, yi);
		}
 
		cout << ans << endl;
 
	}
 
 
	return 0;
}
 
/*
 
5
1 2 3
1 2 2
1 3 4
2 1 1 5 5
2 2 2 2 2
 
4
2 1 1 3 3
2 1 1 2 2
1 2 2
1 2 2
 
 
*/