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

bool compare3(pair<int, pair<int,int> > a, pair<int, pair<int,int> > b) { // 내림차순으로 정렬 
	return a.first > b.first;
}

//유니온 파인드
int Find(int x, int* parent){

    // Root인 경우 x를 반환
    if(x == parent[x]){
        return x;
    }
    else{
        // 아니면 Root를 찾아감
        int p = Find(parent[x], parent);
        parent[x] = p;
        return p;
    }
}

// x와 y의 원소가 들어오면
// 각각 x에는 들어온 x의 Root 노드 y에는 들어온 y의 Root 노드를 저장해서 비교하고
// x에 y를 붙이는 방식 -> y의 Root 노드를 x로 설정
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
	for(int i = 0; i < n-1; i++) { // 거리와 함께 edge인 노드들 저장. 
		edge.push_back( make_pair( abs(x_point[i].second-x_point[i+1].second), make_pair(x_point[i].first, x_point[i+1].first) ) );
		edge.push_back( make_pair( abs(y_point[i].second-y_point[i+1].second), make_pair(y_point[i].first, y_point[i+1].first) ) );
	}
	sort(edge.begin(), edge.end(), compare3); // 내림차순으로 정렬 
	//x_point.clear();
	//y_point.clear();
	
	for(int i = 0; i < m; i++) {
		int * temp = new int[3];
		cin >> temp[0] >> temp[1] >> temp[2];
		query.push_back(make_pair(i, temp));
		query[i].second[0] -= 1; query[i].second[1] -= 1;
		//query[i].first = i; // query 번호 저장 
	}
	sort(query.begin(), query.end(), compare2);

	int parent[n]; //유니온 파인드 
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
