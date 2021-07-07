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

int F[100005];

int fquery(int b)
{
    int ret = 0;
    for (; b; b -= b & -b)
        ret += F[b];
    return ret;
}

void fupdate(int b, int c)
{
    for (; b <= 100000; b += b & -b)
        F[b] += c;
}

template<typename T>
T cross(complex<T> a, complex<T> b) { return imag(conj(a) * b); }
template<typename T>
T dot(complex<T> a, complex<T> b) { return real(conj(a) * b); }

struct __Query { static bool query; };
bool __Query::query = false;

template<typename T>
struct Point
{
	complex<T> p;
	int X;
	mutable function<const complex<T>*()> succ;
	bool operator<(const Point &rhs) const
	{
		const complex<T> &q = rhs.p;
		if (!__Query::query)
		{
			if (real(p) != real(q))
				return real(p) < real(q);
			return imag(p) > imag(q);
		}
		const complex<T> *s = succ();
		if (!s) return false;
		return dot(p - *s, q) < 0;
	}
};

template<typename T, int turn>
struct half_hull : public set<Point<T>>
{
	using set<Point<T>>::begin;
	using set<Point<T>>::insert;
	using set<Point<T>>::end;
	using set<Point<T>>::lower_bound;
	using set<Point<T>>::empty;
	using set<Point<T>>::erase;
	using typename set<Point<T>>::iterator;

	complex<T> extreme(const complex<T> &p) const
	{
		assert(!empty() && turn * imag(p) >= 0);
		__Query::query = true;
		auto pos = lower_bound(Point<T>{p});
		__Query::query = false;
		assert(pos != end());
		return pos->p;
	}

	void insert(const complex<T> &p, int X)
	{
		auto y = insert(Point<T>{p, X}).first; fupdate(X, +1);
		if (y == end()) return;
		y->succ = [=] { return next(y) == end() ? nullptr : &next(y)->p; };
		if (bad(y)) { fupdate(y->X, -1); erase(y); return; }
		while (y != begin() && bad(prev(y))) { fupdate(prev(y)->X, -1); erase(prev(y)); }
		while (next(y) != end() && bad(next(y))) { fupdate(next(y)->X, -1); erase(next(y)); }
	}

private:
	bool bad(iterator y)
	{
		if (y == begin() || y == end())
			return false;
		auto x = prev(y), z = next(y);
		if (z == end())
			return false;
		return cross(y->p - x->p, z->p - x->p) * turn > 0;
	}
};

template<typename T>
struct convex_hull_trick
{
	void insert(const complex<T> &p, int X)
	{
		//lower_hull.insert(p);
		upper_hull.insert(p, X);
	}


	half_hull<T, +1> upper_hull;
	//half_hull<T, -1> lower_hull;
};



int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	convex_hull_trick<ll> cht;

	pair<int, int> mx = { -1, -1 }; int X;
	vector<pair<int, int>> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; ++i) cin >> a[i].F >> a[i].S, b[i] = a[i].F;

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	int x, y, cx, pt = 0;
	for (auto &i : a)
	{
		tie(x, y) = i;
		cx = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;

		cht.insert({ x, y }, cx);

		if (y > mx.S || (y == mx.S && x < mx.F))
			mx = { x, y }, X = cx;

		cout << ++pt - cht.upper_hull.size() + fquery(X-1) << "\n";
	}

	return 0;
}