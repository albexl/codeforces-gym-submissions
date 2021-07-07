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


bool final(vector<string> &a, char c){
	
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++){
			if(a[i][j] == c){
				int pos = j;
				while(pos < 6){
					if(a[i][pos] != c && a[i][pos] != '.')
						return false;
					pos++;
				}
				return true;
			}
		}
	return true;
}

void print(vector<string> &s){
	cerr << "-----------" << endl;
	for(int i = 0; i < 6; i++)
		cerr << s[i] << endl;
	cerr << "-----------" << endl;
}

int bfs(vector<string> s, char c){
	map<vector<string>, int> d;
	d[s] = 0;
	queue<vector<string>> Q;
	Q.push(s);
	
	while(!Q.empty()){
		auto u = Q.front();Q.pop();
		
		//print(u);
		
		int dst = d[u];
		if(final(u, c))
			return dst + 1;
		
		//cerr << "horizontal" << endl;
		//move horizontal
		vector<bool> seen(26);
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++){
				if(u[i][j] != '.' && !seen[u[i][j] - 'A'] && u[i][j + 1] == u[i][j]){
					
					//cerr << i << " " << j << " :" << endl;
					
					seen[u[i][j] - 'A'] = true;
					vector<string> v = u;
					int sz = 2;
					if(j + 2 < 6 && u[i][j + 2] == u[i][j])
						sz++;
					
					//move forward
					int lo = j, hi = j + sz - 1;
					while(hi < 5){
						if(v[i][hi + 1] == '.'){
							v[i][lo] = '.';
							v[i][hi + 1] = u[i][j];
							if(!d.count(v)){
								d[v] = 1 + dst;
								Q.push(v);
							}
							lo++;
							hi++;
						}
						else break;
					}
					
					//move backwards
					v = u;
					lo = j, hi = j + sz - 1;
					while(lo > 0){
						if(v[i][lo - 1] == '.'){
							v[i][hi] = '.';
							v[i][lo - 1] = u[i][j];
							if(!d.count(v)){
								d[v] = 1 + dst;
								Q.push(v);
							}
							hi--;
							lo--;
						}
						else break;
					}
				}
			}
		}
		
		//cerr << "vertical" << endl;
		//move vertical
		for(int j = 0; j < 6; j++){
			for(int i = 0; i < 5; i++){
				if(u[i][j] != '.' && !seen[u[i][j] - 'A'] && u[i + 1][j] == u[i][j]){
					seen[u[i][j] - 'A'] = true;
					vector<string> v = u;
					int sz = 2;
					if(i + 2 < 6 && u[i + 2][j] == u[i][j])
						sz++;
					
					//move down
					int lo = i, hi = i + sz - 1;
					while(hi < 5){
						if(v[hi + 1][j] == '.'){
							v[lo][j] = '.';
							v[hi + 1][j] = u[i][j];
							if(!d.count(v)){
								d[v] = 1 + dst;
								Q.push(v);
							}
							lo++;
							hi++;
						}
						else break;
					}
					
					//move backwards
					v = u;
					lo = i, hi = i + sz - 1;
					while(lo > 0){
						if(v[lo - 1][j] == '.'){
							v[hi][j] = '.';
							v[lo - 1][j] = u[i][j];
							if(!d.count(v)){
								d[v] = 1 + dst;
								Q.push(v);
							}
							hi--;
							lo--;
						}
						else break;
					}
				}
			}
		}
	}
	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	while(true){
		string c;
		cin >> c;
		
		if(c == "*")
			break;
		
		vector<string> a(6);
		for(int i = 0; i < 6; i++)
			cin >> a[i];
		
		cout << bfs(a, c[0]) << endl;
	}

	

	return 0;
}