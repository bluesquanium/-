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
using namespace std;

// accesory configuration
#define HR "HR"
#define RE "RE"
#define CO "CO"
#define EX "EX"
#define DX "DX"
#define HU "HU"
#define CU "CU"
#define MAXACC 4
// game condition
#define NOTFINISHED 0
#define WIN 1
#define DEAD 2

#define DIR 4
ll dy[DIR] = { -1, 0, 1, 0 };
ll dx[DIR] = { 0, 1, 0, -1 };

ll N, M, ans, temp;
char m[100][101];
string cmds;

void assert() {
	cout << "Error!\n";
	exit(1);
}

class Monster {
private:
	string name;
	ll atk, def;
	ll maxHP;
	ll exp;

public:
	Monster(string name, ll atk, ll def, ll maxHP, ll exp) :
		name(name), atk(atk), def(def), maxHP(maxHP), exp(exp) {}
	Monster(Monster & monster) {
		name = monster.name;
		atk = monster.atk;
		def = monster.def;
		maxHP = monster.maxHP;
		exp = monster.exp;
	}

	Monster& operator=(const Monster &monster) {
		return *this;
	}

	string getName() {
		return name;
	}

	ll getATK() {
		return atk;
	}

	ll getDEF() {
		return def;
	}

	ll getMaxHP() {
		return maxHP;
	}

	ll getEXP() {
		return exp;
	}
};

class Item {
private:
	char type;
	string accName;
	ll value;

public:
	Item(char type, ll value) : type(type), value(value) {}
	Item(char type, string accName) : type(type), accName(accName) {}
	Item(Item & item) {
		type = item.type;
		accName = item.accName;
		value = item.value;
	}
	string getAccName() {
		return accName;
	}
	ll getValue() {
		return value;
	}
	char getType() {
		return type;
	}
};

class Player {
private:
	ll level, remainExp;
	ll maxHP, curHP;
	ll atk, def;
	ll weapon, armor;
	string acc[MAXACC];

public:
	Player() {
		level = 1;
		remainExp = 5;
		maxHP = curHP = 20;
		atk = 2;
		def = 2;
		weapon = armor = 0;
		acc[0] = acc[1] = acc[2] = acc[3] = "";
	}

	void LevelUp() {
		level++;
		remainExp = level * 5;
		maxHP += 5;
		curHP = maxHP;
		atk += 2;
		def += 2;
	}

	void removeOneAcc(string accName) {
		for (ll i = 0; i < MAXACC; i++) {
			if (acc[i] == accName) {
				acc[i] = "";
				break;
			}
		}
		return;
	}

	void revive() {
		curHP = maxHP;
	}

	bool checkAcc(string accName) {
		for (ll i = 0; i < MAXACC; i++) {
			if (acc[i] == accName) {
				return true;
			}
		}
		return false;
	}

	bool interactWithMonster(Monster & monster) {
		ll trueATK = atk + weapon;
		ll trueDEF = def + armor;
		ll alphaDamage = 0;
		if (checkAcc(CO)) {
			if (checkAcc(DX)) {
				if (trueATK - monster.getDEF() < 1) {
					alphaDamage = max(0LL, trueATK * 3 - monster.getDEF() - 1);
				}
				else {
					alphaDamage = trueATK * 2;
				}
			}
			else {
				if (trueATK - monster.getDEF() < 1) {
					alphaDamage = max(0LL, trueATK * 2 - monster.getDEF() - 1);
				}
				else {
					alphaDamage = trueATK;
				}
			}
		}

		ll myPerDMG = max(1LL, trueATK - monster.getDEF());
		ll oppPerDMG = max(1LL, monster.getATK() - trueDEF);
		ll maxMyTurn = (curHP + oppPerDMG - 1) / oppPerDMG;

		if (maxMyTurn * myPerDMG >= monster.getMaxHP() - alphaDamage) {
			ll trueEXP = monster.getEXP();
			if (checkAcc(EX)) {
				trueEXP = monster.getEXP() * 1.2;
			}

			if (remainExp <= trueEXP) {
				LevelUp();
			}
			else {
				ll oppTurn;
				if (monster.getMaxHP() - alphaDamage <= 0) {
					oppTurn = 0;
				}
				else {
					oppTurn = (monster.getMaxHP() - alphaDamage + myPerDMG - 1) / myPerDMG - 1;
				}

				ll hpRegeneration = 0;
				if (checkAcc(HR)) {
					hpRegeneration = 3;
				}
				ll dmg = oppTurn * (max(1LL, monster.getATK() - trueDEF));
				curHP = min(curHP - dmg + hpRegeneration, maxHP);
				remainExp -= trueEXP;
			}

			return true;
		}
		curHP = 0;
		return false;
	}

