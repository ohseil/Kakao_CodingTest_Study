#include "problem15.h"

bool comp(pair<double, double> lhs, pair<double, double> rhs) {
	if (lhs.first >= rhs.first)
		return true;
	return false;
}

int solution(vector<string> lines) {
	
	int answer = 0;

	vector<pair<double, double>> datas;

	for (string line : lines) {

		// line���� ��¥ ���� �ð�, ��, �ʸ� �ʷ� ȯ���Ѵ�.
		// ȯ�� ����� ���۽ð�, �Ϸ�ð� �ΰ��� ���� ���Ϳ� ����.
	}

	// ���۽ð� ���� ������������ ����
	sort(datas.begin(), datas.end(), comp);

	// �˻� �� ó�� �ð��� �� ó�� �������� ���۽ð����� ����.
	// �� �Ŀ� ���� �������� ���۽ð��� �����ϵ��� 1�� ������ �����Ͽ� ���� Ȯ��.
	// ���� ������� ������ �����ͱ��� �˻�.
	// �� �� ���� ���� ������ ���Ե� ���� ���.

	return answer;
}

namespace KakaoBlind2018 {

	namespace problem15 {

		void execute() {

		}
	}
}