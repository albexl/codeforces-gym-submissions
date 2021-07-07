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
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		
		
		vector<int> pos;
		for(int i = 0; i < n; i++){
			if(a[i] != b[i])
				pos.push_back(i);
		}
		
		if(pos.size() == 0){
			cout << "YES" << endl;
			continue;
		}
		
		if(pos.size() == 1){
			cout << "NO" << endl;
			continue;
		}
	
		
		bool ok = true;
		int sz = pos.size();
		
		for(int i = 0; i < sz; i++)
			if(b[pos[i]] != a[pos[(i + 1) % sz]])
				ok = false;
		
		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}