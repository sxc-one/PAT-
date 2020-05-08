#include<bits/stdc++.h>
#include<cstdio>
#include<set>
using namespace std;
set<int>num[55];
int main() {
	int n, k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int m, x;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &x);
			num[i].insert(x);
		}
	}
	scanf("%d", &k);
	int s1, s2;
	for (int i = 0; i < k; i++) {
		int same=0;
		scanf("%d%d", &s1, &s2);
		for (auto it = num[s1].begin(); it != num[s1].end(); it++) {
			if (num[s2].count(*it)) same++;
		}
		printf("%.1f%\n", 100.0*same / (num[s1].size() + num[s2].size()-same));
	}
	return 0;
}
