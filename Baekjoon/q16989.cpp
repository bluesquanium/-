#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <functional>
#define pii	pair<int,int>
using namespace std;

#define DIR	4
int dy[DIR] = { -1, 0, 1, 0 },
	dx[DIR] = { 0, 1, 0,-1 };

int N, M, ans;
int m[1000][1000], is_visited[1000][1000];
map<int, int> chunk1_map;
map<pii, int> chunk2_map;

void Solve() {
	// 전체 맵 돌면서 m[i][j]==2 이면서 아직 탐색을 안한 지점을 찾은 후
	// 돌 1, 2개로 막을 수 있는지 확인 + 막아야할 위치와 함께 저장 (chunk1_map, chunk2_map)
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		if (m[i][j] == 2 && is_visited[i][j] == 0) {
			int count = 0, count_0 = 0; // count : 해당 덩어리의 크기 카운트, count_0 : 막아야할 위치(0인 지점) 카운트
			vector<pii> st, zero;
			st.push_back({ i,j });
			while (!st.empty()) {
				pii cur = st.back(); st.pop_back();
				if (is_visited[cur.first][cur.second] == 0) {
					is_visited[cur.first][cur.second] = 1;
					count++;
					for (int dir = 0; dir < DIR; dir++) {
						int next_y = cur.first + dy[dir], next_x = cur.second + dx[dir];
						if (0 <= next_y && next_y < N &&
							0 <= next_x && next_x < M) {
							// m[next_y][next_x] == 2이고 아직 탐색하지 않았으면 st에 push_back 해준다. 
							if (m[next_y][next_x] == 2 && is_visited[next_y][next_x] == 0)
								st.push_back({ next_y, next_x });
							// 막아야할 위치이고 아직 확인 안한 지점일 때 
							else if (m[next_y][next_x] == 0 && is_visited[next_y][next_x] == 0) {
								count_0++;
								is_visited[next_y][next_x] = 1;
								zero.push_back({ next_y,next_x });
							}
						}
					}
				}
			}
			if (count_0 == 2) {
				// temp1, temp2 : 막아야할 위치의 좌표(y,x)를 값 하나로 줄여줌. 
				int temp1 = M * zero[0].first + zero[0].second,
					temp2 = M * zero[1].first + zero[1].second;
				if (temp1 > temp2) swap(temp1, temp2); 
				if (chunk2_map.count({ temp1,temp2 }) == 0)
					chunk2_map[{ temp1, temp2 }] = count;
				
				else // temp1, temp2에 둠으로써 막아지는 다른 chunk2가 있었을 수 있다. 이 경우 count 값을 더해서 저장해줌. 
					chunk2_map[{ temp1, temp2 }] += count;
			}
			else if (count_0 == 1) {
				int temp1 = M * zero[0].first + zero[0].second;
				if (chunk1_map.count(temp1) == 0)
					chunk1_map[temp1] = count;
				else
					chunk1_map[temp1] += count;
			}
			// 탐색한 빈칸들은 다른 chunk에서도 막아야할 지점이 될 수 있기에
			// 해당 위치의 is_visited값 초기화 
			while (!zero.empty()) {
				pii cur = zero.back(); zero.pop_back();
				is_visited[cur.first][cur.second] = 0;
			}
		}
	}
	}

	if (chunk1_map.size() == 0 && chunk2_map.size() == 0) return;
	// chunk2 탐색 
	for (map<pii, int>::iterator iter = chunk2_map.begin(); iter != chunk2_map.end(); iter++) {
		int temp = (*iter).second;
		if (chunk1_map.count((*iter).first.first) != 0) // chunk2를 막는 두 지점 중 처음 위치에 두면서 동시에 막하지는 chunk1이 있다면 더해줌. 
			temp += chunk1_map[(*iter).first.first];
		if (chunk1_map.count((*iter).first.second) != 0)// 두번째 지점 막으면서 막아지는 chunk1의 크기 더해줌. 
			temp += chunk1_map[(*iter).first.second];
		ans = max(ans, temp);
	}
	// temp : chunk1 가장 큰 거 2개 더한거  
	int temp = 0, maxi = 0;
	map<int, int>::iterator maxi_iter = chunk1_map.end();
	for (map<int, int>::iterator iter = chunk1_map.begin(); iter != chunk1_map.end(); iter++) {
		if (maxi <= (*iter).second) {
			maxi = (*iter).second;
			maxi_iter = iter;
		}
	}
	temp += maxi;
	if (maxi_iter != chunk1_map.end()) (*maxi_iter).second = 0;
	maxi = 0;
	for (map<int, int>::iterator iter = chunk1_map.begin(); iter != chunk1_map.end(); iter++) {
		if (maxi <= (*iter).second) {
			maxi = (*iter).second;
			maxi_iter = iter;
		}
	}
	temp += maxi;
	
	ans = max(ans, temp);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < M; j++)
		cin >> m[i][j];
	Solve();
	cout << ans;
	return 0;
}
