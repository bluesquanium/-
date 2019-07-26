/* Solution1 : 인덱스 트리 1000개씩 200개
 * 0번 기준 ~ 200000번 기준 2개 저장
 * 각 인덱스 트리의 원소 갯수 저장
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define ll	long long
#define MODNUM	1000000007
#define INUM	200
#define ELNUM	1000
using namespace std;

int N, ind;
ll cost, ans = 1;
int m[200000];
int field[200000];
ll index[200][3]; // 0번 기준, 200000번 기준, 원소 갯수

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N; // N==1인 경우는 없음
	for (int i = 0; i < N; i++) cin >> m[i];

	ind = m[0] / ELNUM;
	field[m[0]] = 1;
	index[ind][0] += m[0];
	index[ind][1] += 200000 - m[0];
	index[ind][2]++;

	for (int i = 1; i < N; i++) {
		ind = m[i] / ELNUM;
		cost = 0;
		for (int j = 0; j < ind; j++) cost += abs(index[j][1] - (200000 - m[i]) * index[j][2]);
		for (int j = 0; j < ELNUM; j++) if (field[ (ind * ELNUM) + j ] != 0) { cost += abs( m[i] - ((ind * ELNUM) + j) ) * field[ (ind * ELNUM) + j ];}
		for (int j = ind + 1; j < INUM; j++) cost += abs(index[j][0] - (m[i]) * index[j][2]);
		ans = (ans * (cost % MODNUM)) % MODNUM;

		field[m[i]]++;
		index[ind][0] += m[i];
		index[ind][1] += 200000 - m[i];
		index[ind][2]++;
	}

	cout << ans;

	return 0;
}
