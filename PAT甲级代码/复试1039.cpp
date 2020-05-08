#include<bits/stdc++.h>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 1;
vector<int>course[maxn];
int getid(char str[]) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + str[i] - 'A';
	}
	id = id * 10 + str[3] - '0';
	return id;
}
int main() {
	char name[5];
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int index, x;
		scanf("%d%d", &index, &x);
		for (int j = 0; j < x; j++) {
			scanf("%s", name);
			int id = getid(name);
			course[id].push_back(index);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		int id = getid(name);
		printf("%s %d", name,course[id].size());
		sort(course[id].begin(), course[id].end());
		for (int j = 0; j < course[id].size(); j++) {
			printf(" %d", course[id][j]);
		}
		printf("\n");
	}
	return 0;
}
