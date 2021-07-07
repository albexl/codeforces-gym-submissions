#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1005;

int pi[maxn], sz[maxn], L[maxn], R[maxn];

int root(int x){
	return x == pi[x] ? x : root(pi[x]);
}

void merge(int a, int b){
	a = root(a);
	b = root(b);

	if(a == b)
		return;

	if(sz[a] > sz[b])
		swap(a, b);


	sz[b] += sz[a];
	L[b] = min(L[b], L[a]);
	R[b] = max(R[b], R[a]);
	pi[a] = b;

}


 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("hard.in", "r", stdin);
	freopen("hard.out", "w", stdout);

	string s;

	int id = 0;

	vector<pii> segs;

	while(getline(cin, s)){


		int lo = -32768;
		int hi = 32767;

		string op = "";
		op += s[2];
		op += s[3];

		int num = 0;

		int pos = 5;
		int sign = +1;

		if(s[pos] == '-')
			sign = -1, pos++;

		for(; pos < (int)s.size() && isdigit(s[pos]); pos++)
			num = num * 10 + (s[pos] - '0');

		num *= sign;

		if(op == ">=")
			lo = num;
		else
			hi = num;

		num = 0;

		if(pos + 1 < (int)s.size() && s[pos + 1] == '&'){
			pos += 9;

			sign = +1;
			if(s[pos] == '-')
				sign = -1, pos++;

			while(pos < (int)s.size() && isdigit(s[pos])){

				num = num * 10 + (s[pos] - '0');
				pos++;
			}

			num *= sign;
			hi = num;
		}

		
		if(lo <= hi){
			segs.push_back({lo, hi});
			sz[id] = 1;
			L[id] = lo;
			R[id] = hi;
			pi[id] = id;
			id++;
		}
	}

	if(segs.empty()){
		cout << "false" << endl;
		return 0;
	}

	for(int i = 0; i < (int)segs.size(); i++){
		for(int j = i + 1; j < (int)segs.size(); j++){

			int l = max(segs[i].first, segs[j].first);
			int r = min(segs[i].second, segs[j].second);

			if(l <= r || l - r == 1)
				merge(i, j);
		}
	}

	set<int> roots;

	for(int i = 0; i < id; i++)
		roots.insert(root(i));


	segs.clear();
	for(auto &r : roots)
		segs.push_back({L[r], R[r]});

	if((int)segs.size() == 1){
		if(segs[0].first == -32768 && segs[0].second == 32767){
			cout << "true" << endl;
			return 0;
		}
	}

	sort(segs.begin(), segs.end());

	int cnt = 0;
	for(auto &s : segs){
		if(s.first == -32768){
			cout << "x <= " << s.second;
		}
		else if(s.second == 32767){
			cout << "x >= " << s.first;
		}
		else{
			cout << "x >= " << s.first << " && x <= " << s.second;
		}

		cnt++;
		if(cnt != (int)segs.size())
			cout << " ||";

		cout << endl;

	}


	return 0;
}