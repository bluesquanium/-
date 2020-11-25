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

ll N, M, DIGIT, ans, temp;
vector<ll> val1(16, -1);
vector<ll> m;

void cntDIGIT(ll num) {
	while (num) {
		DIGIT++;
		num /= 2;
	}
	DIGIT--;
}

ll cnt0(ll num) {
	ll ret = DIGIT;
	while (num) {
		ret -= (num % 2);
		num /= 2;
	}
	return ret;
}

ll cnt1(ll num) {
	ll ret = 0;
	while (num) {
		ret += (num % 2);
		num /= 2;
	}
	return ret;
}

ll findMax0() {
	ll maxi0_idx, maxi0 = -1;
	for (ll i = 2; i <= N; i++) {
		if (maxi0 < cnt0(m[i])) {
			maxi0 = cnt0(m[i]);
			maxi0_idx = i;
		}
	}
	return maxi0_idx;
}

ll mem[1 << 16][2];
vector<ll> findMax1() {
	vector<ll> ret;
	for (ll i = (1 << DIGIT) - 1; i >= 0; i--) {
		if (mem[i][1] != 0) {
			ret.push_back(mem[i][0]);
			ret.push_back(mem[i][1]);
			break;
		}

		for (ll mask = 1; mask < (1 << DIGIT); mask *= 2) {
			if ((i & mask) != 0) {
				ll target = (i ^ mask);
				if (mem[target][0] == 0) {
					mem[target][0] = mem[i][0];
				}
				else {
					mem[target][1] = mem[i][0];
				}
			}
		}
	}
	return ret;
}

vector<ll> Phase2() {
	vector<ll> ret;

	for (ll i = 2; i <= N; i++) {
		ll isFail = 0;
		for (ll d = 0; d < DIGIT; d++) {
			ll mask = 1 << d;
			if (val1[d] == -1 && ((~m[i]) & mask) == 0) {
				isFail = 1;
				break;
			}
		}
		if (isFail == 0) {
			ret.push_back(i);
			break;
		}
	}

	if (ret.size() == 0) {
		for (ll i = 2; i <= N; i++) {
			ll isFail = 0;
			for (ll d = 0; d < DIGIT; d++) {
				ll mask = 1 << d;
				if (val1[d] == -1 && (m[i] & mask) == 0) {
					isFail = 1;
					break;
				}
			}
			if (isFail == 0) {
				ret.push_back(i);
				if (ret.size() == 2) {
					break;
				}
			}
		}
	}

	return ret;
}

int main(void) {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cntDIGIT(N);
	m.resize(N + 1);
	for (ll i = 2; i <= N; i++) {
		cout << "XOR 1 " << i << '\n';
		cin >> temp;
		m[i] = temp;
		if (mem[temp][0] == 0) {
			mem[temp][0] = i;
		}
		else {
			mem[temp][1] = i;
		}
	}

	ll max0Candi = findMax0();
	vector<ll> max1Candi = findMax1();
	ll max1Cnt = -1;
	if (max1Candi.size() >= 2) {
		cnt1(m[max1Candi[0]] & m[max1Candi[1]]);
	}
	ll max0Cnt = cnt0(m[max0Candi]);

	if (max0Cnt >= max1Cnt) {
		cout << "AND 1 " << max0Candi << '\n';
		ll valAND;
		cin >> valAND;
		ll valXOR = m[max0Candi];
		for (ll i = 0; i < DIGIT; i++) {
			ll mask = 1 << i;
			if ((valXOR & mask) == 0) {
				if ((valAND & mask) != 0) {
					val1[i] = 1;
				}
				else {
					val1[i] = 0;
				}
			}
		}
	}
	else {
		ll target1 = m[max1Candi[0]] ^ m[max1Candi[1]]; target1 = ~target1;
		cout << "AND " << max1Candi[0] << ' ' << max1Candi[1] << '\n';
		ll valAND;
		cin >> valAND;
		for (ll i = 0; i < DIGIT; i++) {
			ll mask = 1 << i;
			if ((target1 ^ mask) != 0) {
				if ((valAND & mask) != 0) {
					val1[i] = 0;
				}
				else {
					val1[i] = 1;
				}
			}
		}
	}

	// for(ll i = DIGIT - 1; i >= 0; i--) {
	//     cout << val1[i] << ' ';
	// }
	// cout << '\n';

	vector<ll> phase2 = Phase2();
	if (phase2.size() == 1) {
		cout << "AND 1 " << phase2[0] << '\n';
		ll valAND;
		cin >> valAND;
		ll valXOR = m[phase2[0]];
		for (ll i = 0; i < DIGIT; i++) {
			ll mask = 1 << i;
			if ((valXOR & mask) == 0) {
				if ((valAND & mask) != 0) {
					val1[i] = 1;
				}
				else {
					val1[i] = 0;
				}
			}
		}
	}
	else {
		cout << "AND " << phase2[0] << ' ' << phase2[1] << '\n';
		ll valAND;
		cin >> valAND;
		ll target1 = m[phase2[0]] ^ m[phase2[1]]; target1 = ~target1;
		for (ll i = 0; i < DIGIT; i++) {
			ll mask = 1 << i;
			if ((target1 & mask) != 0) {
				if ((valAND & mask) != 0) {
					if ((m[phase2[0]] & mask) == 0) {
						val1[i] = 1;
					}
					else {
						val1[i] = 0;
					}
				}
				else {
					if ((m[phase2[0]] & mask) == 0) {
						val1[i] = 0;
					}
					else {
						val1[i] = 1;
					}
				}
			}
		}
	}

	ll firstVal = 0, mulVal = 1;
	for (ll i = 0; i < DIGIT; i++) {
		firstVal += val1[i] * mulVal;
		mulVal *= 2;
	}

	cout << "! " << firstVal << ' ';
	for (ll i = 2; i <= N; i++) {
		ll val = 0, mulVal = 1;
		for (ll j = 0; j < DIGIT; j++) {
			ll mask = 1 << j;
			if ((mask & m[i]) == 0) {
				val += firstVal & mask;
			}
			else {
				val += ((~firstVal) & mask);
			}
			mulVal *= 2;
		}
		cout << val << ' ';
	}
	cout << '\n';

	return 0;
}
