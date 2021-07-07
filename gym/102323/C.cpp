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
	
	int tc;
	cin >> tc;
	
	for(int cases = 1; cases <= tc; cases++){
		
		int n, d;
		cin >> n >> d;
		d++;
		
		string s;
		cin >> s;
		
		cout << "Day #" << cases << endl;
		cout << n << " " << d - 1 << endl;
		cout << s << endl;
		
		vector<int> dist(n, -1);
		dist[0] = 0;
		queue<int> Q;
		Q.push(0);
		
		while(!Q.empty()){
			int x = Q.front();Q.pop();
			for(int i = 1; i <= d; i++){
				int y = x + i;
				if(y < n && dist[y] == -1 && s[y] != 'X'){
					dist[y] = dist[x] + 1;
					Q.push(y);
				}
			}
		}
		
		if(dist[n - 1] == -1)
			cout << 0 << endl;
		else
			cout << dist[n - 1] << endl;
		
		cout << endl;
		
	}
	

	return 0;
}