#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

bool valid(int x, int y, int n, int m){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		
		cout << "Image " << "#" << cases << ": ";
		
		int n, m;
		cin >> n >> m;
		
		vector<string> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];
		
		vector<string> cur(n, string(m, '.'));
		
		int ans = 0;
		bool ok = true;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(v[i][j] == '#'){
					if(!valid(i - 1, j, n, m) || v[i - 1][j] == '.')
						continue;
					if(!valid(i + 1, j, n, m) || v[i + 1][j] == '.')
						continue;
					if(!valid(i, j - 1, n, m) || v[i][j - 1] == '.')
						continue;
					if(!valid(i, j + 1, n, m) || v[i][j + 1] == '.')
						continue;
					cur[i][j] = cur[i - 1][j] = cur[i + 1][j] = cur[i][j - 1] = cur[i][j + 1] = '#';
					ans++;
				}
			}
		}
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(v[i][j] != cur[i][j])
					ok = false;
		
		if(ok)
			cout << ans << endl;
		else
			cout << "impossible" << endl;
		cout << endl;
	}


     //   cout << flush,system("pause");
	return 0;
}