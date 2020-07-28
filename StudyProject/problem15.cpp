#include "problem15.h"

namespace KakaoBlind2018 {

	namespace problem15 {

		bool comp(pair<double, double> lhs, pair<double, double> rhs) {
			if (lhs.first <= rhs.first)
				return true;
			return false;
		}

		int solution(vector<string> lines) {

			int answer = 0;

			vector<pair<int, int>> datas;

			for (string line : lines) {

				// line���� ��¥ ���� �ð�, ��, �ʸ� �ʷ� ȯ���Ѵ�.

				string str = line.substr(11); // ��,��,�� ¥����

				double hour, min, sec;

				hour = stod(str.substr(0, 2));
				min = stod(str.substr(3, 2));
				sec = stod(str.substr(6, 6));

				min += hour * 60;
				sec += min * (double)60; // �Ϸ�ð��� �ʷ� ȯ���� ���.

				// ���۽ð��� �ʷ� ȯ���� ���
				double startSec = sec - stod(str.substr(0, str.length() - 1).substr(13)) + 0.001;

				// �Ҽ��� ���ְ� int������ ��ȯ.
				startSec = round(startSec *= 1000);
				sec = round(sec *= 1000);

				// ȯ�� ����� ���۽ð�, �Ϸ�ð� �ΰ��� ���� ���Ϳ� ����.
				datas.push_back(make_pair<int, int>((int)startSec, (int)sec));

			}

			// ���۽ð� ���� ������������ ����
			sort(datas.begin(), datas.end(), comp);

			// �� �����͸��� �������� ���۽ð��� �����ϵ��� 1�� ������ �����Ͽ�
			// ť�� �̿��Ͽ� �������� ���� Ȯ��.
			// ���� ������� ������ �����ͱ��� �˻�.
			// �� �� ���� ���� ������ ���Ե� ���� ���.

			queue<int> q;

			for (auto data : datas) {

				// ���ο� �������� ���۽ð��� ������ 1�ʱ�������
				// ���� ������ ���ԵǾ� �ִ� ������ ��
				// ���Ե��� �ʴ� ������ ť���� ����
				int sTime = data.first - 1000 + 1;

				if (!q.empty()) {

					int qSize = q.size();

					for (int i = 0; i < qSize; i++) {
						int comparing = q.front();
						q.pop();
						if (sTime <= comparing) {
							q.push(comparing);
						}
					}
				}

				q.push(data.second);

				// ���� 1�� �������� ���ԵǾ� �ִ� ������ ���� Ȯ��.
				if (answer < q.size())
					answer = q.size();

			}

			return answer;
		}

		void execute() {

			vector<string> lines;
			lines.push_back("2016-09-15 00:59:57.421 0.351s");
			lines.push_back("2016-09-15 00:59:58.233 1.181s");
			lines.push_back("2016-09-15 00:59:58.299 0.8s");
			lines.push_back("2016-09-15 00:59:58.688 1.041s");
			lines.push_back("2016-09-15 00:59:59.591 1.412s");
			lines.push_back("2016-09-15 01:00:00.464 1.466s");
			lines.push_back("2016-09-15 01:00:00.741 1.581s");
			lines.push_back("2016-09-15 01:00:00.748 2.31s");
			lines.push_back("2016-09-15 01:00:00.966 0.381s");
			lines.push_back("2016-09-15 01:00:02.066 2.62s");

			cout << solution(lines) << endl;
		}
	}
}