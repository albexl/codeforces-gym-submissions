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

int num(string s){
	int num = 0;
	for(int i = 0; i < (int)s.size(); i++)
		num = num * 10 + s[i] - '0';
	return num;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	int t1 = 0, t2 = 0, x1 = 0, x2 = 0, s1 = 0, s2 = 0;
	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s == "M") continue;
		if(s == "X")
			x1++, t1++, s1 += 10;
		else
			s1 += num(s), t1 += (num(s) == 10);
	}
	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s == "M") continue;
		if(s == "X")
			x2++, t2++, s2 += 10;
		else
			s2 += num(s), t2 += (num(s) == 10);
	}
	
	if(s1 > s2){
		cout << "Yuju" << endl;
	}
	else if(s2 > s1){
		cout << "Yerin" << endl;
	}
	else{
		if(t1 > t2){
			cout << "Yuju" << endl;
		}
		else if(t2 > t1){
			cout << "Yerin" << endl;
		}
		else{
			if(x1 > x2){
				cout << "Yuju" << endl;
			}
			else if(x2 > x1){
				cout << "Yerin" << endl;
			}
			else{
				cout << "Shoot-off" << endl;
			}
		}
	}
	

	return 0;
}