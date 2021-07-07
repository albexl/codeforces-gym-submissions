#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string a, b;
	cin >> a >> b;

	int n = (int)a.size();
	int m = (int)b.size();

	int pos = 0;

	for(int i = 0; i < n && pos < m; i++){
		if(a[i] == b[pos]){
			pos++;
		}
	}

	if(pos == m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0;
}