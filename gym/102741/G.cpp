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

	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<string> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;
		
	while(m > 0){

		bool found = false;
		for(int i = 0; i + 1 < n; i++){

			if(a[i + 1] < a[i]){

				int pos = -1;
				for(int j = 0; j < m; j++)
					if(a[i + 1][j] < a[i][j]){
						pos = j;
						break;
					}

				for(int i = 0; i < n; i++){
					string x = "";
					for(int j = 0; j < m; j++)
						if(j != pos)
							x += a[i][j];
					a[i] = x;
				}

				m--;
				ans++;
				found = true;
				break;
			}

		}

		if(!found)
			break;
		
	}	


	cout << ans << endl;

	return 0;
}