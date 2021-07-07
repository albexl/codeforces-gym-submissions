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

const int maxn = 9;

pair<char, char> a[maxn], b[maxn];
bool dp[1 << maxn][1 << maxn][26][2];
bool seen[1 << maxn][1 << maxn][26][2];
int n, m;

bool solve(int m1, int m2, int last, int pos){
	
	if(seen[m1][m2][last][pos])
		return dp[m1][m2][last][pos];
	seen[m1][m2][last][pos] = true;
	
	bool win = false;
	if(pos == 1){
		
		for(int i = 0; i < m; i++){
			if(m2 & (1 << i))
				continue;
			if(last == b[i].first - 'a')
				win |= !solve(m1, m2 | (1 << i), b[i].second - 'a', 1 - pos);
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(m1 & (1 << i))
				continue;
			if(last == a[i].first - 'a')
				win |= !solve(m1 | (1 << i), m2, a[i].second - 'a', 1 - pos);
		}
	}
	
	return dp[m1][m2][last][pos] = win;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	
	string line;
	
	for(int cases = 1; cases <= t; cases++){
		
		
		cin >> n;
		getline(cin, line);
		
		for(int i = 0; i < n; i++){
			getline(cin, line);
			a[i] = {line[0], line[line.size() - 1]};
		}
		
		cin >> m;
		getline(cin, line);
		
		for(int i = 0; i < m; i++){
			getline(cin, line);
			b[i] = {line[0], line[line.size() - 1]};
		}
		
		memset(seen, false, sizeof(seen));
		bool win = false;
		for(int i = 0; i < n; i++)
			win |= !solve(1 << i, 0, a[i].second - 'a', 1);
		
		cout << "Game " << cases << ": ";
		if(win)
			cout << "player1" << endl;
		else
			cout << "player2" << endl;
	}

	return 0;
}