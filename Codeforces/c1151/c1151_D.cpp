#include <iostream>
#include <vector>
#include <algorithm>
#define ll	long long
#define pll	pair<ll, ll>
using namespace std;

int N;
ll ans, a, b;
vector<pll> st;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		st.push_back({ a - b, b*(ll)(N - 1) });
	}
	sort(st.begin(), st.end());

	ll idx = 0;
	while (!st.empty()) {
		pll cur = st.back(); st.pop_back();
		//cout << ' ' << cur.second + cur.first*idx << endl;
		ans += cur.second + cur.first*idx++;
	}
	
	cout << ans;

	return 0;
}
