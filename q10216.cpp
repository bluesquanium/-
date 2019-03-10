#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int T, N, x, y, r;
int parent[3001];

int abs(int a) {
	return a > 0 ? a : -a;
}

int Find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		parent[x] = Find(parent[x]);
		return parent[x];
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x > y)
		swap(x, y);

	parent[y] = x;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	while (T--) {
		int check[3001] = { 0 };
		int count = 0;
		vector< tuple<int, int, int> > enemy;
		enemy.push_back({ -1,-1,-1 }); // dummy;


		cin >> N;
		for (int i = 1; i <= N; i++) parent[i] = i;

		for (int i = 0; i < N; i++) {
			cin >> x >> y >> r;
			enemy.push_back( make_tuple(x,y,r) );
		}

		for (int i = 1; i <= N; i++) {
			for (int j = i+1; j <= N; j++) {
				int dx = abs(get<0>(enemy[i]) - get<0>(enemy[j]));
				int dy = abs(get<1>(enemy[i]) - get<1>(enemy[j]));
				int dr = abs(get<2>(enemy[i]) + get<2>(enemy[j]));
				if (dx*dx + dy * dy <= dr * dr) {
					Union(i, j);
				}
			}
		}

		for (int i = 1; i <= N; i++) Find(i);
		for (int i = 1; i <= N; i++) {
			if (check[parent[i]] == 0) {
				count++;
				check[parent[i]] = 1;
			}
		}

		cout << count << '\n';
	}

	//system("pause");
	return 0;
}
