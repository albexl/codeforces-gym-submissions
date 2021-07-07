#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

//#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	srand(time(0));
	
	int n, m;
	cin >> n;
	
	//n = rand() % 20 + 1;
	
	vector<pair<pii, pii>> a;
	vector<int> ans(n);
	
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		//x = rand() % 20 + 1;
		//y = rand() % 20 + 1;
		a.push_back({{x, 0}, {i, y}});
	}
	
	cin >> m;
	//m = rand() % 20 + 1;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		//x = rand() % 20 + 1;
		//y = rand() % 20 + 1;
		a.push_back({{x, 1}, {i, y}});
	}
	
	sort(a.rbegin(), a.rend());
	set<pii> S;
	
	//cout << n << " " << m << endl;
	
	//for(auto &e : a){
	//	int x = e.first.first;
	//	int tp = e.first.second;
	//	int idx = e.second.first;
	//	int y = e.second.second;
		
	//	cout << x << " " << y << " " << idx << " " << tp << endl;
		
	//}
	
	//cout << endl;
	
	for(auto &e : a){
		
		int x = e.first.first;
		int tp = e.first.second;
		int idx = e.second.first;
		int y = e.second.second;
		
		
		if(tp == 0){
			
			if(S.size() == 0){
				cout << -1 << endl;
				return 0;
			}
			
			auto mx = *S.rbegin();
			if(mx.first < y){
				cout << -1 << endl;
				return 0;
			}
			
			auto it = S.lower_bound(pii(y, 0));
			
			if(it == S.end()){
				cout << -1 << endl;
				return 0;
			}
			
			ans[idx] = (*it).second + 1;
			S.erase(it);
		}
		else{
			S.insert(pii(y, idx));
		}
	}
	
	
	for(int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i + 1 == n];

	return 0;
}

/*
3
1 2
2 3
3 3
3
1 1
1 3
2 5
*/

/*
9 19
20 17 16 1
20 17 0 1
18 13 14 1
18 15 13 1
18 19 3 1
18 19 7 0
17 12 0 0
16 7 2 1
15 16 1 0
14 1 8 1
14 9 4 1
14 7 2 0
13 2 10 1
12 19 18 1
12 3 8 0
12 15 3 0
11 8 1 1
10 15 12 1
10 11 6 1
10 5 6 0
10 1 5 0
8 6 5 1
7 13 11 1
5 2 7 1
3 17 15 1
2 19 17 1
2 2 9 1
1 9 4 0

*/