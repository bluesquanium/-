#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
	    long long a, b;
	    cin >> a >> b;
	    cout << a+b << '\n';
    }
	
	return 0;
}
