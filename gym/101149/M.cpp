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

    //again
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	srand(time(0));
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	random_shuffle(a.begin(), a.end());
	
	string ans;
	
	cout << "? " << a[0] << " " << a[1] << endl;
	
	int mx = 0, smx = 0;
	
	cin >> ans;
	if(ans == "<")
		mx = a[1], smx = a[0];
	else
		mx = a[0], smx = a[1];
	
	for(int i = 2; i < n; i++){
		cout << "? " << a[i] << " " << mx << endl;
		cin >> ans;
		if(ans == ">")
		{
			smx = mx;
			mx = a[i];
			continue;
		}
		cout << "? " << a[i] << " " << smx << endl;
		cin >> ans;
		if(ans == ">")
			smx = a[i];
	}
	
	cout << "! " << smx << endl;

	return 0;
}