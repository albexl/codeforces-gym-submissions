#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

//#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<int> d(n);
	
	for(int i = 0; i < n; i++)
		cin >> d[i];
	
	const int maxn = 1e6 + 1;
	
	vector<bool> can(maxn);
	vector<int> last(maxn, -1);
	
	can[0] = true;
	for(int i = 1; i < maxn; i++){
		for(int j = 0; j < n; j++){
			if(i - d[j] >= 0 && can[i - d[j]]){
				can[i] = true;
				last[i] = j;
			}
		}
	}
	
	vector<int> cands;
	
	for(int i = 1; i < maxn; i++)
		if(can[i])
			cands.push_back(i);
	
	if(cands.size() == 0){
		cout << 2 << endl;
		cout << -1 << endl;
		return 0;
	}
	
	int lo = 0, hi = cands.size() - 1, ans = -1;
	int L = 1;
	int R = maxn - 1;
	bool found = false;
	
	
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		vector<int> v(n);
		
		
		//cout << L << " " << R << " :" << endl;
		
		int x = cands[mid];
		while(x > 0){
			v[last[x]]++;
			x -= d[last[x]];
		}
		
		cout << 1 << endl;
		for(int i = 0; i < n; i++)
			cout << v[i] << " \n"[i + 1 == n];
		cout.flush();
		
		string A;
		cin >> A;
		
		if(A == "yellow"){
			ans = cands[mid];
			found = true;
			break;
		}
		else if(A == "green"){
			L = cands[mid] + 1;
			lo = mid + 1;
		}
		else{
			R = cands[mid] - 1;
			hi = mid - 1;
		}
		
	}
	
	//cout << L << " " << R << endl;
	
	if(!found){
		if(R == L){
			ans = L;
		}
	}
	
	
	cout << 2 << endl;
	cout << ans << endl;
	

	return 0;
}