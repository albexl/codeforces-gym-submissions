#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<char> t(n + 1);
		for(int i = 1; i <= n; i++)
			cin >> t[i];
		int last = k;
		int ans = 0;
		for(int i = 0; i < m; i++){
			char c;
			cin >> c;
			if(c == 'A')
				last = max(last, n);
			else{
				int x;
				cin >> x;
				if(x <= last && t[x] == 'S')
					ans++;
				last = max(last, x);
			}
		}
		
		cout << ans << endl;
	}

	return 0;
}