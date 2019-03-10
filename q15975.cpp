#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map< int,vector<int> > nums;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, x, color, sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> color;
		nums[color].push_back(x);
	}
	map< int,vector<int> >::iterator iter;
	for(iter = nums.begin(); iter != nums.end(); iter++) sort((*iter).second.begin(),(*iter).second.end());
	
	for(iter = nums.begin(); iter != nums.end(); iter++)
	for(int j = 0; j < (*iter).second.size(); j++)
		if( j == 0 ) { if(j+1 < (*iter).second.size()) sum += (*iter).second[j+1] - (*iter).second[j]; }
		else if( j == (*iter).second.size()-1 ) sum += (*iter).second[j] - (*iter).second[j-1];
		else sum += min( (*iter).second[j]-(*iter).second[j-1], (*iter).second[j+1]-(*iter).second[j] );
	cout << sum;

	return 0;
}
