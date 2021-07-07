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


	int t;
	cin >> t;

	for(int cases = 1; cases <= t; cases++){
		int n, k;
		cin >> n >> k;

		vector<pii> p(n);
		vector<int> cnt(k);

		for(int i = 0; i < n; i++)
			cin >> p[i].first >> p[i].second;

		string ans(n, '.');

		for(int i = 0; i < n; i++){
				
			int p = -1;

			do{
				p = randint(0, k - 1);
			}while(cnt[p] == n / k);

			cnt[p]++;
			ans[i] = (char)(p + 'A');
		}

		cout << "Case #" << cases << ": " << ans << endl;
	}


	return 0;
}