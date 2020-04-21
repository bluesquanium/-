#include <iostream>
#define ll	long long
using namespace std;

ll A, B, C, cur, mul, ans;
ll mem[40];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> A >> B >> C;
	ans = cur = mul = 1;
	mem[1] = A % C;
	while (cur != 0) {
		if (mul * 2 <= B) {
			mem[cur + 1] = (mem[cur] * mem[cur]) % C;
			mul *= 2;
			cur++;
		}
		else {
			if (mul <= B) {
				ans = (ans * mem[cur]) % C;
				B -= mul;
			}
			mul /= 2;
			cur--;
		}
	}

	cout << ans;

	return 0;
}