	bool interactWithBoss(Monster & monster) {
		ll trueATK = atk + weapon;
		ll trueDEF = def + armor;
		ll alphaDamage = 0;
		if (checkAcc(CO)) {
			if (checkAcc(DX)) {
				if (trueATK - monster.getDEF() < 1) {
					alphaDamage = max(0LL, trueATK * 3 - monster.getDEF() - 1);
				}
				else {
					alphaDamage = trueATK * 2;
				}
			}
			else {
				if (trueATK - monster.getDEF() < 1) {
					alphaDamage = max(0LL, trueATK * 2 - monster.getDEF() - 1);
				}
				else {
					alphaDamage = trueATK;
				}
			}
		}

		ll myPerDMG = max(1LL, trueATK - monster.getDEF());
		ll oppPerDMG = max(1LL, monster.getATK() - trueDEF);
		if (checkAcc(HU)) {
			curHP = maxHP + oppPerDMG;
		}
		ll maxMyTurn = (curHP + oppPerDMG - 1) / oppPerDMG;
		if (maxMyTurn * myPerDMG >= monster.getMaxHP() - alphaDamage) {
			ll trueEXP = monster.getEXP();
			if (checkAcc(EX)) {
				trueEXP = monster.getEXP() * 1.2;
			}

			if (remainExp <= trueEXP) {
				LevelUp();
			}
			else {
				ll oppTurn;
				if (monster.getMaxHP() - alphaDamage <= 0) {
					oppTurn = 0;
				}
				else {
					oppTurn = (monster.getMaxHP() - alphaDamage + myPerDMG - 1) / myPerDMG - 1;
				}

				ll hpRegeneration = 0;
				if (checkAcc(HR)) {
					hpRegeneration = 3;
				}
				ll dmg = oppTurn * (max(1LL, monster.getATK() - trueDEF));
				curHP = min(curHP - dmg + hpRegeneration, maxHP);
				remainExp -= trueEXP;
			}

			return true;
		}
		curHP = 0;
		return false;
	}

	// interactWithSpike returns false if the player's curHP is lower 
	// than 0 after interaction with spike
	bool interactWithSpike() {
		if (checkAcc(DX)) {
			curHP -= 1;
		}
		else {
			curHP -= 5;
		}

		if (curHP > 0) {
			return true;
		}
		curHP = 0;
		return false;
	}

	void getNewAcc(Item & item) {
		ll blankSocket = -1;
		for (ll i = 0; i < MAXACC; i++) {
			if (item.getAccName() == acc[i]) {
				return;
			}
			else if (acc[i] == "") {
				blankSocket = i;
			}
		}
		if (blankSocket != -1) {
			acc[blankSocket] = item.getAccName();
		}
		return;
	}

	void getNewWeapon(Item & item) {
		weapon = item.getValue();
		return;
	}

	void getNewArmor(Item & item) {
		armor = item.getValue();
		return;
	}

	bool interactWithItem(Item & item) {
		if (item.getType() == 'O') {
			getNewAcc(item);
		}
		else if (item.getType() == 'W') {
			getNewWeapon(item);
		}
		else {
			getNewArmor(item);
		}
		return true;
	}

