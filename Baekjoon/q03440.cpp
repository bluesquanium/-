#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
#define NODESTARTNUM 10000
#define NUMNODE 20000
using namespace std;

#define MAXN 200
#define DIR 4
ll dy[DIR] = { -1, 0, 1, 0 };
ll dx[DIR] = { 0, 1, 0, -1 };

ll mapCur, temp;
string m[200];
ll nm[200][201];
int visited[200][200];
#define NUMALPHA 26
ll results[NUMALPHA];

class Node {
public:
	char type; // 9 'o' 1 '&' 'A'~'Z'
	ll needNumChild;
	vector<ll> children;
	vector<pll> portPos;
	ll val;

	Node() {}
	Node(char type) : type(type), needNumChild(0), val(-1) {}
};
Node nodes[NUMNODE];
ll nCnt = 0;

void nodeUpdateVal(ll nodeIdx) {
	if (nodes[nodeIdx].needNumChild != nodes[nodeIdx].children.size()) {
		exit(1);
	}
	switch (nodes[nodeIdx].type) {
	case 9:
		exit(1);
		break;
	case 'o':
		nodes[nodeIdx].val = nodes[nodes[nodeIdx].children[0]].val == 1 ? 0 : 1;
		break;
	case '1':
		nodes[nodeIdx].val = 0;
		for (ll i = 0; i < nodes[nodeIdx].children.size(); i++) {
			if (nodes[nodes[nodeIdx].children[i]].val == 1) {
				nodes[nodeIdx].val = 1;
				break;
			}
		}
		break;
	case '&':
		nodes[nodeIdx].val = 1;
		for (ll i = 0; i < nodes[nodeIdx].children.size(); i++) {
			if (nodes[nodes[nodeIdx].children[i]].val == 0) {
				nodes[nodeIdx].val = 0;
				break;
			}
		}
		break;
	case '=':
		nodes[nodeIdx].val = 0;
		for (ll i = 0; i < nodes[nodeIdx].children.size(); i++) {
			if (nodes[nodes[nodeIdx].children[i]].val == 1) {
				nodes[nodeIdx].val = !nodes[nodeIdx].val;
			}
		}
		break;
	default:
		nodes[nodeIdx].val = nodes[nodes[nodeIdx].children[0]].val;
		results[nodes[nodeIdx].type - 'A'] = nodes[nodeIdx].val;
		break;
	}
}

class PosPrevPos {
public:
	pll prevPos;
	pll pos;
	PosPrevPos(pll prevPos, pll pos) : prevPos(prevPos), pos(pos) {}
};

