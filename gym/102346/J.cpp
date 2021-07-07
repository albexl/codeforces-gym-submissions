#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX

typedef long long ll;

string cards = "A23456789DQJK";

int get_pos(char c){
	for(int i = 0; i < cards.size(); i++)
		if(cards[i] == c)
			return i;
	return cards.size();
}

struct player{

	vector<int> freq;
	bool just_received;
	bool has_wildcard;

	player(){
		just_received = false;
		has_wildcard = false;
		freq.resize(13);
	}

};

//|| (p.freq[i] == 3 && p.has_wildcard)

bool is_winner(player p){

	int cnt = 0;
	for(int i = 0; i < 13; i++)
		cnt += p.freq[i];
	cnt += p.has_wildcard;

	if(cnt != 4)
		return false;

	for(int i = 0; i < 13; i++)
		if(p.freq[i] == 4 )
			return true;

	return false;
}

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	k--;

	vector<player> p;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;

		player x;

		for(auto &c : s)
			x.freq[get_pos(c)]++;

		p.push_back(x);
	}


	p[k].has_wildcard = true;
	p[k].just_received = true;

	// int turn = 0;


	for(; ; k += 1, k %= n){

		// cout << k << " im going to play:" << endl;

		// for(int j = 0; j < 13; j++)
		// 	cout << p[k].freq[j] << " \n"[j == 12];	

		//check for winners
		for(int i = 0; i < n; i++){
			if(is_winner(p[i])){
				cout << i + 1 << endl;
				// cout << turn << endl;


				// for(int j = 0; j < 13; j++)
				// 	cout << p[i].freq[j] << " \n"[j == 12];



				return 0;
			}
		}

		if(p[k].has_wildcard && !p[k].just_received){
			p[k].has_wildcard = false;
			p[(k + 1) % n].has_wildcard = true;
			p[(k + 1) % n].just_received = true;
		}
		else{

			p[k].just_received = false;

			int least = 25, opt = -1;

			for(int j = 0; j < 13; j++){
				if(p[k].freq[j] < least && p[k].freq[j] != 0){
					least = p[k].freq[j];
					opt = j;
				}
			}

			p[k].freq[opt]--;
			p[(k + 1) % n].freq[opt]++;

		}

		// turn++;

	}


	return 0;
}