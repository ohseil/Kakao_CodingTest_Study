#include "problem9.h"

bool comp(pair<int, double> lhs, pair<int, double> rhs) {

	if (lhs.second > rhs.second)
		return true;
	else if (lhs.second == rhs.second)
		if (lhs.first < rhs.first)
			return true;
	return false;
}

vector<int> solution(int N, vector<int> stages) {

	vector<int> answer;
	vector <pair<int, double>> v;

	int* stageNum = new int[N + 2];
	int* totalNum = new int[N + 2];

	for (int i = 0; i < N + 2; i++) {
		stageNum[i] = 0;
		totalNum[i] = 0;
	}

	sort(stages.begin(), stages.end(), greater<int>());

	int plusNum = 0;

	for (int i : stages) {
		stageNum[i]++;
		plusNum++;
		totalNum[i] = plusNum;
	}

	for (int i = 1; i < N + 1; i++) {
		double d = stageNum[i] == 0 ? 0 : (double)stageNum[i] / totalNum[i];
		v.push_back(make_pair<int, double>((int)i, (double)d));
	}

	sort(v.begin(), v.end(), comp);

	for (auto a : v)
		answer.push_back(a.first);
	
	return answer;
}

void KakaoBlind2019::problem9::execute() {

	vector<int> v;
	v.push_back(4); v.push_back(4); v.push_back(4); v.push_back(4);
	v.push_back(4); //v.push_back(4); v.push_back(3); v.push_back(3);

	vector<int> aa = solution(4, v);

	for (auto a : aa)
		cout << a << " ";
	cout << endl;
}