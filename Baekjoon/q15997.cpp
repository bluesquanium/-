#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

vector<string> nation(4);
vector < pair< tuple<int,int> , tuple<double,double,double> > > match(6);
vector<int> score(4);
double win[4];

void Dfs(int count, double prob) {
	if (prob == 0) return;

	if (count < 6) {
		score[get<0>(match[count].first)] += 3;
		Dfs(count + 1, prob*(get<0>(match[count].second)) );
		score[get<0>(match[count].first)] -= 3;

		score[get<0>(match[count].first)] += 1;
		score[get<1>(match[count].first)] += 1;
		Dfs(count + 1, prob*(get<1>(match[count].second)) );
		score[get<0>(match[count].first)] -= 1;
		score[get<1>(match[count].first)] -= 1;

		score[get<1>(match[count].first)] += 3;
		Dfs(count + 1, prob*(get<2>(match[count].second)) );
		score[get<1>(match[count].first)] -= 3;

		return;
	}

	int w1, w2, w3, w4;
	vector<int>::iterator iter = max_element(score.begin(), score.end());
	w1 = iter - score.begin();
	*iter -= 100;
	vector<int>::iterator iter2 = max_element(score.begin(), score.end());
	w2 = iter2 - score.begin();
	*iter2 -= 100;
	vector<int>::iterator iter3 = max_element(score.begin(), score.end());
	w3 = iter3 - score.begin();
	*iter3 -= 100;
	vector<int>::iterator iter4 = max_element(score.begin(), score.end());
	w4 = iter4 - score.begin();

	*iter += 100;
	*iter2 += 100;
	*iter3 += 100;

	if (score[w2] > score[w3]) {
		win[w1] += prob; win[w2] += prob;
	}
	else if (score[w2] == score[w3]) {
		if (score[w2] == score[w4]) {
			if (score[w2] == score[w1]) {
				win[w1] += prob / 2; win[w2] += prob / 2;
				win[w3] += prob / 2; win[w4] += prob / 2;
			}
			else {
				win[w1] += prob    ; win[w2] += prob / 3;
				win[w3] += prob / 3; win[w4] += prob / 3;
			}
		}
		else {
			if (score[w2] == score[w1]) {
				win[w1] += prob*2 / 3; win[w2] += prob*2 / 3;
				win[w3] += prob*2 / 3;
			}
			else {
				win[w1] += prob    ; win[w2] += prob / 2;
				win[w3] += prob / 2;
			}
		}
	}


	return;
}

int main(void) {
	for (int i = 0; i < 4; i++) cin >> nation[i];
	for (int i = 0; i < 6; i++) {
		string temp_a, temp_b;
		int a, b;
		double w, d, l;
		cin >> temp_a >> temp_b >> w >> d >> l;
		for (int j = 0; j < 4; j++) {
			if (temp_a == nation[j]) a = j;
			if (temp_b == nation[j]) b = j;
		}
		match[i].first = make_tuple(a, b);
		match[i].second = make_tuple(w, d, l);
	}

	Dfs(0, 1.0);

	cout << fixed;
	cout.precision(10);
	for (int i = 0; i < 4; i++) cout << win[i] << '\n';
	return 0;
}
