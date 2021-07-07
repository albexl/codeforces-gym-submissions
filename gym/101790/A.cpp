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

	int n;
	cin >> n;
	
	vector<ll> a(n + 1), b(n + 1);
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	
	for(int i = 1; i <= n; i++){
		if(a[i] < b[i]){
			for(int j = 1; j <= n && a[i] < b[i]; j++){
				if(i != j && a[j] > b[j]){
					
					//cout << i << " " << j << " " << a[j] << " " << b[j] << endl;
					
					ll rem = a[j] - b[j];
					ll dif = b[i] - a[i];
					ll mn = min(dif, rem);
					
					b[j] += mn;
					b[i] -= mn;
					cout << j << " " << i << " " << mn << endl;
				}
			}
		}
	}

	return 0;
}