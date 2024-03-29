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
	
	string a, b;
	cin >> a >> b;
	
	int n = a.size();
	
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	
	for(int i = 0; i < n; i++){
		if(a[i] == '.' && b[i] == '.')
			s1++;
		if(a[i] == '.' && b[i] == '#')
			s2++;
		if(a[i] == '#' && b[i] == '.')
			s3++;
		if(a[i] == '#' && b[i] == '#')
			s4++;
	}
	
	if(s2 > 0 && s3 > 0 && s4 == 0){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	string r1 = "", r2 = "";
	for(int i = 0; i < s1; i++)
		r1 += ".", r2 += ".";
	for(int i = 0; i < s2; i++)
		r1 += ".", r2 += "#";
	for(int i = 0; i < s4; i++)
		r1 += "#", r2 += "#";
	for(int i = 0; i < s3; i++)
		r1 += "#", r2 += ".";
	
	cout << r1 << endl << r2 << endl;

	return 0;
}