#include <iostream>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	string poke[n+1];
	map<string, int> poke_map;
	for(int i = 1; i < n+1; i++) {
		cin >> poke[i];
		poke_map.insert(pair<string,int>(poke[i], i));
	}
	
	for(int i = 0; i < m; i++) {
		char q[20];
		cin >> q;
		
		string s = q;
		
		if('0' <= q[0] && q[0] <= '9') {
			int num;
			sscanf(q, "%d", &num);
			cout << poke[num] << '\n';
		}
		else {
			string s = q;
			cout << poke_map[s] << '\n';
		}
	}
	
	return 0;
}
