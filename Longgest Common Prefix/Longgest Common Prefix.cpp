#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	int count = 0;

	for (int i1 = 0; i1 < strs[0].size(); i1++) {
		bool flag = false;

		for (int i = 0; i < strs.size(); i++) {
			if (strs[i].size() <= i1) {
				flag = true;
			}

			if (strs[i][i1] != strs[0][i1]) {
				flag = true;
			}
		}

		if (flag) {
			return strs[0].substr(0, i1);
		}
	}

	return strs[0];
}

int main() {
	vector<string> v = { "dog", "racecar", "car" };
	cout << longestCommonPrefix(v);
}