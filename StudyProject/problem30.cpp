#include "problem30.h"

vector<long long> solution(long long k, vector<long long> room_number) {

	// map�� �̿��ؼ� �� ���� ���� ����ִ� ���� ����Ű�� ������ �����.
	// queue�� ���� ���� ã���� ��, ������ ã������ ���ĿԴ� �����
	// ������ �ξ��ٰ� ����� ������ �������ֱ� ���� ���.

	vector<long long> answer;

	map<long long, long long> m;
	queue<long long> q;

	for (auto num : room_number) {

		while (m[num] != 0) {
			q.push(num);
			num = m[num];
		}

		while (q.empty() == false) {
			long long data = q.front();
			q.pop();
			m[data] = num + 1;
		}

		m[num] = num + 1;
		answer.push_back(num);
	}

	return answer;
}

namespace KakaoWinterIntern2019 {

	namespace problem30 {

		void execute() {

		}
	}
}