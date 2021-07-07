#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX
 
typedef long long ll;
typedef pair<int, int> pii;

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	
	int n, p;

	cin >> n >> p;

	vector<string> board(n);
	for(int i = 0; i + 1 < n; i++)
		cin >> board[i];

	board[n - 1] = "*";

	int d;
	cin >> d;

	vector<pair<int, string>> deck(d);
	for(int i = 0; i < d; i++)
		cin >> deck[i].first >> deck[i].second;

	vector<int> pos(p, -1);

	int cur_card = 0;

	for(int cur_player = 0; ; cur_player = (cur_player + 1) % p){

		auto card = deck[cur_card];
		cur_card = (cur_card + 1) % d;

		if(card.first == 1){

			int j = pos[cur_player] + 1;
			while(j < n && board[j] != card.second){
				j++;
			}

			if(j == n){
				cout << cur_player + 1 << endl;
				return 0;
			}

			pos[cur_player] = j;

		}
		else if(card.first == 2){
			int j = pos[cur_player] + 1;
			while(j < n && board[j] != card.second){
				j++;
			}

			if(j == n){
				cout << cur_player + 1 << endl;
				return 0;
			}

			pos[cur_player] = j;

			j = pos[cur_player] + 1;
			while(j < n && board[j] != card.second){
				j++;
			}

			if(j == n){
				cout << cur_player + 1 << endl;
				return 0;
			}
		}
		else{
			for(int j = 0; j < n; j++)
				if(board[j] == card.second)
					pos[cur_player] = j;
		}

	}



	return 0;
}