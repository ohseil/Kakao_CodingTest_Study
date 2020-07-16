#include "problem10.h"

namespace KakaoBlind2019 {

	namespace problem10 {

		bool comp(vector<int> lhs, vector<int> rhs) {
			if (lhs.size() >= rhs.size())
				return false;

			return true;
		}

		int solution(vector<vector<string>> relation) {

			int answer = 0;
			const int cNum = relation[0].size();
			bitset<9> bset;

			map<vector<int>, pair<int, map<string, int>>> m;

			for (auto r : relation) {

				int num = 1;
				bset = num;

				while (bset[cNum] == 0) {

					vector<int> canKey;
					string data = "";

					for (int i = 0; i < cNum; i++) {
						if (bset[i] == 1) {
							canKey.push_back(i);
							data += r[i];
						}
					}

					// 해당 키집합이 후보키 조건에 맞는 상태인 경우
					if (m[canKey].first != -1) {
						if (m[canKey].second[data] != 1)
							m[canKey].second[data] = 1;
						else {
							m[canKey].first = -1; // 후보키 후보에서 제거
							m[canKey].second[data]++;
						}
					}

					num++;
					bset = num;
				}
			}

			vector<vector<int>> checkedKeyset;
			vector<int> checkset;

			for (auto a : m) {
				if (a.second.first != -1) {
					checkedKeyset.push_back(a.first);
					checkset.push_back(0);
				}
			}

			sort(checkedKeyset.begin(), checkedKeyset.end(), comp);

			int ckSize = checkedKeyset.size();

			for (int i = 0; i < ckSize; i++) {

				if (checkset[i] == 0) {

					vector<int> keyset = checkedKeyset[i];

					for (int j = i + 1; j < ckSize; j++) {
						if (checkset[j] == 0) {
							// 최소성 확인
							checkset[j] = -1;
							for (int key : keyset) {
								bool isKey = false;
								for (int compare : checkedKeyset[j])
									if (key == compare) {
										isKey = true;
										break;
									}
								if (isKey == false) {
									checkset[j] = 0;
								}
							}
						}
					}
				}
			}

			for (int i = 0; i < ckSize; i++)
				if (checkset[i] == 0)
					answer++;

			return answer;
		}

		int solution2(vector<vector<string>> relation) {

			int answer = 0;
			int keyCount = relation[0].size();

			map<int, vector<int>> keymap;

			int bitsetNum = 1;
			bitset<9> b(1);

			while (!(b[keyCount] == 1))
			{
				int bitCount = b.count();
				vector<int> tempKeys;

				for (int i = 0; i < keyCount; i++)
				{
					if (b[i] == true)
						tempKeys.push_back(i);
				}

				bool check = false;

				for (auto a : keymap)
				{
					int count = 0;
					vector<int> keys = a.second;
					for (int key : keys)
					{
						for (int compare : tempKeys)
							if (compare == key)
							{
								count++;
								break;
							}
					}

					if (count == keys.size())
					{
						check = true;
						break;
					}
				}

				if (check == false)
				{
					// 최소성 만족
					// 유일성 검사
					bool isUnique = true;
					map<string, int> tempM;

					for (auto row : relation)
					{
						string str = "";
						for (auto a : tempKeys)
							str += row[a];

						if (tempM.find(str) != tempM.end())
						{
							isUnique = false;
							break;
						}

						tempM.insert(make_pair(str, 1));
					}

					if (isUnique == true)
					{
						keymap.insert(make_pair(bitsetNum, tempKeys));
						answer++;
					}
				}

				cout << "bitset: " << b << endl;

				bitsetNum++;
				b = bitsetNum;

				for (auto a : keymap) {
					vector<int> aa = a.second;

					for (int it : aa)
						cout << it << " ";
					cout << endl;
				}

				cout << endl << endl;
			}

			return answer;
		}

		void execute() {

			vector<vector<string>> v;
			vector<string> vv;

			vv.push_back("b"); vv.push_back("2"); vv.push_back("a"); vv.push_back("a"); vv.push_back("b");
			v.push_back(vv);
			vv[0] = "b"; vv[1] = "2"; vv[2] = "7"; vv[3] = "1"; vv[4] = "b";
			v.push_back(vv);
			vv[0] = "1"; vv[1] = "0"; vv[2] = "a"; vv[3] = "a"; vv[4] = "8";
			v.push_back(vv);
			vv[0] = "7"; vv[1] = "5"; vv[2] = "a"; vv[3] = "a"; vv[4] = "9";
			v.push_back(vv);
			vv[0] = "3"; vv[1] = "0"; vv[2] = "a"; vv[3] = "f"; vv[4] = "9";
			v.push_back(vv);
			//vv[0] = "600"; vv[1] = "apeach"; vv[2] = "music"; vv[3] = "2";
			//v.push_back(vv);

			cout << solution(v) << endl;
		}

	}

}