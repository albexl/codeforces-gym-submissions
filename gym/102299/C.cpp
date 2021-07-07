#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second



int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n >> q;

	set<pair<int, int>> s1, s2;
	for (int i = 1, x; i <= n; ++i)
	{
		cin >> x;
		s1.insert({ x, i });
		s2.insert({ i, x });
	}

	char op;
	for (int id, w; q--; )
	{
		cin >> op >> id;
		if (op == '-')
		{
			auto it = s2.lower_bound({ id, 0 });
			s1.erase({ it->S, it->F });
			s2.erase(it);
		}
		else if (op == '?')
		{
			auto it = *s2.lower_bound({ id, 0 });
			s1.erase({ it.S, it.F });
			s2.erase(it);

			debug(s1)
			debug(s2)
			debug(it)

			int sum = 0, ans = 0;
			pair<int, int> last = { -1, -1 };
			while (true)
			{
				auto f = s1.lower_bound({ sum, 0 });
				if (f != s1.end() && *f == last) f = next(f);
				if (f == s1.end() || sum + f->F > it.S) break;
				debug(*f)
				sum += f->F;
				++ans;
				last = *f;
			}

			sum += it.S;
			++ans;
			last = it;
			debug(it)
			while (true)
			{
				auto f = s1.lower_bound({ sum, 0 });
				if (f != s1.end() && *f == last) f = next(f);
				if (f == s1.end()) break;
				sum += f->F;
				debug(*f)
				last = *f;
				++ans;
			}

			cout << ans << "\n";

			s1.insert({ it.S, it.F });
			s2.insert(it);
		}
		else
		{
			cin >> w;
			swap(id, w);

			s1.insert({ w, id });
			s2.insert({ id, w });
		}
	}

	return 0;
}