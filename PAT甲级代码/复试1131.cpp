#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> v[10000]; //ͼ���ڽӱ��ڵ������ɴ�10000�� 
int visit[10000], minCnt, minTransfer, start, end1; // ���پ�����վ���������ٻ���վ�� 
unordered_map<int, int> line;  //��һ��int����һ��8λ���ִ洢����վ����һ��վ��*10000����ǰ��λ��+�ڶ���վ�ţ��ڶ���intΪ������վ����·�Ǽ����ߵ� 
vector<int> path, tempPath;  //��ʱ·��������·�� 
int transferCnt(vector<int> a) { //����һ��·�����㻻��վ�� 
	int cnt = -1, preLine = 0;  //preline����һ����· 
	for (int i = 1; i < a.size(); i++) {
		if (line[a[i-1]*10000+a[i]] != preLine) cnt++;  //��ǰ����վ����·����һ�����ȣ�˵���л���վ 
		preLine = line[a[i-1]*10000+a[i]];  //����preline 
	}
	return cnt; 
}
void dfs(int node, int cnt) {  //���������;�ͣվ���� 
	if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {  //�������溯��������ʱ·���Ļ���վ�� 
		minCnt = cnt;	//���if�ǵݹ���ڣ�����ǰ�ڵ����յ�վ���ң���ͣվ���ٻ��߾�ͣվ��ȵ�����վ���٣���������پ�ͣվ�����ٻ���վ������·�� 
		minTransfer = transferCnt(tempPath);
		path = tempPath;
	}
	if (node == end1) return;	//�ݹ���ڣ���������������¶�Ҫ������ 
	for (int i = 0; i < v[node].size(); i++) {	//�Ե�ǰ�ڵ�������ڽӵ� 
		if (visit[v[node][i]] == 0) {	//��û���ʣ�����һ��ݹ�ǰ��Ϊ�ѷ��ʲ����ڽӵ������ʱ·�� 
			visit[v[node][i]] = 1;	 
			tempPath.push_back(v[node][i]);
			dfs(v[node][i], cnt + 1);
			visit[v[node][i]] = 0; //����һ����ݺ���Ϊδ���ʣ�֮����ܻ�Ҫ���ʵģ������ٽ��ɾ�� 
			tempPath.pop_back();
		}
	}
}
int main() {
	int n, m, k, pre, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { //n����· 
		scanf("%d%d", &m, &pre);	//ÿ����·��վ�����͵�һ��վ����ÿ����վ��ǰһ��վ�� 
		for (int j = 1; j < m; j++) {	//����m-1��վ 
			scanf("%d", &temp);	//������һ��վ 
			v[pre].push_back(temp);	//��ͼ 
			v[temp].push_back(pre);	//��ͼ 
			line[pre*10000+temp] = line[temp*10000+pre] = i + 1;	//������վ֮�����·Ϊ��ǰ��·i+1 
			pre = temp;	//��һ��վ �� ǰһ��վ 
		}
	}
	scanf("%d", &k);	//k����ѯ 
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &start, &end1);
		minCnt = 99999, minTransfer = 99999;	
		tempPath.clear();	//ÿ��ѭ�������ʱ·�� 
		tempPath.push_back(start);	//����dfsд������ǲ���·���еģ����ȼ���·�� 
		visit[start] = 1;	//�����Ϊ�ѷ��� 
		dfs(start, 0);	//��������㲻���ھ�ͣվ�� 
		visit[start] = 0;	//������Ͻ������Ϊδ���ʣ������д�������֮������нڵ���dfs�ھ���true����ԭ�ˣ����ֻ�軹ԭ���Ϊδ���ʶ�����Ҫ��������vis 
		printf("%d\n", minCnt);	//�����С��ͣվ�� 
		int preLine = 0, preTransfer = start;	//��һ����·��Ϊ0����һ������վ��Ϊ��� 
		for (int j = 1; j < path.size(); j++) {	//��ʱpath������·�����ӵڶ���վ�㿪ʼ 
			if (line[path[j-1]*10000+path[j]] != preLine) {	//��ǰһ��վ��ͺ�һ��վ��֮���·������һ����ͬ��˵���л��ˣ�Ҫ����������� 
				if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n",preLine, preTransfer, path[j-1]);	//�����һ����·����һ������վ����ǰվ��ǰһ��վ����ǰվ�Ѿ�������·�ˣ� 
				preLine = line[path[j-1]*10000+path[j]];	//������һ����·Ϊ����· 
				preTransfer = path[j-1];	//������һ������վΪ��ǰվ��ǰһ��վ 
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer,end1);	//���һ������վ���յ� 
	}
	return 0;
}

