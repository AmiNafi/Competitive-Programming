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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define pb push_back
#define int ll
#define pii pair <int, int>
#define pll pair <long long, long long>
// #define endl '\n'
#include <random>
#define PI (2.0 * acos(0.0))
#define testcase int T; cin >> T; for (int tc = 1; tc <= T; tc++)
//#define info pair<int, pair < int, string > >

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
int fx[10] = {0, 1, 0, -1, 1, -1, 1, -1};
int fy[10] = {1, 0, -1, 0, 1 , -1, -1, 1};
const long long M = 1e5 + 10, M2 = 2e6 + 10, oo = 1e9 + 7, mod = 998244353;
const long long MC = (1 << 20) + 5;
int ceil(int a, int b) {
    return (a + b - 1) / b;
}
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ceil is a bad function
// think about reverse process
// read statement carefully
// think about corner cases before *implementing*
// don't forget to comment/uncomment define endl in interractive/non-interractive problems
// don't forget to return value in a return type function
// check if you are returning from solve before resetting array values
// try not to use continue statement
// try to write custom functions if stl one deals with floating point values

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
int fc[M2], fcinv[M2];
int ncr (int n, int r) {
    if (n < r) return 0;
    int ret = fc[n];
    ret = (ret * fcinv[r]) % oo;
    ret = (ret * fcinv[n - r]) % oo;
    return ret;
}
int pre[100000];
void precomp() {
    fc[0] = 1;
    fcinv[0] = 1;
    for (int i = 1; i < M2; i++) {
        fc[i] = (fc[i - 1] * i) % oo;
        fcinv[i] = (fcinv[i - 1] * pinverse(i, oo)) % oo;
    }
}
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve () {

}
int32_t main () {
    //freopen("E:/newts/in.txt", "r", stdin);
    //freopen("E:/newts/out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    // int T;
    //scanf("%d", &T);
    //while (T--) {
    testcase {
        // cout << "Case #" << tc << ": "; 
        solve (); 
    }
   return 0;
}