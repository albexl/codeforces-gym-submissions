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
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxb = 50;

vector<int> boxes[maxb][maxb];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	freopen("zeros.in", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int t;
	cin >> t;

	while(t--){

		int x, y, m, k;
		cin >> x >> y >> m >> k;


		if(x + y <= 20){

			int N = x + y;
			int ans = 0;

			for(int i = 1; i < (1 << N); i++){
				int b = __builtin_popcount(i);
				if(b == x && (i % m >= k) && ( (i >> (N - 1)) & 1) )
					++ans;
			}

			cout << ans << endl;
		}
		else{

			int sz1 = (x + y) / 2;
			int sz2 = x + y - sz1;

			ll ans = 0;

			vector<int> v;

			for(int i = 1; i < (1 << sz1); i++){
				if((i >> (sz1 - 1)) & 1)
					v.push_back(i);
			}

			for(int i = 0; i < maxb; i++)
				for(int j = 0; j < maxb; j++)
					boxes[i][j].clear();

			for(int i = 0; i < (1 << sz2); i++){
				int b = __builtin_popcount(i);
				boxes[b][sz2 - b].push_back(i % m);
			}

			for(int val : v){
				int o = __builtin_popcount(val);
				int z = sz1 - o;

				if(o > x || z > y)
					continue;

				auto &vec = boxes[x - o][y - z];

				ll num = ((ll)val) << sz2;

				num %= m;

				int p1 = lower_bound(vec.begin(), vec.end(), m - num) - vec.begin();
				int p2 = lower_bound(vec.begin(), vec.end(), k - num) - vec.begin();

				ans += p1 - p2;
				ans += vec.size() - (lower_bound(vec.begin(), vec.end(), m + k - num) - vec.begin());

			}

			cout << ans << endl;
		}
	}

	return 0;
			
}