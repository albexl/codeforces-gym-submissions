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

const int maxn = 100000;

int idx = 1;
map<string, int> M;

bool mix(string s){
	for(int i = 0; i < (int)s.size(); i++)
		if(s[i] >= 'a' && s[i] <= 'z')
			return false;
	return true;
}

vector<int> g[maxn];
bool E[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		
		string s;
		cin >> s;
		
		if(M.find(s) == M.end())
			M[s] = idx++;
		
		if(mix(s))
			E[M[s]] = true;
		
		int k;
		cin >> k;
		
		for(int j = 0; j < k; j++){
			string x;
			cin >> x;
			if(M.find(x) == M.end())
				M[x] = idx++;
			
			if(mix(x))
				E[M[x]] = true;
			
			g[M[s]].push_back(M[x]);
			
		}
	}
	
	int ans = 1;	
		
	for(int i = 1; i < idx; i++){
		if(E[i]){
			int cnt = 1;
			for(auto &v : g[i])
				if(E[v])
					cnt++;
			ans = max(ans, cnt);
		}
	}
	
	cout << ans << endl;

	return 0;
}