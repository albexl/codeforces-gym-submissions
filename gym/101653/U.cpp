#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		vector<string> a(n), b(n);
		
		for(int i = 0; i < n; i++)
			cin >> a[i];
			
		for(int i = 0; i < n; i++)
			cin >> b[i];
			
		set<string> A, B;
		vector<int> groups;
		int sz = 0;
		
		for(int i = 0; i < n; i++){
			sz++;
			if(a[i] == b[i]){
				if(A.size() == 0 && B.size() == 0){
					groups.push_back(sz);
					sz = 0;
				}
			}
			else{
				
				if(A.find(b[i]) == A.end())
					B.insert(b[i]);
				else
					A.erase(A.find(b[i]));
				
				if(B.find(a[i]) == B.end())
					A.insert(a[i]);
				else
					B.erase(B.find(a[i]));
				
				if(A.size() == 0 && B.size() == 0){
					groups.push_back(sz);
					sz = 0;
				}
			}
		}
		
		if(sz != 0)
			groups.push_back(sz);
		
		for(int i = 0; i < (int)groups.size(); i++)
			cout << groups[i] << " \n"[i + 1 == (int)groups.size()];
	}

	return 0;
}