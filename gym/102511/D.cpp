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

const int maxn = 1e6 + 5;

pii convert(string &s){
	pii ans = {0, 0};
	ans.first = s[0] == 's' ? +1 : -1;
	for(int i = 1; i < s.size(); i++)
		ans.second = ans.second * 10 + (s[i] - '0');
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	int n;
	cin >> n;
	
	vector<pii> a(n);
	
	vector<vector<int>> pos(maxn), R(maxn), L(maxn);
	vector<vector<int>> SR(maxn), SL(maxn);
	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		auto v = convert(s);
		a[i] = v;
		pos[v.second].push_back(i);
	}
	
	for(int i = 1; i < maxn; i++){
		if(pos[i].empty())
			continue;
		
		L[i].resize(pos[i].size());
		SL[i].resize(pos[i].size());
		
		for(int j = 0; j < pos[i].size(); j++){
			int val = a[pos[i][j]].first;
			SL[i][j] = val;
			if(j)
				SL[i][j] += SL[i][j - 1];
			L[i][j] = SL[i][j];
			if(j)
				L[i][j] = min(L[i][j], L[i][j - 1]);
		}
		
		R[i].resize(pos[i].size());
		SR[i].resize(pos[i].size());
		
		for(int j = (int)pos[i].size() - 1; j >= 0; j--){
			int val = a[pos[i][j]].first;
			SR[i][j] = val;
			if(j != (int)pos[i].size() - 1)
				SR[i][j] += SR[i][j + 1];
			R[i][j] = SL[i][j];
			if(j != (int)pos[i].size() - 1)
				R[i][j] = min(R[i][j], R[i][j + 1]);
		}
	}
	
	set<int> balanced;
	int cut = 0, mx = 0, cur = 0;
	
	for(int i = 1; i < maxn; i++){
		if(pos[i].empty())
			continue;
		if(SR[i][0] == 0 && R[i][0] >= 0){
			balanced.insert(i);
			cur++;
			mx++;
		}
	}
	
	for(int i = 1; i < n; i++){
		int t = a[i - 1].second;
		int p = lower_bound(pos[t].begin(), pos[t].end(), i - 1) - pos[t].begin();
		int p1 = p + 1;
		
		if(p1 == pos[t].size()){
			if(SL[t][p] == 0 && L[t][p] >= 0){
				if(!balanced.count(t)){
					cur++;
					balanced.insert(t);
				}
			}
			else{
				if(balanced.count(t)){
					balanced.erase(t);
					cur--;
				}
			}
		}
		else{
			int s_suff = SR[t][p1];
			int s_pref = SL[t][p];
			int m_suff = R[t][p1];
			int m_pref = L[t][p];
			
			if(s_suff + s_pref == 0 && m_suff - s_pref >= 0 && s_suff + m_pref >= 0){
				if(!balanced.count(t)){
					cur++;
					balanced.insert(t);
				}
			}
			else{
				if(balanced.count(t)){
					balanced.erase(t);
					cur--;
				}
			}
		}
		
		if(cur > mx){
			mx = cur;
			cut = i;
		}
	}
	
	cout << cut + 1 << " " << mx << endl;

	return 0;
}