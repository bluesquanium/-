#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll X, temp;
vector< string > ans;

string itos(ll a) {
	string s;
	while (a) {
		s.push_back(a % 10 + '0');
		a /= 10;
	}
	return string(s.rbegin(), s.rend());
}

ll Sum(ll a, ll b) {
	string s;
	s = itos(a) + " + " + itos(b);
	ans.push_back(s);

	return a + b;
}

ll Xor(ll a, ll b) {
	string s;
	s = itos(a) + " ^ " + itos(b);
	ans.push_back(s);

	return a ^ b;
}

ll mul2s(ll a, ll times) {
	for (ll i = 0; i < times; i++) {
		a = Sum(a, a);
	}
	return a;
}

ll calNumDigit(ll a) {
	ll numDigit = 0;
	while (a) {
		a /= 2;
		numDigit++;
	}
	return numDigit;
}

void makeShorter() {
	if (X % 4 == 3) {
		ll num = Sum(X, X);
		X = Xor(X, num);
	}

	ll numDigit = calNumDigit(X);
	ll num = mul2s(X, numDigit - 1);
	ll firstEven = Xor(Xor(num, X), Sum(num, X));
	ll lastEven = Xor(firstEven, Sum(X, X));

	while (calNumDigit(X) >= calNumDigit(lastEven)) {
		num = mul2s(lastEven, calNumDigit(X) - calNumDigit(lastEven));
		X = Xor(X, num);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> X;

	while (X != 1) {
		makeShorter();
	}

	cout << ans.size() << '\n';
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
