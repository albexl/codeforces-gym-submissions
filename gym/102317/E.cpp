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
		
		cout << "Word search puzzle #" << cases << ":" << endl;
		
		int n, m;
		cin >> n >> m;
		
		vector<string> a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		int q;
		cin >> q;
		
		while(q--){
			string s;
			cin >> s;
			int sz = s.size();
			
			bool ok = false;
			
			for(int i = 0; i < n && !ok; i++){
				for(int j = 0; j < m && !ok; j++){
					
					//up
					int x = i, y = j, cnt = 0;
					while(cnt < sz){
						if(a[x][y] == s[cnt])
							x = (x - 1 + n) % n, cnt++;
						else
							break;
					}
					
					if(cnt == sz)
						ok = true;
					
					if(ok){
						cout << "U " << i + 1 << " " << j + 1 << " " << s << endl;
						break;
					}
					
					//down
					x = i, y = j, cnt = 0;
					while(cnt < sz){
						if(a[x][y] == s[cnt])
							x = (x + 1) % n, cnt++;
						else
							break;
					}
					
					if(cnt == sz)
						ok = true;
					
					if(ok){
						cout << "D " << i + 1 << " " << j + 1 << " " << s << endl;
						break;
					}
					
					//left
					x = i, y = j, cnt = 0;
					while(cnt < sz){
						if(a[x][y] == s[cnt])
							y = (y - 1 + m) % m, cnt++;
						else
							break;
					}
					
					if(cnt == sz)
						ok = true;
					
					if(ok){
						cout << "L " << i + 1 << " " << j + 1 << " " << s << endl;
						break;
					}
					
					//right
					x = i, y = j, cnt = 0;
					while(cnt < sz){
						if(a[x][y] == s[cnt])
							y = (y + 1) % m, cnt++;
						else
							break;
					}
					
					if(cnt == sz)
						ok = true;
					
					if(ok){
						cout << "R " << i + 1 << " " << j + 1 << " " << s << endl;
						break;
					}
					
				}
			}
		}
		
		cout << endl;
	}

	return 0;
}