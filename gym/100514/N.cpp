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
	
	map<int, char> mp;
	
	
	int num = 0;
	
	for(char c = 'a'; c <= 'h'; c += 2){
		mp[num] = c;
		mp[num + 1] = c + 1;
		num += 8;
	}
	
	num = 4;
	
	for(char c = 'i'; c <= 'p'; c += 2){
		mp[num] = c;
		mp[num + 1] = c + 1;
		num += 8;
	}
	
	num = 2;
	
	for(char c = 'q'; c <= 'x'; c += 2){
		mp[num] = c;
		mp[num + 1] = c + 1;
		num += 8;
	}
	
	mp[6] = 'y';
	mp[7] = 'z';
	
	//a = 0
	//b = ? 1
	//c = 8
	//d = ? 9
	//e = 16
	//f = 17
	//g = ? 24
	//h = 25
	//i = 4
	//j = ? 5
	//k = ? 12
	//l = ? 13
	//m = 20
	//n = ? 21
	//o = 28
	//p = ? 29
	//q = ? 2
	//r = 3
	//s = 10
	//t = 11
	//u = 18
	//v = ? 19
	//w = ? 26
	//x = ? 27
	//y = 6
	//z = 7
	
	int n;
	cin >> n;
	for(int i = 0, x; i < n; i++){
		cin >> x;
		cout << mp[x];
	}
		
	cout << endl;

	return 0;
}