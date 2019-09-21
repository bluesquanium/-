#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define IND	500
#define MEM	1000
#define DTYPE	long long
using namespace std;


int N, temp;
DTYPE ans;
unordered_map<DTYPE, int> r; // r : range
int index[IND];
int mem[IND][MEM];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		r[temp] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		
		int _ind = r[temp] / MEM, _mem = r[temp] % MEM;
		DTYPE sum = 0;

		for (int i = _mem + 1; i < MEM; i++) { // 자신 멤버 중 자기 이후의 합
			sum += mem[_ind][i];
		}
		for (int i = _ind + 1; i < IND; i++) { // 자신 이후 인덱스 합
			sum += index[i];
		}

		// Update
		mem[_ind][_mem] = 1;
		index[_ind] += 1;

		ans += sum;
	}

	cout << ans;

	return 0;
}
