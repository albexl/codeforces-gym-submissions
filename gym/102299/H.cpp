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

ll sqr(ll x){
	return x * x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	const ll oo = 0x3f3f3f3f3f3f3f3f;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> courses(n, vector<int>(m + 1, -1));

	for(int i = 0; i < n; i++){
		int k;
		cin >> k;

		for(int j = 0; j < k; j++){
			int x, y;
			cin >> x >> y;
			courses[i][x] = y;
		}
	}


	for(int i = 0; i < n; i++){

		int closest = -1;
		ll cost = oo;

		for(int j = 0; j < n; j++){

			if(i != j){

				ll sum = 0;
				bool found = false;

				for(int k = 1; k <= m; k++)
					if(courses[i][k] != -1 && courses[j][k] != -1)
						sum += sqr(1ll * (courses[i][k] - courses[j][k]) ), found = true;

				if(found){

					if(sum < cost){
						cost = sum;
						closest = j;
					}
				}
			}
		}

		bool found = false;

		int take = -1;
		int grade = -1;

		for(int k = 1; k <= m; k++){

			if(courses[i][k] == -1 && courses[closest][k] != -1){
				found = true;
				if(courses[closest][k] > grade){
					grade = courses[closest][k];
					take = k;
				}
			}
		}

		cout << take << endl;


	}


	return 0;
}