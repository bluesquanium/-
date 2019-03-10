#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n, l, k;

#define Step(X)	( (X)>0?1:-1 )

// �� �������� �޸��� �������� ���� ���ܱ����� �Ÿ��� �� 
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
		vector< pair<int,int> > ants; // ��ǥ�� �����ϴ� ������� �־���.
		int ants_id[n];
		for(int j = 0; j < n; j++) {
			int position, id;
			scanf("%d %d", &position, &id);
			ants_id[j] = id;
			ants.push_back( make_pair(position, id) );
		}
		vector< pair<int,int > > ants_sorted = ants;
		sort(ants_sorted.begin(), ants_sorted.end(), Compare);
		
		// ��ȣ�� 0���� �����ϹǷ� k��°�� [k-1]�� 
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
