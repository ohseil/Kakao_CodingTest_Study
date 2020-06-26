#include "problem5.h"

int KakaoBlind2020::problem5::solution(int n, vector<int> weak, vector<int> dist) {

	int answer = 0;

	vector<int> tempDist;

	// ������������ ���ĵ� �ӽ� ���� ����
	for (int i = dist.size() - 1; i >= 0; i--)
		tempDist.push_back(dist[i]);

	// ���� ��� Ȯ���� �� �ִ� ������� ģ������ ���ĵ�.
	// ������� 1��, 2��, 3�� ~ n����� �̾Ƴ��� permutation ������ ��� ��� �˻�.
	for (int i = 0; i < tempDist.size(); i++) {

		vector<int> checkSample;

		// ��Ÿ� �� �� �ִ� ������ ģ�� i + 1 �� �̱�.
		for (int j = 0; j <= i; j++)
			checkSample.push_back(tempDist[j]);

		// permutation ���� ���ؼ� ������������ ����.
		sort(checkSample.begin(), checkSample.end());

		// permutation ������ ��� ��� Ȯ��.
		do {
			// ��� ��������� Ȯ���� �� �ִ��� Ȯ���ϴ� �κ�.
			for (int startPoint = 0; startPoint < weak.size(); startPoint++) {
				
				int curIndex = startPoint; // ���� �˻��ʿ��� ������� �ε���

				int weakNum = 0; // ���� Ȯ���� ������� ����.

				for (auto friendDist : checkSample) {

					int curDist = friendDist;

					for (int wk = curIndex; wk < weak.size(); wk = (wk + 1) % weak.size()) {

						// �����������index���� �Դٴ� �� �� ���� �ϳ��� �˻��ϰ� �����Ѵٴ� �ǹ�.
						weakNum++;

						// ����� ��� �˻�Ϸ�.
						if (weakNum == weak.size()) {
							answer = checkSample.size(); // sample�� ���� ģ������ ���� ����.
							return answer;
						}

						// ���� ����������� �������� �� ���� ������������� �Ÿ�
						int weakDist = 0;

						if (wk == weak.size() - 1)
							weakDist = (n - weak[wk]) + weak[0];
						else
							weakDist = weak[wk + 1] - weak[wk];

						// ���� ������������� �Ÿ� ���ϰ� ���� �ͱ��� �˻��� �� �ִ��� Ȯ��
						if (weakDist > curDist) {
							// ���� ������� �˻� �Ұ�.
							curIndex = (wk + 1) % weak.size();
							break;
						}
						else {
							// ���� ����������� �˻� ����.
							curDist -= weakDist;
						}
					}


				}
			}


		} while (next_permutation(checkSample.begin(), checkSample.end()));

	}

	// routine �ȿ��� return ���� �ʾҴٸ� ��� ����� ������
	// ��� ��������� Ȯ���ϴ� ��찡 ���ٴ� �ǹ��̹Ƿ� -1 ���.
	answer = -1;

	return answer;
}

void KakaoBlind2020::problem5::execute() {

	int n = 12;
	vector<int> weak, dist;

	weak.push_back(1);
	weak.push_back(5);
	weak.push_back(6);
	//weak.push_back(9);
	weak.push_back(10);

	dist.push_back(1);
	dist.push_back(2);
	dist.push_back(3);
	dist.push_back(4);

	cout << solution(n, weak, dist) << endl;

}