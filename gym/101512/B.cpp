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
	
	const int oo = 3600;
	
	int t;
	cin >> t;
	while(t--){
		
		int n, s;
		cin >> n >> s;
		
		vector<int> moves(n);
		for(int i = 0; i < n; i++)
			cin >> moves[i];
		
		vector<int> d(oo + 10, -1);
		
		queue<int> Q;
		Q.push(0);
		d[0] = 0;
		
		while(!Q.empty()){
			int x = Q.front();Q.pop();
			
			for(auto &t : moves){
				int xx = x + t;
				if(xx < 0)
					xx = 0;
				else if(xx > oo)
					xx = oo;
				
				if(d[xx] == -1){
					d[xx] = d[x] + 1;
					Q.push(xx);
				}
			}
		}
		
		int ans = -oo - 5, extra = 0;
		
		for(int i = s; i <= oo; i++){
			if(d[i] != -1){
				ans = d[i];
				extra = i - s;
				break;
			}
		}
		
		cout << ans << " " << extra << endl;
		
	}

	return 0;
}