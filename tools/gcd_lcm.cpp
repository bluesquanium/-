#include <iostream>
#define ll	long long
using namespace std;

ll Gcd(ll x, ll y) {
	return y?gcd(y,x%y):x;
}

ll Lcm(ll x, ll y) {
	return x*y/gcd(x,y);
}