ll sCnt = NODESTARTNUM;
vector<pll> search(pll startPos) {
	sCnt++;
	pll prevCur = { startPos.first, startPos.second - 1 };
	pll cur = startPos;
	vector<pll> searchedPos;
	vector<PosPrevPos> st;
	st.push_back(PosPrevPos(prevCur, cur));
	while (!st.empty()) {
		PosPrevPos cur = st.back(); st.pop_back();
		if (0 <= cur.pos.first && cur.pos.first < mapCur &&
			0 <= cur.pos.second && cur.pos.second < m[cur.pos.first].size() && visited[cur.pos.first][cur.pos.second] != sCnt) {
			visited[cur.pos.first][cur.pos.second] = sCnt;

			switch (nm[cur.pos.first][cur.pos.second]) {
			case '=':
				if (cur.prevPos.second != cur.pos.second + 1) {
					st.push_back(PosPrevPos(cur.pos, { cur.pos.first, cur.pos.second + 1 }));
				}
				break;
			case '-':
				if (cur.prevPos.second == cur.pos.second - 1) {
					st.push_back(PosPrevPos(cur.pos, { cur.pos.first, cur.pos.second + 1 }));
				}
				else {
					st.push_back(PosPrevPos(cur.pos, { cur.pos.first, cur.pos.second - 1 }));
				}
				break;
			case '|':
				if (cur.prevPos.first == cur.pos.first - 1) {
					st.push_back(PosPrevPos(cur.pos, { cur.pos.first + 1, cur.pos.second }));
				}
				else {
					st.push_back(PosPrevPos(cur.pos, { cur.pos.first - 1, cur.pos.second }));
				}
				break;
			case '+':
				for (ll dir = 0; dir < DIR; dir++) {
					ll ny = cur.pos.first + dy[dir], nx = cur.pos.second + dx[dir];
					if (0 <= ny && ny < mapCur &&
						0 <= nx && nx < m[ny].size()) {
						if(dir == 0 || dir == 2) { // vertical
							if (cur.prevPos.first != ny && (m[ny][nx] == '|' || m[ny][nx] == 'x' || m[ny][nx] == '+')) {
								st.push_back(PosPrevPos(cur.pos, { ny, nx }));
							}
						}
						else {
							if (cur.prevPos.second != nx && (m[ny][nx] == '-' || m[ny][nx] == 'x' || m[ny][nx] == '+' || m[ny][nx] == '=')) {
								st.push_back(PosPrevPos(cur.pos, { cur.pos.first, cur.pos.second + 1 }));
							}
						}
					}
				}
				break;
			case 'x':
				if (cur.prevPos.first == cur.pos.first - 1) {
					st.push_back(PosPrevPos(cur.pos, { cur.pos.first + 1, cur.pos.second }));
				}
				if (cur.prevPos.first == cur.pos.first + 1) {
					st.push_back(PosPrevPos(cur.pos, { cur.pos.first - 1, cur.pos.second }));
				}
				if (cur.prevPos.second == cur.pos.second - 1) {
					st.push_back(PosPrevPos(cur.pos, { cur.pos.first, cur.pos.second + 1 }));
				}
				if (cur.prevPos.second == cur.pos.second + 1) {
					st.push_back(PosPrevPos(cur.pos, { cur.pos.first, cur.pos.second - 1 }));
				}
				break;
			case '#':
				visited[cur.pos.first][cur.pos.second] = 0;
				searchedPos.push_back(cur.pos);
				break;
			case ' ':
			case '\0':
				break;
			case 'o':
				visited[cur.pos.first][cur.pos.second] = 0;
				searchedPos.push_back(cur.pos);
				break;
			default: // 'A'~'Z' or NODESTARTNUM + alpha
				visited[cur.pos.first][cur.pos.second] = 0;
				searchedPos.push_back(cur.pos);
				break;
			}
		}
	}

	return searchedPos;
}

char findType(pll pos) {
	char ret;
	ll minY = INF, maxY = 0, minX = INF, maxX = 0;
	vector<pll> st;
	st.push_back(pos);
	while (!st.empty()) {
		pll cur = st.back(); st.pop_back();
		if (visited[cur.first][cur.second] == 0) {
			visited[cur.first][cur.second] = 1;
			minY = min(minY, cur.first);
			maxY = max(maxY, cur.first);
			minX = min(minX, cur.second);
			maxX = max(maxX, cur.second);
			for (ll dir = 0; dir < DIR; dir++) {
				ll ny = cur.first + dy[dir];
				ll nx = cur.second + dx[dir];
				if (nm[ny][nx] == '#' && visited[ny][nx] == 0) {
					st.push_back({ ny, nx });
				}
			}
		}
	}

	for (ll i = minY; i <= maxY; i++) {
		for (ll j = minX; j <= maxX; j++) {
			if (m[i][j] != '#' && m[i][j] != ' ') {
				ret = m[i][j];
				nm[i][j] = ' ';
			}
		}
	}

	return ret;
}

ll fillGate(ll nodeIdx, pll pos) {
	nodes[nCnt] = Node(findType({ pos.first, pos.second }));
	vector<pll> childrenPorts;
	vector<pll> parentPorts;

	char ret;
	vector<pll> st;
	st.push_back(pos);
	while (!st.empty()) {
		pll cur = st.back(); st.pop_back();
		if (nm[cur.first][cur.second] == '#') {
			nm[cur.first][cur.second] = nCnt + NODESTARTNUM;
			for (ll dir = 0; dir < DIR; dir++) {
				ll ny = cur.first + dy[dir];
				ll nx = cur.second + dx[dir];
				if (0 <= ny && ny < mapCur &&
					0 <= nx && m[cur.first][cur.second] != '\0') {
					if (nm[ny][nx] == '#') {
						st.push_back({ ny, nx });
					}
					else if (nm[ny][nx] == 'o') {
						parentPorts.push_back({ ny, nx });
					}
					else if (nm[ny][nx] == '=') {
						if (dir == 1) {
							parentPorts.push_back({ ny, nx });
						}
						else if (dir == 3) {
							childrenPorts.push_back({ ny, nx });
						}
					}
				}
			}
		}
	}

	nodes[nCnt].needNumChild = childrenPorts.size();
	nodes[nCnt].portPos = parentPorts;

	return nCnt++;
}


