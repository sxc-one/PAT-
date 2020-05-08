
#include <iostream>
#include <algorithm>
#include "string"
using namespace std;
int main() {
	int n;
	scanf("%d\n", &n);
	string ans;
	for(int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		int lens = s.length();
		reverse(s.begin(), s.end());//反转字符串 从末尾开始比对
		if(i == 0) {
			ans = s;
			continue;
		} else {
			int lenans = ans.length();
			int minlen = min(lens, lenans);
			for(int j = 0; j < minlen; j++) {
				if(ans[j] != s[j]) {
					ans = ans.substr(0, j);//截取最短的公共部分
					break;
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.length() == 0) ans = "nai\n";
	cout << ans;
	return 0;
}
