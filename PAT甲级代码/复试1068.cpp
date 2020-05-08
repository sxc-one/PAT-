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
	scanf("%d", &w[i]);	//��ֵ��������� 
	sort(w + 1, w + n + 1, cmp1);	//�Ӵ�С�� 
	for(int i = 1; i <= n; i++) {	//�ö���forΪģ�壬����ÿһ�������ǴӴ�С������ 
		for(int j = m; j >= w[i]; j--) {	// ��ÿһ����������������������������������������С�ˣ�������һ�е�j-w[i]��Ϊ���� 
			if(dp[j-w[i]] + w[i] >= dp[j]) {	// ģ�壬���ҲҪ���£���ΪС�����ں��� 
				choice[i][j] = true;
				dp[j] = dp[j-w[i]] + w[i];
			}
		}
	}
	if(dp[m] != m) printf("No Solution");	//���ֵ��������ȣ�d[m]������m���޽� 
	else {
		vector<int> arr;
		int v = m, index = n;	
		while(v > 0) {	//�Ӻ���ǰ�ң������ǽ�С���� 
			if(choice[index][v] == true) {	// ��ѡ��index�� 
				arr.push_back(w[index]);	//������ 
				v -= w[index];	//��ȥindex������ 
			}
			index--;	//�����һ���� 
		}
		for(int i = 0; i < arr.size(); i++) {	//arr���Ѱ�Ҫ��洢����С���� 
			if(i != 0) printf(" ");
			printf("%d", arr[i]);
		}
	}
return 0;
}
