#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GNode {
public:
	int num;
	vector< pair<GNode *,int> > edge_with; // first : node_num, second : edge_length
	
	GNode(int _num = 0) : num(_num) {}
};

int n, from, to, result;
GNode * addr[100001]; // 0은 더미 
bool is_checked[100001]; // 0은 더미

void Dfs(int cur, int dest, int cost, int mcost) {
	if(cur == dest) {
		result = cost - mcost;
		return;
	}
	
	for(int i = 0; i < addr[cur]->edge_with.size(); i++) {
		int next = addr[cur]->edge_with[i].first->num,
			ncost = addr[cur]->edge_with[i].second;
		if( is_checked[next] == false ) {
			is_checked[next] = true;
			Dfs(next, dest, cost + ncost, max(mcost, ncost));
			is_checked[next] = false;
		}
	}
	
	return;
}

int main(void) {
	cin >> n >> from >> to;
	for(int i = 1; i <= n; i++) addr[i] = new GNode(i);
	
	for(int i = 0; i < n-1; i++) {
		int p1, p2, e;
		cin >> p1 >> p2 >> e;
		addr[p1]->edge_with.push_back( make_pair(addr[p2],e) );
		addr[p2]->edge_with.push_back( make_pair(addr[p1],e) );
	}
	
	is_checked[from] = true;
	Dfs(from, to, 0, 0);
	
	cout << result;

	return 0;
}
