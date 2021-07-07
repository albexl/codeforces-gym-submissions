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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		string s;
		cin >> n >> s >> k;
		
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(s == "odd"){
				if(i % 2 == 0)
					k--;
			}
			else{
				if(i % 2 == 1)
					k--;
			}
			
			if(k == 0){
				ans = i;
				break;
			}
		}
		
		cout << ans << endl;
	}

	

	return 0;
}