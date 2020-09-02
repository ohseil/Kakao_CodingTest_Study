#include "problem33.h"

namespace KakaoIntern2020 {

	namespace problem33 {

		// 숫자 2개와 연산자의 연산 결과값을 반환하는 함수
		long long cf(long long num1, long long num2, string oper) {
			if (oper == "+")
				return num1 + num2;
			else if (oper == "-")
				return num1 - num2;
			else
				return num1 * num2;
		}

		long long calFunc(queue<string> q, vector<string> op) {

			// 입력된 연산자 순서대로 계산
			for (string oper : op) {

				// 기본 루틴은 숫자와 연산자 하나씩 뽑아서
				// num1과 ope 변수에 숫자와 연산자를 저장하고,
				// 별일 없으면 다시 queue에 삽입한다.
				// ope가 연산해야할 연산자라면 flag를 true로 변경하여
				// 다음에 확인하는 숫자에서 num1과 연산을 한 결과값을 num1에 저장하고
				// 다음 연산자값을 ope에 저장한다.
				// 마찬가지로 ope에 저장된 연산자가 연산이 필요없는 연산자라면
				// num1과 ope를 다시 queue에 삽입한다.
				// 위과정을 반복한다.

				int qSize = q.size();

				string num1, ope;

				bool needCul = false;

				for (int i = 0; i < qSize; i++) {

					string data = q.front();
					q.pop();

					if (data == "+" || data == "-" || data == "*") {

						ope = data;

						if (ope == oper) {
							// 연산해야할 연산자라면 flag를 true로 바꿔준다.
							// 다음 숫자와 연산.
							needCul = true;
						}
						else {
							// 연산할 필요 없는 연산자이므로 다시 큐에 삽입.
							q.push(num1);
							q.push(ope);
						}
					}
					else {

						if (needCul == true) {
							// 이전에 확인한 연산자를 이용해 연산을 해야한다.
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

			set<string> operators; // 연산자 set.

			queue<string> q;

			string num = "";

			// 숫자와 연산자를 분리하여 큐에 삽입하는 동시에
			// 연산자 set 설정.
			for (int i = 0; i < expression.length(); i++) {

				if (48 <= expression[i] && expression[i] <= 57) {
					num += expression[i];
				}
				else {
					// 연산자
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

			// 연산자의 순서를 위해 vector에 다시 저장.
			vector<string> op;

			for (auto a : operators)
				op.push_back(a);

			// next_permutation 함수를 쓰기 위해 sorting.
			sort(op.begin(), op.end());

			// 모든 연산자의 순서로 계산하여 가장 큰 값이 정답.
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