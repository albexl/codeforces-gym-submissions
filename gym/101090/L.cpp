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
	
	int n;
	cin >> n;
	
	vector<int> b, r;
	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int m = s.size() - 1;
		int num = 0;
		for(int j = 0; j < m; j++)
			num = num * 10 + s[j] - '0';
		if(s[m] == 'B')
			b.push_back(num);
		else
			r.push_back(num);
	}
	
	sort(b.rbegin(), b.rend());
	sort(r.rbegin(), r.rend());
	
	int ans = 0;
	
	n = b.size();
	int m = r.size();
	
	int sum = 0;
	
	for(int i = 0; i < min(n, m); i++){
		sum += b[i] + r[i];
		ans = max(ans, sum - (i + 1) * 2);
	}
	
	cout << ans << endl;

	return 0;
}