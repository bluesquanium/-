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
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll N, M, ans, temp;
typedef struct {
	string name;
	ll kor, eng, math;
} Student;
vector<Student> m;

bool cmp(Student a, Student b) {
	if (a.kor != b.kor) {
		return a.kor > b.kor;
	}
	else if (a.eng != b.eng) {
		return a.eng < b.eng;
	}
	else if (a.math != b.math) {
		return a.math > b.math;
	}
	return a.name < b.name;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		Student t;
		cin >> t.name >> t.kor >> t.eng >> t.math;
		m.push_back(t);
	}
	sort(m.begin(), m.end(), cmp);

	for (ll i = 0; i < N; i++) {
		cout << m[i].name << '\n';
	}

	return 0;
}
