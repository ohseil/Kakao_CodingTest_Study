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

		// line에서 날짜 빼고 시간, 분, 초를 초로 환산한다.
		// 환산 결과를 시작시간, 완료시간 두가지 페어로 벡터에 저장.
	}

	// 시작시간 기준 오름차순으로 정렬
	sort(datas.begin(), datas.end(), comp);

	// 검색 전 처음 시간을 맨 처음 데이터의 시작시간으로 설정.
	// 그 후에 다음 데이터의 시작시간을 포함하도록 1초 구간을 설정하여 개수 확인.
	// 위의 방식으로 마지막 데이터까지 검색.
	// 이 중 가장 많은 개수가 포함된 구간 출력.

	return answer;
}

namespace KakaoBlind2018 {

	namespace problem15 {

		void execute() {

		}
	}
}