	ll getLevel() {
		return level;
	}
	ll getMaxEXP() {
		return level * 5;
	}
	ll getCurEXP() {
		return level * 5 - remainExp;
	}
	ll getMaxHP() {
		return maxHP;
	}
	ll getCurHP() {
		return curHP;
	}
	ll getATK() {
		return atk;
	}
	ll getDEF() {
		return def;
	}
	ll getWeapon() {
		return weapon;
	}
	ll getArmor() {
		return armor;
	}
};



class Controller {
private:
	ll gameOver;
	string deadBy;
	string cmds;
	Player player;
	pll playerPos;
	pll startPoint;
	ll passedTurns;
	ll monsterCnt;
	ll itemCnt;
	map<pll, Monster *> monsterMap;
	map<pll, Item *> itemMap;

public:
	Controller() {
		gameOver = NOTFINISHED;
		player = Player();
		passedTurns = 0;
		monsterCnt = itemCnt = 0;
	}
	~Controller() {
		for (auto iter = monsterMap.begin(); iter != monsterMap.end(); iter++) {
			delete (*iter).second;
		}
		for (auto iter = itemMap.begin(); iter != itemMap.end(); iter++) {
			delete (*iter).second;
		}
	}

	void SetStartPoint(ll y, ll x) {
		startPoint = { y, x };
		playerPos = { y, x };
	}

	void updateMonster(Monster & monster, pll pos) {
		Monster * newPtr = new Monster(monster);
		monsterMap[pos] = newPtr;
	}

	void updateItem(Item & item, pll pos) {
		Item * newPtr = new Item(item);
		itemMap[pos] = newPtr;
	}

	bool exec(char dir) {
		passedTurns++;

		bool ret = true;
		ll cury = playerPos.first, curx = playerPos.second;
		ll ny = cury + dy[dir], nx = curx + dx[dir];
		if (0 > ny || ny >= N ||
			0 > nx || nx >= M) {
			ny = cury;
			nx = curx;
		}
		if (m[ny][nx] == '#') {
			ny = cury;
			nx = curx;
		}
		playerPos = { ny, nx };

		switch (m[ny][nx]) {
		case '.':
			ret = true;
			break;
		case '&':
			if (monsterMap.count({ ny, nx }) == 0) {
				assert();
			}
			ret = player.interactWithMonster(*monsterMap[{ny, nx}]);
			if (ret) {
				m[ny][nx] = '.';
			}
			else if (player.checkAcc(RE)) {
				player.removeOneAcc(RE);
				player.revive();
				playerPos = startPoint;
				ret = true;
			}
			else {
				gameOver = DEAD;
				deadBy = monsterMap[{ny, nx}]->getName();
			}
			break;
		case 'M':
			ret = player.interactWithBoss(*monsterMap[{ny, nx}]);
			if (ret) {
				m[ny][nx] = '.';
				gameOver = WIN;
				ret = false;
			}
			else if (player.checkAcc(RE)) {
				player.removeOneAcc(RE);
				player.revive();
				playerPos = startPoint;
				ret = true;
			}
			else {
				gameOver = DEAD;
				deadBy = monsterMap[{ny, nx}]->getName();
			}
			break;
		case '^':
			ret = player.interactWithSpike();
			if (ret == false) {
				if (player.checkAcc(RE)) {
					player.removeOneAcc(RE);
					player.revive();
					playerPos = startPoint;
					ret = true;
				}
				else {
					gameOver = DEAD;
					deadBy = "SPIKE TRAP";
				}
			}
			break;
		case 'B':
			if (itemMap.count({ ny, nx }) == 0) {
				assert();
			}
			ret = player.interactWithItem(*itemMap[{ny, nx}]);
			if (ret) {
				m[ny][nx] = '.';
			}
			break;
		default:
			assert();
		}

		return ret;
	}

	ll getMonsterCnt() {
		return monsterCnt;
	}

