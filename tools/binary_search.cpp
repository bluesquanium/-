#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

#define BSMAX 100000
bs_arr[BSMAX];
//Becaeful!
// BinarySearchByIndex finds target from [bs_arr[s], bs_arr[e]), not [bs_arr[s], bs_arr[e]]!
ll BinarySearchByIndex(ll s, ll e, ll target) {
	ll ss = s, ee = e;
	while (s < e) {
		ll mid = (s + e) / 2;
		if(target == bs_arr[mid]) {
			return mid;
		}
		else if (target > bs_arr[mid]) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}
	
	// �� �´� ���� ���� ��
	/* target���� ū ���� ���� 
	while (ss <= s && s < ee && bs_arr[s] < target) {
		++s;
	}
	*/
	/* target���� ���� ���� ���� 
	while (ss <= s && s < ee && bs_arr[s] > target) {
		--s;
	}
	*/
	//�� �� �� ���, �Ʒ� ������ ������� ���� �����. 
	
	return s;
}

//Becaeful!
// BinarySearchByNumber finds target from [s, e), not [s, e]!
ll BinarySearchByNumber(ll s, ll e, ll target) {
	ll ee = e, ss = s;
	while (s < e) {
		ll mid = (s + e) / 2;
		if(target == bs_arr[mid]) {
			return mid;
		}
		else if (target > bs_arr[mid]) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}
	
	// �� �´� ���� ���� ��
	/* target���� ū ���� ���� 
	while (ss <= s && s < ee && s < target) {
		++s;
	}
	*/
	/* target���� ���� ���� ���� 
	while (ss <= s && s < ee && s > target) {
		--s;
	}
	*/
	//�� �� �� ���, �Ʒ� ������ ������� ���� �����. 
	
	return s;
}
