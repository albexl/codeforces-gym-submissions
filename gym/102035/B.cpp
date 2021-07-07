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

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	map<int, int> M;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] %= m;
		M[a[i]]++;
	}
		
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	
	
	int ans = 0;
	
	for(int i = 1; i < n; i++){
		if(M[a[b[i]]] == n - i + 1)
			break;
		M[a[b[i]]]--;
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}