#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define abs(X)	(X)>0?(X):-(X)

bool compare(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second;
}

bool compare2(pair<int,int*> a, pair<int,int*> b) {
	return a.second[2] < b.second[2];
}

bool compare3(pair<int, pair<int,int> > a, pair<int, pair<int,int> > b) { // ������������ ���� 
	return a.first > b.first;
}

//���Ͽ� ���ε�
int Find(int x, int* parent){

    // Root�� ��� x�� ��ȯ
    if(x == parent[x]){
        return x;
    }
    else{
        // �ƴϸ� Root�� ã�ư�
        int p = Find(parent[x], parent);
        parent[x] = p;
        return p;
    }
}

// x�� y�� ���Ұ� ������
// ���� x���� ���� x�� Root ��� y���� ���� y�� Root ��带 �����ؼ� ���ϰ�
// x�� y�� ���̴� ��� -> y�� Root ��带 x�� ����
void Union(int x, int y, int* parent){

    x = Find(x, parent);
    y = Find(y, parent);
	
	if (parent[x] < parent[y])
		swap(x, y);
	
    if(x!=y){
        parent[y] = x;
    }
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	//Input
	int n, m;
	cin >> n >> m;
	vector< pair<int,int*> > query; 
	bool result[m];
	int point[n][2];
	vector< pair<int,int> > x_point; // x_point
	vector< pair<int,int> > y_point; // y_point
	for(int i = 0; i < n; i++) {
		cin >> point[i][0] >> point[i][1];
		
		x_point.push_back( make_pair(i,point[i][0]) );
		y_point.push_back( make_pair(i,point[i][1]) );
	}
	sort(x_point.begin(), x_point.end(), compare);
	sort(y_point.begin(), y_point.end(), compare);
	vector< pair<int, pair<int,int> > > edge;
	for(int i = 0; i < n-1; i++) { // �Ÿ��� �Բ� edge�� ���� ����. 
		edge.push_back( make_pair( abs(x_point[i].second-x_point[i+1].second), make_pair(x_point[i].first, x_point[i+1].first) ) );
		edge.push_back( make_pair( abs(y_point[i].second-y_point[i+1].second), make_pair(y_point[i].first, y_point[i+1].first) ) );
	}
	sort(edge.begin(), edge.end(), compare3); // ������������ ���� 
	//x_point.clear();
	//y_point.clear();
	
	for(int i = 0; i < m; i++) {
		int * temp = new int[3];
		cin >> temp[0] >> temp[1] >> temp[2];
		query.push_back(make_pair(i, temp));
		query[i].second[0] -= 1; query[i].second[1] -= 1;
		//query[i].first = i; // query ��ȣ ���� 
	}
	sort(query.begin(), query.end(), compare2);

	int parent[n]; //���Ͽ� ���ε� 
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}
	
	/*
	for(int i = 0; i < edge.size(); i++) {
		cout << edge[i].first << ' ';
	}
	*/
	
	//Algorithm
	for(int i = 0; i < m; i++) {
	
		while(!edge.empty()) {
			if(edge.back().first > query[i].second[2]) {
				break;
			}
			Union(edge.back().second.first, edge.back().second.second, parent);
			edge.pop_back();
		}
		
		/*
		for(int j = 0; j < n; j++) {
			cout << j << ':' << Find(j, parent) << endl;
		}
		*/
		
		result[query[i].first] = (Find(query[i].second[0], parent) == Find(query[i].second[1], parent));
	}
	
	for(int i = 0; i < m; i++) {
		if(result[i] == true) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}
