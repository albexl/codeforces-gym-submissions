#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
	
	string s;
	cin >> s;
	
	int s1 = 0, s2 = 0;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == 'C'){
			if(s1 == 2){
				cout << "P";
				s1 = 0;
			}
			else{
				s1++;
				cout << "B";
			}
			s2 = 0;
		}
		else{
			s1 = 0;
			if(s2 == 2){
				cout << "T";
				s2 = 0;
			}
			else{
				s2++;
				cout << "D";
			}
		}
	}
	
	cout << endl;

	return 0;
}