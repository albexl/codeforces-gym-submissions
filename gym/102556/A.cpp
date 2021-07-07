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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}




int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	
	string s;
	cin >> s;

	int n = s.size();
	vector<char> a(2 * n);
	for(int i = 0; i < n; i++)
		a[i] = a[i + n] = s[i];

	int cnt = 0;
	int ans = 5 * n;

	for(auto &c : s)
		if(c == 'X')
			cnt++;

	if(cnt <= 1){
		cout << 0 << endl;
		return 0;
	}

	vector<int> pos;
	for(int i = 0; i < 2 * n; i++)
		if(a[i] == 'X')
			pos.push_back(i);

	for(int i = 0; i + cnt - 1 < pos.size(); i++)
		ans = min(ans, pos[i + cnt - 1] - pos[i] + 1 - cnt);
	

	cout << ans << endl;


	return 0;
}