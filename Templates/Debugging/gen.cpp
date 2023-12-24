//IF YOU ARE JUSTICE, PLEASE DO NOT LIE..
//https://www.youtube.com/watch?v=taHMtTssjNY
//I can teach you how to bewitch the mind and ensnare the senses. 
//I can tell you how to bottle fame, brew glory, and even put a stopper in death.”
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pii pair <int, int>
#define endl "\n"
#define pll pair <long long, long long >
#define PI (2.0 * acos(0.0))
#define testcase ll T; cin >> T; for (ll tc = 1; tc <= T; tc++)
const long long M = 1e5 + 10, M2 = 1e6 + 10, oo = 1e9 + 7;
int rand (int a, int b) {
	return a + rand() % (b - a + 1);
}
set < pair <string, string> > st;
vector < int > v;
int main (int argc, char* argv[]) {
	srand(atoi(argv[1]));
	cout << 3 << endl;
	int t = 3;
	while (t--) {
		int n = rand(1, 20);
		cout << n << endl;
		int sm = 0;

		for (int i = 0; i < n; i++) {
			int x = rand(0, n);
			cout << x << " ";
			sm += n - x;
		}
		cout << endl;
		cout << rand(0, sm) << endl;
		// cout << endl;
	}
	
	// while (1) {
	// 	for (int i = 0; i < n; i++) {
	// 		s += '0' + rand(0, 1);
	// 	}
	// 	for (int i = 0; i < n; i++) {
	// 		t += '0' + rand(0, 1);
	// 	}
	// 	if (st.count(make_pair(s, t))) continue;
	// 	break;
	// }
	// st.insert(make_pair(s, t));
	// cout << n << endl << s << endl << t << endl;
	return 0;
}

