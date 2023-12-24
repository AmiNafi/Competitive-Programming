/*
Here's to the crazy ones, the misfits, the rebels, the troublemakers,
the round pegs in the square holes ... the ones who see things differently .
They're not fond of rules, and they have no respect for the status quo. ...
You can quote them, disagree with them, glorify or vilify them,
but the only thing you can't do is ignore them because they change things. ...
They push the human race forward, and while some may see them as the crazy ones,
we see genius, because the people who are crazy enough to think that they can change the world, are the ones who do.
*/
/*
I watched a snail crawl along the edge of a straight razor.
That's my dream; that's my nightmare.
Crawling, slithering, along the edge of a straight razor.d.. and surviving..
*/
// Templates
// 1. tempgeo.cpp
// 2. tempunion.cpp
// 3. mysegtree.cpp
// 4. tempnt.cpp

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define int ll
#define pii pair <int, int>
#define pll pair <long long, long long>
// #define endl '\n'
#include <random>
#define PI (2.0 * acos(0.0))
#define testcase int T; cin >> T; for (int tc = 1; tc <= T; tc++)
// #define info pair<int, pair < int, string > >

#define mkp make_pair
#define info pair < int, pii >
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int fx[10] = {1, -1, 0, 0, 1, -1, 1, -1};
int fy[10] = {0, 0, 1, -1, 1 , -1, -1, 1};
const long long M = 2e5 + 10, M2 = 1e6 + 10, oo = 1e9 + 7, mod = 998244353;
const long long MC = (1 << 20) + 5;
inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}
inline int abs (int a, int b) {
    int d1 = a - b;
    if (d1 < 0) d1 *= -1;
    return d1;
}

long long bigmod (int n, int p, int md) {
    if (p == 0) return 1;
    long long ans= bigmod(n, p / 2, md);
    ans = (ans * ans) % md;
    if (p % 2 == 1) ans = (ans * n) % md;
    return ans;
}
long long pinverse (int num, int md) {
    return bigmod(num, md - 2, md);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ceil is a bad function
// think about reverse process
// read statement carefully
// think about corner cases before *implementing*
// don't forget to comment/uncomment define endl in interractive/non-interractive problems
// don't forget to return value in a return type function
// check if you are returning from solve before resetting array values
// try not to use continue / return statement, try to use if else
// try to write custom functions if stl one deals with floating point values
// don't use unordered map without custom hash
// set multiset are bad try to use map if possible
// don't forget to return a value from a non-void function
void precomp () {
	// precomputation here
}
struct P {
	int x, y;
	void read () {
		cin >> x >> y;
	}
	P operator -(const P& b) const {
		return P{x - b.x, y - b.y};
	}
	void operator -=(const P& b) {
		x -= b.x; y -= b.y;
	}
	long long operator* (const P& b) const {
		return  1LL * x * b.y - 1LL * y * b.x;
	}
	long long triangle (const P& b, const P& c) {
		return (b - *this) * (c - *this);
	}
};
void solve () {
}
int32_t main () {
    //freopen("E:/newts/in.txt", "r", stdin);
    //freopen("E:/newts/out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    // int T;
    // scanf("%d", &T);
    // while (T--) {
    testcase {
        // cout << "Case #" << tc << ": ";
    

      // cout << "Case " << tc << ": ";
        solve ();
    }
   return 0;
}
