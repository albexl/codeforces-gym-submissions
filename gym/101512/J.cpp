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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int tc;
	cin >> tc;
	
	cout << tc << endl;
	
	while(tc--){
		
		string s;
		cin >> s;
		
		vector<vector<char>> a(210, vector<char>(110));
		
		for(int i = 0; i < 210; i++)
			for(int j = 0; j < 110; j++)
				a[i][j] = '#';
		
		vector<int> dx = {0, 1, 0, -1};
		vector<int> dy = {1, 0, -1, 0};
		
		int x = 105, y = 0;
		int dir = 0;
		
		
		for(auto &c : s){
			if(c == 'R')
				dir++, dir %= 4;
			else if(c == 'L')
				dir--, dir += 4, dir %= 4;
			else if(c == 'B')
				dir += 2, dir %= 4;
			x += dx[dir];
			y += dy[dir];
			a[x][y] = '.';
		}
		
		string border = "";
		
		int m = 0;
		
		vector<vector<char>> rows;
		for(int i = 0; i < 210; i++){
			int pos = -1;
			for(int j = 0; j < 110; j++)
				if(a[i][j] == '.')
					pos = j;
					
			if(pos != -1){
				rows.push_back(a[i]);
				m = max(m, pos + 1);
			}
		}
		
		m += 1;
		for(int i = 0; i < m; i++)
			border += "#";
		
		cout << rows.size() + 2 << " " << m << endl;
		
		cout << border << endl;
		for(int i = 0; i < rows.size(); i++){
			for(int j = 0; j < m; j++)
				cout << rows[i][j];
			cout << endl;
		}
			
		
		cout << border << endl;
			
		
	}
	

	return 0;
}