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
	
	set<pii> S;
	S.insert({0, 0});
	S.insert({0, 8});
	S.insert({0, 6});
	S.insert({2, 4});
	S.insert({2, 5});
	S.insert({2, 9});
	S.insert({9, 0});
	S.insert({9, 8});
	S.insert({9, 6});
	S.insert({8, 0});
	S.insert({8, 6});
	S.insert({8, 8});
	S.insert({3, 0});
	S.insert({3, 6});
	S.insert({3, 8});
	S.insert({4, 0});
	S.insert({4, 6});
	S.insert({4, 8});
	S.insert({7, 0});
	S.insert({7, 6});
	S.insert({7, 8});
	S.insert({5, 2});
	S.insert({6, 2});
	
	vector<int> ALL = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vector<int> L = {2, 0, 1, 0, 1, 1, 2, 0, 2, 1};
	vector<int> R = {2, 2, 1, 2, 2, 1, 1, 2, 2, 2};
	
	int q;
	cin >> q;
	while(q--){
		char x, y;
		cin >> x >> y;
		int a = x - '0';
		int b = y - '0';
		
		int total = ALL[a] + ALL[b];
		pii g = {a, b};
		if(S.find(g) != S.end())
			total -= L[b];
		
		cout << total << endl;
	}
	
	return 0;
}