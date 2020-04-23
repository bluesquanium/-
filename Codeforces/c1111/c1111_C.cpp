#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, k, a, b, temp;
map< pair<int,int>, long long > memo;
map< pair<int,int>, long long >::iterator iter1, iter2;
vector<int> avengers;

long long pow(int x, int y) {
	long long r = 1;
	for(int i = 0; i < y; i++) {
		r *= x;
	}
	return r;
}

long long Destroy(int start, int end, int l_av, int r_av) {
	long long sum = 0;
	if(end-start <=1){
		sum += r_av - l_av;
		memo[make_pair(start, end)] = sum; // update
		if(sum == 0) {
			sum = a;
		}
		else {
			sum = b*sum*1;
		}
		return sum;
	} 
	int mid = (end+start)/2, mid_av = lower_bound(avengers.begin()+l_av, avengers.begin()+r_av, mid) - avengers.begin();
	long long num1 = Destroy(start,mid, l_av, mid_av), num2 = Destroy(mid,end, mid_av, r_av);
	
	sum = memo[make_pair(start,mid)] + memo[make_pair(mid,end)];
	memo[make_pair(start, end)] = sum; // update
	
	if(sum == 0) {
		sum = a;
	}
	else {
		sum = b*sum*(end-start);
	}
	
	return min(num1+num2, sum);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k >> a >> b;
	for(int i = 0; i < k; i++) {
		cin >> temp;
		avengers.push_back(temp-1);
	}
	sort(avengers.begin(), avengers.end());
	
	cout << Destroy(0, pow(2,n), 0, k);
	return 0;
}
