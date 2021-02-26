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

ll N, M, temp;
vector<ll> m;

#define MOD_TAUNT 4
#define MOD_SENTENCE 3
#define MOD_NOUN_PHRASE 1
#define MOD_MODIFIED_NOUN 2
#define MOD_MODIFIER 2
#define MOD_PRESENT_REL 1
#define MOD_PAST_REL 1
#define MOD_PRESENT_PERSON 3
#define MOD_PAST_PERSON 5 
#define MOD_NOUN 11
#define MOD_PRESENT_VERB 2
#define MOD_PAST_VERB 2
#define MOD_ARTICLE 1
#define MOD_ADJECTIVE 7
#define MOD_ADVERB 5

// ---------------- CLASS DEFINITION ----------------
class Element {
public:
	ll cur, curMod;
	Element() : cur(0), curMod(-1) {};
	virtual string print() = 0;
	void UpdateCur() {
		cur = (cur + 1) % curMod;
	}
};

class Taunt : public Element {
public:
	ll cnt;
	Taunt() {
		cnt = 0;
		curMod = MOD_TAUNT;
	}

	string print();

	void ResetCnt();
	ll GetCnt();
	void SetCnt(ll num);
};

class Sentence : public Element {
public:
	Sentence() {
		curMod = MOD_SENTENCE;
	}

	string print();
};

class NounPhrase : public Element {
public:
	NounPhrase() {
		curMod = MOD_NOUN_PHRASE;
	}

	string print();
};

class ModifiedNoun : public Element {
public:
	ModifiedNoun() {
		curMod = MOD_MODIFIED_NOUN;
	}

	string print();
};

class Modifier : public Element {
public:
	Modifier() {
		curMod = MOD_MODIFIER;
	}

	string print();
};

class PresentRel : public Element {
public:
	PresentRel() {
		curMod = MOD_PRESENT_REL;
	}

	string print();
};

class PastRel : public Element {
public:
	PastRel() {
		curMod = MOD_PAST_REL;
	}

	string print();
};

class PresentPerson : public Element {
public:
	PresentPerson() {
		curMod = MOD_PRESENT_PERSON;
	}

	string print();
};

class PastPerson : public Element {
public:
	PastPerson() {
		curMod = MOD_PAST_PERSON;
	}

	string print();
};

class Noun : public Element {
public:
	Noun() {
		curMod = MOD_NOUN;
	}

	string print();
};

class PresentVerb : public Element {
public:
	PresentVerb() {
		curMod = MOD_PRESENT_VERB;
	}

	string print();
};

class PastVerb : public Element {
public:
	PastVerb() {
		curMod = MOD_PAST_VERB;
	}

	string print();
};

class Article : public Element {
public:
	Article() {
		curMod = MOD_ARTICLE;
	}

	string print();
};

class Adjective : public Element {
public:
	Adjective() {
		curMod = MOD_ADJECTIVE;
	}

	string print();
};

class Adverb : public Element {
public:
	Adverb() {
		curMod = MOD_ADVERB;
	}

	string print();
};

Taunt taunt;
Sentence sentence;
NounPhrase nounPhrase;
ModifiedNoun modifiedNoun;
Modifier modifier;
PresentRel presentRel;
PastRel pastRel;
PresentPerson presentPerson;
PastPerson pastPerson;
Noun noun;
PresentVerb presentVerb;
PastVerb pastVerb;
Article article;
Adjective adjective;
Adverb adverb;

// ---------------- Implementation of class functions ----------------
void Taunt::ResetCnt() {
	cnt = 0;
}

ll Taunt::GetCnt() {
	return cnt;
}

void Taunt::SetCnt(ll num) {
	cnt = num;
}

string Taunt::print() {
	string ret;
	cnt++;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = sentence.print();
		break;
	case 1:
		ret = taunt.print();
		ret.push_back(' ');
		ret += sentence.print();
		break;
	case 2:
		ret = noun.print();
		ret.push_back('!');
		break;
	case 3:
		ret = sentence.print();
		break;
	default:
		exit(1);
	}

	return ret;
}

string Sentence::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = pastRel.print();
		ret.push_back(' ');
		ret += nounPhrase.print();
		break;
	case 1:
		ret = presentRel.print();
		ret.push_back(' ');
		ret += nounPhrase.print();
		break;
	case 2:
		ret = pastRel.print();
		ret.push_back(' ');
		ret += article.print();
		ret.push_back(' ');
		ret += noun.print();
		break;
	default:
		exit(1);
	}

	return ret;
}

string NounPhrase::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = article.print();
		ret.push_back(' ');
		ret += modifiedNoun.print();
		break;
	default:
		exit(1);
	}

	return ret;
}

string ModifiedNoun::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = noun.print();
		break;
	case 1:
		ret = modifier.print();
		ret.push_back(' ');
		ret += noun.print();
		break;
	default:
		exit(1);
	}

	return ret;
}

string Modifier::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = adjective.print();
		break;
	case 1:
		ret = adverb.print();
		ret.push_back(' ');
		ret += adjective.print();
		break;
	default:
		exit(1);
	}

	return ret;
}

string PresentRel::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "your ";
		ret += presentPerson.print();
		ret.push_back(' ');
		ret += presentVerb.print();
		break;
	default:
		exit(1);
	}
	
	return ret;
}

