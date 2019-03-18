#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N	1000001
#define ll	long long
using namespace std;

int N, M, K;
ll a, b, c, sum;
ll nums[MAX_N];
ll m[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		sum += nums[i];
		if (i % 1000 == 0) { // 1000개씩 나눠서 저장
			m[i / 1000] = sum;
			sum = 0;
		}
	}

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) { // nums, m 둘 다 업데이트 해줌
			m[(b-1) / 1000 + 1] += c - nums[b];
			nums[b] = c;
		}
		else {
			sum = 0;
			int j;
			for (j = b; j%1000 != 1 && j <= c; j++) { // 1000개씩 더할 수 없는 앞부분
				sum += nums[j];
			}
			for (j = j + 999; j <= c; j += 1000) { // 1000개 씩 더해줌
				sum += m[j/1000];
			}
			for (j = j - 1000 + 1; j <= c; j++) { // 1000개씩 더할 수 없는 뒷부분
				sum += nums[j];
			}
			cout << sum << '\n';
		}
	}

	return 0;
}
