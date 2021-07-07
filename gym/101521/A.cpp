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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	vector<pii> a(m);
	
	map<int, int> M;
	
	for(int i = 0; i < m; ++i)
		cin >> a[i].first >> a[i].second, M[a[i].second]++;
	
	vector<int> f;
	for(auto &p : M)
		if(p.second == 2)
			f.push_back(p.first);
	
	sort(f.begin(), f.end());
	
	if(f.size()){
		if(f.back() != n){
			cout << "No" << endl;
			return 0;
		}
		
		for(int i = 0; i + 1 < (int)f.size(); i++){
			if(f[i] + 1 != f[i + 1]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	
	vector<pii> cells;
	
	for(int i = 0; i < m; i++)
		if(M[a[i].second] != 2)
			cells.emplace_back(a[i].second, a[i].first);
	
	if(cells.empty()){
		cout << "Yes" << endl;
		return 0;
	}
	
	sort(cells.begin(), cells.end());
	
	int x = cells[0].first, y = cells[0].second;
	int xo = 1, yo = 1;
	
	if(xo % 2 == x % 2){
		if(y == yo){
			cout << "No" << endl;
			return 0;
		}
	}
	else{
		if(y != yo){
			cout << "No" << endl;
			return 0;
		}
	}
	
	xo = x, yo = (y == 1 ? 2 : 1);
	
	for(int i = 1; i < (int)cells.size(); i++){
		int x = cells[i].first, y = cells[i].second;
		if(x % 2 == xo % 2){
			if(y != yo){
				cout << "No" << endl;
				return 0;
			}
		}
		else{
			if(y == yo){
				cout << "No" << endl;
				return 0;
			}
		}
		xo = x, yo = (y == 1 ? 2 : 1);
	}
	
	cout << "Yes" << endl;
	

	return 0;
}