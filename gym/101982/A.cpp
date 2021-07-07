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
	
	int k;
	cin >> k;
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int ans = 0;
	int s1 = 0, s2 = 0, s3 = 0;
	
	
	for(int i = 0; i < n; i++){
		if(a[i] == b[i])
			s3++;
		else
			s2++;
	}
		
	ans += min(k, s3);
	k -= ans;
	
	ans += max(0, s2 - k);
	
	cout << ans << endl;

	return 0;
}