string PastRel::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "your ";
		ret += pastPerson.print();
		ret.push_back(' ');
		ret += pastVerb.print();
		break;
	default:
		exit(1);
	}

	return ret;
}

string PresentPerson::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "steed";
		break;
	case 1:
		ret = "king";
		break;
	case 2:
		ret = "first-born";
		break;
	default:
		exit(1);
	}

	return ret;
}

string PastPerson::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "mother";
		break;
	case 1:
		ret = "father";
		break;
	case 2:
		ret = "grandmother";
		break;
	case 3:
		ret = "grandfather";
		break;
	case 4:
		ret = "godfather";
		break;
	default:
		exit(1);
	}

	return ret;
}

string Noun::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "hamster";
		break;
	case 1:
		ret = "coconut";
		break;
	case 2:
		ret = "duck";
		break;
	case 3:
		ret = "herring";
		break;
	case 4:
		ret = "newt";
		break;
	case 5:
		ret = "peril";
		break;
	case 6:
		ret = "chicken";
		break;
	case 7:
		ret = "vole";
		break;
	case 8:
		ret = "parrot";
		break;
	case 9:
		ret = "mouse";
		break;
	case 10:
		ret = "twit";
		break;
	default:
		exit(1);
	}

	return ret;
}

string PresentVerb::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "is";
		break;
	case 1:
		ret = "masquerades as";
		break;
	default:
		exit(1);
	}

	return ret;
}

string PastVerb::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "was";
		break;
	case 1:
		ret = "personified";
		break;
	default:
		exit(1);
	}

	return ret;
}

string Article::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "a";
		break;
	default:
		exit(1);
	}

	return ret;
}

string Adjective::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "silly";
		break;
	case 1:
		ret = "wicked";
		break;
	case 2:
		ret = "sordid";
		break;
	case 3:
		ret = "naughty";
		break;
	case 4:
		ret = "repulsive";
		break;
	case 5:
		ret = "malodorous";
		break;
	case 6:
		ret = "ill-tempered";
		break;
	default:
		exit(1);
	}

	return ret;
}

string Adverb::print() {
	string ret;

	ll _cur = cur;
	this->UpdateCur();
	switch (_cur) {
	case 0:
		ret = "conspicuously";
		break;
	case 1:
		ret = "categorically";
		break;
	case 2:
		ret = "positively";
		break;
	case 3:
		ret = "cruelly";
		break;
	case 4:
		ret = "incontrovertibly";
		break;
	default:
		exit(1);
	}

	return ret;
}

// ---------------- Other functions ----------------
char upperToLower(char c) {
	return 'a' + (c - 'A');
}

char lowerToUpper(char c) {
	return 'A' + (c - 'a');
}

bool isUpperCase(char c) {
	if (('A' <= c && c <= 'Z')) {
		return true;
	}
	return false;
}

bool isAlpha(char c) {
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
		return true;
	}
	return false;
}

string convertToLowerCaseString(string s) {
	string ret;
	for (ll i = 0; i < s.size(); i++) {
		if (isAlpha(s[i])) {
			if (isUpperCase(s[i])) {
				ret.push_back(upperToLower(s[i]));
			}
			else {
				ret.push_back(s[i]);
			}
			
		}
	}
	return ret;
}

bool checkTheHolyGrail(string s) {
	string target = "theholygrail";
	ll tCnt = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == target[tCnt]) {
			tCnt++;
		}
		if (tCnt == target.size()) {
			return true;
		}
	}
	return false;
}

ll countNumWord(string s) {
	ll ret = 0, check = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			check = 0;
		}
		else if (isAlpha(s[i])) {
			if (check == 0) {
				ret++;
			}
			check = 1;
		}
	}

	return ret / 3 + (ret % 3 != 0);
}

string preTreat(string s) {
	string ret;
	ll isSpace = 0;
	for (ll i = 0; i < s.size(); i++) {
		if ((s[i] == ' ' || s[i] == '\t')) {
			if (isSpace == 0) {
				ret.push_back(' ');
			}
			isSpace = 1;
		}
		else {
			isSpace = 0;
			ret.push_back(s[i]);
		}
	}

	if (ret[0] == ' ' || ret[0] == '\t') {
		ret = ret.substr(1, ret.size() - 1);
	}
	return ret;
}

string postTreat(string s) {
	bool isStart = 1;
	for (ll i = 0; i < s.size(); i++) {
		if (isStart && isAlpha(s[i])) {
			s[i] = lowerToUpper(s[i]);
			isStart = 0;
		}
		else if (s[i] == '!') {
			isStart = 1;
		}
	}
	s.push_back('.');
	return s;
}

void solve(string s) {
	taunt.ResetCnt();
	ll needNum = countNumWord(s);
	if (checkTheHolyGrail(s)) {
		taunt.SetCnt(1);
		cout << "Taunter: " << "(A childish hand gesture)." << '\n';
	}

	while (needNum > taunt.GetCnt()) {
		cout << "Taunter: " << postTreat(taunt.print()) << '\n';
	}
}

int main(void) {
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	while (1) {
		string s;
		getline(cin, s);
		if(s.empty()) {
			break;
		}
		s = preTreat(s);

		cout << "Knight: " << s << '\n';
		solve(s);
		cout << '\n';
	}

	return 0;
}
