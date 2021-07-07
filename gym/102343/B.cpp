#include<bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tri;
 
bool cmp(pii a, pii b){
	if(a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	
	string s;
	cin >> s;

	vector<int> freq(26);

	for(auto &c : s)
		freq[c - 'a']++;

	vector<pii> v;
	for(int i = 0; i < 26; i++)
		if(freq[i])
			v.push_back({freq[i], i});

	sort(v.begin(), v.end(), cmp);
 	
 	for(int i = 0; i < v.size(); i++){
 		for(int j = 0; j < v[i].first; j++)
 			cout << (char)(v[i].second + 'a');
 	}
	
 	cout << endl;

	return 0;
}