#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX
 
typedef long long ll;
typedef pair<int, int> pii;

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	
 	int n;
 	cin >> n;
 	vector<int> v(n);
 	for(int i = 0; i < n; i++)
 		cin >> v[i];

 	int x = v[0];
 	sort(v.begin(), v.end());

 	if(x == v[n - 1])
 		cout << "S" << endl;
 	else
 		cout << "N" << endl;

	return 0;
}