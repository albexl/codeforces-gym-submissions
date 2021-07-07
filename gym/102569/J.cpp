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

vector<int> v;

void check(){
	vector<int> F(4), S(4);
	for(int i = 0; i < 3; i++){
		for(int j = 3; j < 6; j++){
			if(v[i] > v[j])
				F[1]++;
			else if(v[j] > v[i])
				S[1]++;
		}
	}
	
	if(v[0] + v[1] + v[2] > v[3] + v[4] + v[5])
		F[3]++;
	else if(v[0] + v[1] + v[2] < v[3] + v[4] + v[5])
		S[3]++;
	
	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 3; j++){
			for(int k = 3; k < 6; k++){
				for(int l = k + 1; l < 6; l++){
					if(v[i] + v[j] > v[k] + v[l])
						F[2]++;
					else if(v[i] + v[j] < v[k] + v[l])
						S[2]++;
					
				}
			}
		}
	}
	
	if(F[1] > S[1] && F[3] > S[3] && F[2] < S[2]){
		for(int i = 0; i < 6; i++)
			cout << v[i] << " \n"[i == 5];
	}
}

void gen(int p){
	if(p == 6){
		check();
	}
	else{
		for(int i = 1; i <= 10; i++){
			v.push_back(i);
			gen(p + 1);
			v.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	//gen(0);
	cout << 3 << endl;
	cout << "1 5 5" << endl;
	cout << 3 << endl;
	cout << "3 3 4" << endl;

	return 0;
}