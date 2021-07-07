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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		
		int s1 = 0, s2 = 0, s3 = 0;
		
		for(int i = 0; i < n; i++){
			if(i + 1 < n && s[i] == 'T' && s[i + 1] == 'J')
				s1++;
			if(i + 1 < n && s[i] == 's' && s[i + 1] == 'i')
				s2++;
			if(i + 2 < n && s[i] == 'l' && s[i + 1] == 'o' && s[i + 2] == 'g')
				s3++;
		}
		
		cout << s1 << " " << s2 << " " << s3 << endl;
	}

	return 0;
}