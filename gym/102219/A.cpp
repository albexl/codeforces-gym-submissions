#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

const int maxn = 1000 + 5;

int n;
string s;
char a[maxn][maxn][2];

char change(char c, bool left){
	if(c == '.')
		return '.';
	if(left){
		if(c == '>')
			return '^';
		if(c == '<')
			return 'v';
		if(c == '^')
			return '<';
		return '>';
	}
	else{
		if(c == '>')
			return 'v';
		if(c == '<')
			return '^';
		if(c == '^')
			return '>';
		return '<';
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);



	int n;
	cin >> n >> s;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j][0];

	int m = s.size();

	for(int k = 0; k < m; k++){
		
		int x = 0, y = 0;

		if(s[k] == 'L'){
			for(int j = n - 1; j >= 0; j--)
				for(int i = 0; i < n; i++){
					a[x][y][(k + 1) % 2] = change(a[i][j][k % 2], true);
					y++;
					if(y == n){
						x++;
						y = 0;
					}
				}
		}
		else{
			for(int j = 0; j < n; j++)
				for(int i = n - 1; i >= 0; i--){
					a[x][y][(k + 1) % 2] = change(a[i][j][k % 2], false);
					y++;
					if(y == n){
						x++;
						y = 0;
					}
				}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << a[i][j][m % 2];
		cout << endl;
	}

	return 0;
}