#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define DATA	int
#define INIT	0

int construct_t[1001];

class GNode {
public:
	DATA data;
	vector<DATA> edgeWith;
	
	GNode(DATA _data = INIT) {
		data = _data;
	}
};

int Construct(vector<GNode*> nodes, int root) {
	//cout << "-2-" << endl;
	int max_time = 0;
	for(int i = 0; i < nodes[root]->edgeWith.size(); i++) {
		int target = nodes[root]->edgeWith[i];
		if( construct_t[target] != -1 ) {
			max_time = max(max_time, construct_t[target]);
		}
		else {
			max_time = max(max_time, Construct(nodes, target));
		}
	}
	
	if(construct_t[root] == -1) {
		construct_t[root] = nodes[root]->data + max_time;
	}
	return nodes[root]->data + max_time;
}

int main(void) {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		memset(construct_t, -1, sizeof(construct_t)); // construct 배열을 -1로 초기화 
		int n, k;
		cin >> n >> k;
		vector<GNode*> nodes; // 각 노드들의 주소 저장해줄 vector 
		nodes.push_back(0); // nodes[0]에는 더미 노드 
		//int build_t[n];
		for(int j = 0; j < n; j++) {
			int build_t;
			cin >>build_t;
			GNode * newNode = new GNode(build_t);
			nodes.push_back(newNode);
		}
		for(int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			nodes[y]->edgeWith.push_back(x); 
		}
		int w;
		cin >> w;
		
		//cout << "-1-" << endl;
		cout << Construct(nodes, w) << endl;
	}
	
	return 0;
}
