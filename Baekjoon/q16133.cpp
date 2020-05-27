#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

#define WS 0
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define POW 5
#define SQRT 6
#define LPRT 7
#define RPRT 8

ll ans;
string s;
vector<pll> m;

ll CmdToInt(char cmd) {
	ll p;
	switch (cmd) {
	case '+':
		p = ADD;
		break;
	case '-':
		p = SUB;
		break;
	case '*':
		p = MUL;
		break;
	case '/':
		p = DIV;
		break;
	case '^':
		p = POW;
		break;
	case '#':
		p = SQRT;
		break;
	case '(':
		p = LPRT;
		break;
	case ')':
		p = RPRT;
		break;
	default:
		p = -1;
	}

	return p;
}

ll Priority(ll cmd) {
	ll p;
	switch (cmd) {
	case ADD:
	case SUB:
		p = 1;
		break;
	case MUL:
	case DIV:
		p = 2;
		break;
	case POW:
		p = 3;
		break;
	case SQRT:
		p = 4;
		break;
	case LPRT:
	case RPRT:
		p = 5;
		break;
	default:
		p = -1;
	}

	return p;
}

ll findRPRT(ll start, ll end) {
	vector<ll> st;
	st.push_back(LPRT);
	for (ll i = start + 1; i < end; i++) {
		if (m[i].first == 0 && m[i].second == LPRT) {
			st.push_back(LPRT);
		}
		else if (m[i].first == 0 && m[i].second == RPRT) {
			st.pop_back();
			if (st.empty()) {
				return i;
			}
		}
	}
	return -INF;
}

bool isCmd(pll a) {
	if (a.first == 0 && a.second != WS) {
		return true;
	}
	return false;
}

bool isNum(pll a) {
	return a.first;
}

void preprocess() {
	ll num = 0, num_check = 0;
	for (ll i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			num_check = 1;
			num *= 10;
			num += s[i] - '0';
		}
		else if(s[i] != ' ') {
			if (num_check) {
				m.push_back({ 1, num });

				num_check = 0;
				num = 0;
			}
			m.push_back({ 0, CmdToInt(s[i]) });
		}
	}
	if (num_check) {
		m.push_back({ 1, num });
	}
}

void solve(ll begin, ll end) {
	while (1) {
		ll maxp = 0, midx;
		for (ll i = begin; i < end; i++) {
			if (isCmd(m[i])) {
				ll cmd = m[i].second;
				if (cmd == LPRT) {
					ll j = findRPRT(i, end);
					solve(i + 1, j);
					m[i] = { 0, WS };
					m[j] = { 0, WS };
				}
				else if (maxp < Priority(cmd) || ((cmd == POW || cmd == SQRT) && maxp == Priority(cmd))) {
					maxp = Priority(cmd);
					midx = i;
				}
			}
		}

		ll num1, num2;
		if (maxp == 0) {
			break;
		}
		else if (maxp <= 3) { // ADD SUB POW
			ll cmd = m[midx].second;

			for (ll i = midx - 1; i >= begin; i--) {
				if (isNum(m[i])) {
					num1 = m[i].second;
					m[i] = { 0, WS };
					break;
				}
			}
			for (ll i = midx + 1; i < end; i++) {
				if (isNum(m[i])) {
					num2 = m[i].second;
					m[i] = { 0, WS };
					break;
				}
			}
			
			if (cmd == ADD) {
				m[midx] = { 1, num1 + num2 };
			}
			else if(cmd == SUB) {
				m[midx] = { 1, num1 - num2 };
			}
			else if (cmd == MUL) {
				m[midx] = { 1, num1 * num2 };
			}
			else if (cmd == DIV) {
				m[midx] = { 1, num1 / num2 };
			}
			else { // POW
				m[midx] = { 1, (ll) pow(num1, num2) };
			}
		}
		else { //SQRT
			for (ll i = midx + 1; i < end; i++) {
				if (isNum(m[i])) {
					num1 = m[i].second;
					m[i] = { 0, WS };
					break;
				}
			}
			m[midx] = { 1, (ll) sqrt(num1) };
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> s;
	s.pop_back();

	preprocess();
	solve(0, m.size());

	for (ll i = 0; i < m.size(); i++) {
		if (isNum(m[i])) {
			ans = m[i].second;
			break;
		}
	}

	cout << ans;

	return 0;
}
