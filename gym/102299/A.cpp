#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<ll, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int SQR = 225;
const int maxn = 5e4 + 5;

struct query
{
	int l, r, x, m, idx;
};

int a[maxn], ans[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int n, q;
	cin >> n >> q;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector<vector<query>> less(SQR);
	vector<query> great;

	for(int i = 0; i < q; i++){
		int l, r, x, m;
		cin >> l >> r >> x >> m;

		if(m < SQR)
			less[m].push_back({l, r, x, m, i});
		else
			great.push_back({l, r, x, m, i});
	}

	for(int mod = 1; mod < SQR; mod++){

		vector<vector<int>> pos(mod);

		for(int i = 1; i <= n; i++)
			pos[a[i] % mod].push_back(i);


		for(auto &e : less[mod]){
			
			if(!pos[e.x].empty()){
				int hi = upper_bound(pos[e.x].begin(), pos[e.x].end(), e.r) - pos[e.x].begin();
				int lo = lower_bound(pos[e.x].begin(), pos[e.x].end(), e.l) - pos[e.x].begin();

				ans[e.idx] = hi - lo;

			}
		}
	}

	vector<vector<int>> freq(maxn);

	for(int i = 1; i <= n; i++)
		freq[a[i]].push_back(i);

	for(auto &e : great){

		int cnt = 0;
		for(int i = e.x; i < maxn; i += e.m){
			if(!freq[i].empty()){

				int hi = upper_bound(freq[i].begin(), freq[i].end(), e.r) - freq[i].begin();
				int lo = lower_bound(freq[i].begin(), freq[i].end(), e.l) - freq[i].begin();

				cnt += hi - lo;
			}
		}

		ans[e.idx] = cnt;
	}


	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;


	return 0;
}