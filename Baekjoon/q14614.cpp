#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int A, B, ans;
string a, b, sum, C;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C;

	if ((C[C.size() - 1] - '0') % 2 == 0) { // even
		cout << A;
		return 0;
	}

	else { // odd
		// 2Áø¼öÈ­
		int ta = A, tb = B;
		while (ta != 0) {
			a += ta % 2 + '0';
			ta /= 2;
		}
		while (tb != 0) {
			b += tb % 2 + '0';
			tb /= 2;
		}
		//Cal
		for (int i = 0; i < min(a.size(), b.size()); i++) {
			if (a[i] == b[i]) {
				sum += '0';
			}
			else {
				sum += '1';
			}
		}
		
		if (a.size() > b.size()) {
			sum += a.substr(b.size(), a.size() - b.size());
		}
		else if (a.size() < b.size()) {
			sum += b.substr(a.size(), b.size() - a.size());
		}
		
	}

	for (int i = sum.size()-1; i >= 0; i--) {
		ans *= 2;
		ans += sum[i] - '0';
	}

	cout << ans;

	return 0;
}