	ll getItemCnt() {
		return itemCnt;
	}

	void incMonsterCnt() {
		monsterCnt++;
	}

	void incItemCnt() {
		itemCnt++;
	}

	ll getGameOver() {
		return gameOver;
	}
	string getDeadBy() {
		return deadBy;
	}
	pll getPlayerPos() {
		return playerPos;
	}
	ll getPassedTurns() {
		return passedTurns;
	}
	ll getPlayerLevel() {
		return player.getLevel();
	}
	ll getPlayerMaxEXP() {
		return player.getMaxEXP();
	}
	ll getPlayerCurEXP() {
		return player.getCurEXP();
	}
	ll getPlayerMaxHP() {
		return player.getMaxHP();
	}
	ll getPlayerCurHP() {
		return player.getCurHP();
	}
	ll getPlayerATK() {
		return player.getATK();
	}
	ll getPlayerDEF() {
		return player.getDEF();
	}
	ll getPlayerWeapon() {
		return player.getWeapon();
	}
	ll getPlayerArmor() {
		return player.getArmor();
	}
};

int main(void) {
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Controller controller;

	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			if (m[i][j] == '@') {
				controller.SetStartPoint(i, j);
				m[i][j] = '.';
			}
			if (m[i][j] == '&' || m[i][j] == 'M') {
				controller.incMonsterCnt();
			}
			if (m[i][j] == 'B') {
				controller.incItemCnt();
			}
		}
	}
	cin >> cmds;

	for (ll i = 0; i < controller.getMonsterCnt(); i++) {
		ll y, x;
		string name;
		ll atk, def, maxHP, exp;
		cin >> y >> x >> name >> atk >> def >> maxHP >> exp;
		y--; x--;
		Monster monster(name, atk, def, maxHP, exp);
		controller.updateMonster(monster, { y, x });
	}

	for (ll i = 0; i < controller.getItemCnt(); i++) {
		ll y, x;
		char type;
		cin >> y >> x >> type;
		y--; x--;
		if (type == 'O') {
			string accName;
			cin >> accName;
			Item item(type, accName);
			controller.updateItem(item, { y, x });
		}
		else {
			ll value;
			cin >> value;
			Item item(type, value);
			controller.updateItem(item, { y, x });
		}
	}

	for (ll i = 0; i < cmds.size(); i++) {
		ll dir;
		switch (cmds[i]) {
		case 'U':
			dir = 0;
			break;
		case 'R':
			dir = 1;
			break;
		case 'D':
			dir = 2;
			break;
		case 'L':
			dir = 3;
			break;
		}

		if (controller.exec(dir) == false) {
			break;
		}
	}

	if (controller.getGameOver() == WIN || controller.getGameOver() == NOTFINISHED) {
		pll pos = controller.getPlayerPos();
		m[pos.first][pos.second] = '@';
	}
	for (ll i = 0; i < N; i++) {
		cout << m[i] << '\n';
	}
	cout << "Passed Turns : " << controller.getPassedTurns() << '\n';
	cout << "LV : " << controller.getPlayerLevel() << '\n';
	cout << "HP : " << controller.getPlayerCurHP() << '/' << controller.getPlayerMaxHP() << '\n';
	cout << "ATT : " << controller.getPlayerATK() << '+' << controller.getPlayerWeapon() << '\n';
	cout << "DEF : " << controller.getPlayerDEF() << '+' << controller.getPlayerArmor() << '\n';
	cout << "EXP : " << controller.getPlayerCurEXP() << '/' << controller.getPlayerMaxEXP() << '\n';
	switch (controller.getGameOver()) {
	case WIN:
		cout << "YOU WIN!\n";
		break;
	case NOTFINISHED:
		cout << "Press any key to continue.\n";
		break;
	case DEAD:
		cout << "YOU HAVE BEEN KILLED BY " << controller.getDeadBy() << "..\n";
		break;
	}

	return 0;
}
