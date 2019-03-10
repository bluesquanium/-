#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n, l, k;

#define Step(X)	( (X)>0?1:-1 )

// 각 지점에서 달리는 방향으로 막대 끝단까지의 거리를 비교 
inline bool Compare(pair<int,int> a, pair<int,int> b) {
	return (a.second>0?l-a.first:a.first) < (b.second>0?l-b.first:b.first);
}

inline int Distance(pair<int,int> ant, int l) {
	return ant.second>0?l-ant.first:ant.first;
}

int MainAlgorithm(vector< pair<int,int> > ants, vector< pair<int,int> > ants_sorted, int k) {
	int dir = Step(ants_sorted[k].second), count = 0;
	int cur;
	for(int j = 0; j < n; j++) {
		if(ants[j].second == ants_sorted[k].second) {
			cur = j;
			break;
		}
	}
	int j = cur;
	while(j >= 0 && j < n ) {
		if( (ants[j].second < 0) != (dir < 0) ) {
			count++;
		}
		dir>0?j++:j--;
	}
	return ants[cur+dir*count].second;
}

int main(void) {
	int t, result;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d %d %d", &n, &l, &k);
		vector< pair<int,int> > ants; // 좌표가 증가하는 순서대로 주어짐.
		int ants_id[n];
		for(int j = 0; j < n; j++) {
			int position, id;
			scanf("%d %d", &position, &id);
			ants_id[j] = id;
			ants.push_back( make_pair(position, id) );
		}
		vector< pair<int,int > > ants_sorted = ants;
		sort(ants_sorted.begin(), ants_sorted.end(), Compare);
		
		// 번호가 0부터 시작하므로 k번째는 [k-1]임 
		result = MainAlgorithm(ants, ants_sorted, k-1);
		if(k-1!=0 && Distance(ants_sorted[k-2],l) == Distance(ants_sorted[k-1],l)) {
			result = max( result, MainAlgorithm(ants, ants_sorted, k-2) );
		}
		else if(k-1!=n-1 && Distance(ants_sorted[k],l) == Distance(ants_sorted[k-1],l)) {
			result = min( result, MainAlgorithm(ants, ants_sorted, k) );
		}
		
		printf("%d\n",result);
	}
	
}
