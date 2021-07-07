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
	
	int n;
	cin >> n;
	vector<pii> f(n);
	
	for(int i = 0; i < n; i++)
		cin >> f[i].first >> f[i].second;
	
	for(int i = n; i >= 1; i--){
		int count = 0;
		for(int j = 0; j < n; j++){
			if(i >= f[j].first && i <= f[j].second)
				count++;
		}
		if(count == i){
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}