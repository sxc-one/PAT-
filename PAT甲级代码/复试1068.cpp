#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010], w[10010];
bool choice[10010][110];
int cmp1(int a, int b){
	return a > b;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	scanf("%d", &w[i]);	//价值和重量相等 
	sort(w + 1, w + n + 1, cmp1);	//从大到小排 
	for(int i = 1; i <= n; i++) {	//该二重for为模板，遍历每一个数，是从大到小遍历的 
		for(int j = m; j >= w[i]; j--) {	// 对每一个数，容量从最大容量到这个数的重量，不能再小了，否则下一行的j-w[i]将为负数 
			if(dp[j-w[i]] + w[i] >= dp[j]) {	// 模板，相等也要更新，因为小的数在后面 
				choice[i][j] = true;
				dp[j] = dp[j-w[i]] + w[i];
			}
		}
	}
	if(dp[m] != m) printf("No Solution");	//因价值与重量相等，d[m]不等于m即无解 
	else {
		vector<int> arr;
		int v = m, index = n;	
		while(v > 0) {	//从后往前找，后面是较小的数 
			if(choice[index][v] == true) {	// 若选了index号 
				arr.push_back(w[index]);	//加入结果 
				v -= w[index];	//减去index的容量 
			}
			index--;	//检查下一个数 
		}
		for(int i = 0; i < arr.size(); i++) {	//arr中已按要求存储（从小到大） 
			if(i != 0) printf(" ");
			printf("%d", arr[i]);
		}
	}
return 0;
}
