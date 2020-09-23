#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <chrono>
#include <random>
#define ll	unsigned long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

ll N, ans, temp;
vector<ll> hashes;
vector<ll> hash_values;
vector<ll> freq;
unordered_map<ll, ll> hash_freq;
vector< queue<ll> > indices;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	hashes.resize(N + 1, 0);
	hash_values.resize(N + 1);
	freq.resize(N + 1);
	indices.resize(N + 1);

	for (ll i = 0; i <= N; i++) {
		hash_values[i] = rng();
	}

	hash_freq[hashes[0]]++;

	ll start = 0;
	for (ll i = 0; i < N; i++) {
		cin >> temp;

		if (indices[temp].size() >= 3) {
			ll remove = indices[temp].front(); indices[temp].pop();

			while (start <= remove) {
				hash_freq[hashes[start]]--;
				start++;
			}
		}

		ll before = freq[temp];
		freq[temp] = (freq[temp] + 1) % 3;
		hashes[i + 1] = hashes[i] + (freq[temp] - before) * hash_values[temp];
		ans += hash_freq[hashes[i + 1]];
		hash_freq[hashes[i + 1]]++;
		indices[temp].push(i);
	}

	cout << ans;

	return 0;
}
