#include "problem34.h"

namespace KakaoIntern2020 {

	namespace problem34 {

		vector<int> solution(vector<string> gems) {

			vector<int> answer;

			// gem�� ó������ �� ��ȸ�ϴµ�,
			// map�� ����ؼ� �� ������ ������ �����ϸ鼭 ����.
			// ó�� ��� ������ ������ ������ ã�Ҵٸ�
			// ������ ������ ���¿��� ���� index�� ���������� �ű�鼭
			// ��� ������ ������ �������� Ȯ���Ѵ�.
			// ���������� �ű�� ������ ���� ������ �׸��ϰ�
			// ���� �ֱٿ� ������ ������ ó�� ���� �����̴�.

			// ������ �ѹ� ���ߴٸ�,
			// �� �������ʹ� ����index�� ������index �Ѵ� �ű�鼭 �����ϴ� �������� Ȯ���Ѵ�.
			// �� ������ ã�Ҵٸ� ���� index�� ������ �ּҹ����� ã��
			// ������ ������ �������� �۴ٸ� ã�Ƴ� ������ ���信 ������ �ȴ�.

			// ���� ��Ĵ�� ��ȸ�� �Ѵ�.

			int sIndex = 0, fIndex = 0; // ���� Ȯ���ϰ� �ִ� ����
			int rsIndex = 0, rfIndex = 0; // ���� ��� ������ ������ ���� ª�� ����

			int gemSize = 0, gemsLength = gems.size();

			bool isFirst = true;

			map<string, int> gemMap;

			// ���� �ٸ� ���� ���� Ȯ��.
			for (string gem : gems)
				gemMap[gem] = 1;

			gemSize = gemMap.size();

			gemMap.clear();

			for (int i = 0; i < gemsLength; i++) {

				if (isFirst == true) {
					// ���� ��� ������ ������ ���� ã�� ��
					gemMap[gems[i]]++;
					fIndex = i;
					if (gemMap.size() == gemSize) {
						// ��� ������ ������ ������ ã�� ���
						// ���� index�� �ű�� �� ���� ������ ã�ƺ���.
						rsIndex = sIndex, rfIndex = fIndex;
						for (int j = sIndex; j <= fIndex; j++) {
							if (gemMap[gems[j]] - 1 == 0) {
								break;
							}
							else {
								gemMap[gems[j]]--;
								rsIndex = sIndex = j + 1;
							}
						}

						isFirst = false;
					}
				}
				else {
					// �ѹ� �̻� ��� ������ ������ ���� ã�� ��
					// ������ ������ ���¿��� ����,������ index�� ��� �ű�� �˻�.
					gemMap[gems[sIndex]]--;
					gemMap[gems[i]]++;
					if (gemMap[gems[sIndex]] == 0) {
						gemMap.erase(gems[sIndex]);

					}

					sIndex++;
					fIndex = i;

					// �Ǵٽ� ���ǿ� �´� ������ ã�Ҵٸ�
					// �Ǵٽ� �� ���� ������ ã�´�.
					if (gemMap.size() == gemSize) {

						for (int j = sIndex; j <= fIndex; j++) {
							if (gemMap[gems[j]] - 1 == 0) {
								break;
							}
							else {
								gemMap[gems[j]]--;
								rsIndex = sIndex = j + 1;
								rfIndex = fIndex;
							}
						}
					}
				}
			}

			answer.push_back(rsIndex + 1);
			answer.push_back(rfIndex + 1);

			return answer;
		}

		void execute() {

		}
	}
}