#include "problem33.h"

namespace KakaoIntern2020 {

	namespace problem33 {

		// ���� 2���� �������� ���� ������� ��ȯ�ϴ� �Լ�
		long long cf(long long num1, long long num2, string oper) {
			if (oper == "+")
				return num1 + num2;
			else if (oper == "-")
				return num1 - num2;
			else
				return num1 * num2;
		}

		long long calFunc(queue<string> q, vector<string> op) {

			// �Էµ� ������ ������� ���
			for (string oper : op) {

				// �⺻ ��ƾ�� ���ڿ� ������ �ϳ��� �̾Ƽ�
				// num1�� ope ������ ���ڿ� �����ڸ� �����ϰ�,
				// ���� ������ �ٽ� queue�� �����Ѵ�.
				// ope�� �����ؾ��� �����ڶ�� flag�� true�� �����Ͽ�
				// ������ Ȯ���ϴ� ���ڿ��� num1�� ������ �� ������� num1�� �����ϰ�
				// ���� �����ڰ��� ope�� �����Ѵ�.
				// ���������� ope�� ����� �����ڰ� ������ �ʿ���� �����ڶ��
				// num1�� ope�� �ٽ� queue�� �����Ѵ�.
				// �������� �ݺ��Ѵ�.

				int qSize = q.size();

				string num1, ope;

				bool needCul = false;

				for (int i = 0; i < qSize; i++) {

					string data = q.front();
					q.pop();

					if (data == "+" || data == "-" || data == "*") {

						ope = data;

						if (ope == oper) {
							// �����ؾ��� �����ڶ�� flag�� true�� �ٲ��ش�.
							// ���� ���ڿ� ����.
							needCul = true;
						}
						else {
							// ������ �ʿ� ���� �������̹Ƿ� �ٽ� ť�� ����.
							q.push(num1);
							q.push(ope);
						}
					}
					else {

						if (needCul == true) {
							// ������ Ȯ���� �����ڸ� �̿��� ������ �ؾ��Ѵ�.
							string num2 = data;
							num1 = to_string(cf(stol(num1), stol(num2), ope));
							needCul = false;
						}
						else {
							num1 = data;
						}

						if (i == qSize - 1)
							q.push(num1);
					}
				}
			}

			return stol(q.front());

		}

		long long solution(string expression) {

			long long answer = 0;

			set<string> operators; // ������ set.

			queue<string> q;

			string num = "";

			// ���ڿ� �����ڸ� �и��Ͽ� ť�� �����ϴ� ���ÿ�
			// ������ set ����.
			for (int i = 0; i < expression.length(); i++) {

				if (48 <= expression[i] && expression[i] <= 57) {
					num += expression[i];
				}
				else {
					// ������
					string oper = "";
					oper += expression[i];
					operators.insert(oper);
					q.push(num);
					q.push(oper);
					num = "";
				}

				if (i == expression.length() - 1) {
					q.push(num);
				}
			}

			// �������� ������ ���� vector�� �ٽ� ����.
			vector<string> op;

			for (auto a : operators)
				op.push_back(a);

			// next_permutation �Լ��� ���� ���� sorting.
			sort(op.begin(), op.end());

			// ��� �������� ������ ����Ͽ� ���� ū ���� ����.
			do {

				long long calResult = abs(calFunc(q, op));

				if (calResult > answer)
					answer = calResult;

			} while (next_permutation(op.begin(), op.end()));

			return answer;
		}

		void execute() {

			string exp = "100-200*300-500+20";
			cout << solution(exp);
		}
	}
}