ll revealNode(pll pos) {
	if (nm[pos.first][pos.second] >= NODESTARTNUM) {
		return nm[pos.first][pos.second] - NODESTARTNUM;
	}
	else {
		if (m[pos.first][pos.second] == 'o') {
			nodes[nCnt] = Node('o');
			nodes[nCnt].needNumChild = 1;
			nodes[nCnt].portPos.push_back({ pos.first, pos.second + 1 });
			return nCnt++;
		}
		else if (m[pos.first][pos.second] == '#') {
			ll nodeIdx = fillGate(nCnt, pos);
			return nodeIdx;
		}
		else {
			nodes[nCnt] = Node(m[pos.first][pos.second]);
			nodes[nCnt].needNumChild = 1;
			return nCnt++;
		}
	}
	return -1;
}

void init() {
	for (ll i = 0; i < nCnt; i++) {
		nodes[i].children.clear();
		nodes[i].portPos.clear();
	}
	nCnt = 0;
	mapCur = 0;
	for (ll i = 0; i < NUMALPHA; i++) {
		results[i] = -1;
	}
	for (ll i = 0; i < 200; i++) {
		for (ll j = 0; j < 200; j++) {
			visited[i][j] = 0;
		}
	}
}

void solve() {
	vector<ll> nodeStack;

	for (ll i = 0; i < mapCur; i++) {
		for (ll j = 0; j < m[i].size(); j++) {
			if ((m[i][j] == '0' || m[i][j] == '1') && m[i][j+1] == '=') {
				nodes[nCnt] = Node(9);
				nodes[nCnt].needNumChild = 0;
				nodes[nCnt].val = m[i][j] - '0';
				nodes[nCnt].portPos.push_back({ i, j + 1 });

				nm[i][j] = NODESTARTNUM + nCnt;
				nodeStack.push_back(nCnt);
				nCnt++;
			}
			else {
				nm[i][j] = m[i][j];
			}
		}
	}

	for (ll i = 0; i < mapCur; i++) {
		for (ll j = 0; j < m[i].size(); j++) {
			if (nm[i][j] == '#') {
				ll nodeIdx = revealNode({ i, j });
				if (nodes[nodeIdx].needNumChild == 0) {
					nodeUpdateVal(nodeIdx);
					nodeStack.push_back(nodeIdx);
				}
			}
		}
	}
	while (!nodeStack.empty()) {
		ll cur = nodeStack.back(); nodeStack.pop_back();
		if (nodes[cur].needNumChild > nodes[cur].children.size()) {
			exit(1);
		}

		for (ll portIdx = 0; portIdx < nodes[cur].portPos.size(); portIdx++) {
			vector<pll> searchedPos = search(nodes[cur].portPos[portIdx]);
			for (ll i = 0; i < searchedPos.size(); i++) {
				ll nodeIdx = revealNode(searchedPos[i]);
				nodes[nodeIdx].children.push_back(cur);
				if (nodes[nodeIdx].needNumChild == nodes[nodeIdx].children.size()) {
					nodeUpdateVal(nodeIdx);
					nodeStack.push_back(nodeIdx);
				}
			}
		}
	}
}

ll testcase = 0;
void printResult() {
	//cout << "--" << ++testcase << "--\n";
	for (ll i = 0; i < NUMALPHA; i++) {
		if (results[i] != -1) {
			cout << (char)('A' + i) << '=' << results[i] << '\n';
		}
	}
	cout << '\n';
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	while (1) {
		init();
		getline(cin, m[mapCur]); mapCur++;
		if (m[0][0] == '*') {
			break;
		}
		while (1) {
			getline(cin, m[mapCur]);
			if (m[mapCur][0] == '*') {
				break;
			}
			mapCur++;
		}

		solve();
		printResult();
	}

	return 0;
}
