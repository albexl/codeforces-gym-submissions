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
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef vector<ll> vec;
typedef vector<vec> mat;

bool leap(ll x){
	return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int b = 0, s = 0, g = 0;

	for(int i = 0; i < n; i++){
		string x;
		cin >> x;

		int cnt = 1;
		if(x == "silver")
			cnt = 2;
		if(x == "gold")
			cnt = 4;

		if(cnt == 1){
			b++;
			continue;
		}

		if(cnt == 2){
			s++;
			if(!b){
				cout << "NO" << endl;
				return 0;
			}
			b--;
			continue;
		}

		g++;
		if(s >= 1 && b >= 1){
			s--;
			b--;
			continue;
		}

		if(b >= 3){
			b -= 3;
			continue;
		}

		cout << "NO" << endl;
		return 0;
	}


	cout << "YES" << endl;

	return 0;
}