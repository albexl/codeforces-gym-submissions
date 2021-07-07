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

	int n;
	cin >> n;

	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	stack<int> st;

	vector<int> ans(n);
	for(int i = 0; i < n; i++)
		ans[i] = min(n - 1, i + v[i]);


	for(int i = n - 1; i >= 0; i--){
		while(!st.empty() && v[st.top()] <= v[i])
			st.pop();

		int f = -1;
		if(st.empty())
			f = n - 1;
		else
			f = st.top() - 1;

		ans[i] = min(ans[i], f);
		st.push(i);

	}


	for(int i = 0; i < n; i++)
		cout << ans[i] - i << " \n"[i + 1 == n];


	return 0;
}