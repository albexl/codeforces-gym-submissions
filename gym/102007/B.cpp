#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

vector<int> months = {31, 28, 31, 30,
                      31, 30, 31, 31,
                      30, 31, 30, 31};

int conv(int m, int d)
{
	int x = d;
	for(int i = 1; i <= (int)months.size(); ++i)
		if(i < m)
			x += months[i - 1];
	return x;
}

pii iconv(int x)
{
	int m = 1;
	for(int i = 1; i <= (int)months.size(); ++i)
	{
		if(months[i - 1] < x)
			x -= months[i - 1], m = i + 1;
		else break;
	}

	return {m, x};
}

int dist(int from, int to)
{
	if(from < to) return to - from;
	return to + 365 - from;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	vector<int> D;
	while(n--)
	{
		cin >> s >> s;
		int m = (s[0] - '0') * 10 + (s[1] - '0');
		int d = (s[3] - '0') * 10 + (s[4] - '0');

		D.push_back(conv(m, d));
	}

	sort(D.begin(), D.end());
	D.resize(distance(D.begin(), unique(D.begin(), D.end())));

	n = D.size();
	int best = 0, p = 0;
	for(int i = 0; i < n; ++i)
	{
		int cur = D[i] - 1;
		if(cur == 0) cur = 365;

		int dd = D[(i + n - 1) % n];
		if(dd == cur) continue;

		dd = dist(dd, cur);

		if(best < dd)
			best = dd, p = cur;
		if(best == dd)
		{
			if(dist(conv(10, 27), cur) < dist(conv(10, 27), p))
				p = cur;
		}
	}

	auto x = iconv(p);

	if(x.first < 10)
		cout << "0" << x.first;
	else
		cout << x.first;
	cout << "-";

	if(x.second < 10)
		cout << "0" << x.second;
	else
		cout << x.second;

	return 0;
}