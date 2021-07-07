#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}


 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("dislodging_logs_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	string a, b;
	cin >> n >> a >> b;

	vector<int> pos;

	for(int i = 1; i < n; i++){
		if(a[i] > b[i]){
			cout << "YES" << endl;
			cout << 1 << " " << i + 1 << endl;
			return 0;
		}
	}

	if(n == 2){
		swap(a[0], a[1]);
		swap(b[0], b[1]);

		if(a > b){
			cout << "YES" << endl;
			cout << 1 << " " << 2 << endl;
		}
		else
			cout << "NO" << endl;
	}
	else{
		if(a <= b)
			cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			cout << 2 << " " << 3 << endl;
		}
	}

	return 0;
}