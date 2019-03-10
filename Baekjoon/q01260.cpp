#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define DATA	int
#define INIT	0

class GNode {
public:
	DATA data;
	vector<DATA> edgeWith;
	
	GNode(DATA _data = INIT) {
		data = _data;
	}
	
	void Insert(DATA data) {
		vector<int>::iterator check;
		check = find(edgeWith.begin(), edgeWith.end(), data);
		if(check == edgeWith.end()) {
			edgeWith.push_back(data);
			sort(edgeWith.begin(), edgeWith.end());
		}
	}
};

int main(void) {
	int n, m, v;
	cin >> n >> m >> v;
	vector<GNode*> nodes; // �� ������ �ּ� �������� vector 
	
	nodes.push_back(NULL); // 1������ �����ϴ� 0�� �ڸ��� dummy �� �־��ֱ� 
	for(int i = 1; i <= n; i++) {
		GNode * newGNode = new GNode(i);
		nodes.push_back(newGNode);
	}
	
	/*
	for(int i = 1; i <= n; i ++) {
		cout << nodes[i]->data << ' ';
	}
	*/
	
	for(int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		
		//edge �̾��ִ� ���� 
		nodes[v1]->Insert(v2);
		nodes[v2]->Insert(v1);
		//nodes[v1]->edgeWith.push_back(v2);
		//nodes[v2]->edgeWith.push_back(v1);
	}
	
	//DFS
	vector<int> check;
	check.assign(n+1, -1); // 0��° ���� dummy 
	stack<int> s;
	s.push(v);
	while(!s.empty()) {
		int cur = s.top();
		s.pop();
		
		if(check[cur] == -1) { // ���� �ش� ��忡 �鸣�� �ʾҴٸ� 
			cout<< cur << ' ';
			check[cur] = 1;
			for(int i = nodes[cur]->edgeWith.size()-1; i >= 0; i--) {
				if( check[nodes[cur]->edgeWith[i]] == -1 )
					s.push(nodes[cur]->edgeWith[i]);
			}
		}
	}
	
	cout << endl;
	//BFS
	check.clear();
	check.assign(n+1, -1); // 0��° ���� dummy 
	queue<int> q;
	q.push(v);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if(check[cur] == -1) { // ���� �ش� ��忡 �鸣�� �ʾҴٸ� 
			cout<< cur << ' ';
			check[cur] = 1;
			for(int i = 0; i < nodes[cur]->edgeWith.size(); i++) {
				if( check[nodes[cur]->edgeWith[i]] == -1 )
					q.push(nodes[cur]->edgeWith[i]);
			}
		}
	}
	
	
	return 0;
}
