#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> v[10000]; //图的邻接表，节点数最多可达10000个 
int visit[10000], minCnt, minTransfer, start, end1; // 最少经过的站点数和最少换乘站数 
unordered_map<int, int> line;  //第一个int利用一个8位数字存储两个站，第一个站号*10000（即前四位）+第二个站号，第二个int为这两个站的线路是几号线的 
vector<int> path, tempPath;  //临时路径和最优路径 
int transferCnt(vector<int> a) { //根据一条路径计算换乘站数 
	int cnt = -1, preLine = 0;  //preline是上一条线路 
	for (int i = 1; i < a.size(); i++) {
		if (line[a[i-1]*10000+a[i]] != preLine) cnt++;  //当前两个站的线路与上一条不等，说明有换乘站 
		preLine = line[a[i-1]*10000+a[i]];  //更新preline 
	}
	return cnt; 
}
void dfs(int node, int cnt) {  //传进来起点和经停站点数 
	if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {  //利用上面函数计算临时路径的换乘站数 
		minCnt = cnt;	//这个if是递归出口，若当前节点是终点站并且（经停站更少或者经停站相等但换乘站更少）则更新最少经停站、最少换乘站、最优路径 
		minTransfer = transferCnt(tempPath);
		path = tempPath;
	}
	if (node == end1) return;	//递归出口，无论上面更不更新都要返回了 
	for (int i = 0; i < v[node].size(); i++) {	//对当前节点的所有邻接点 
		if (visit[v[node][i]] == 0) {	//若没访问，向下一层递归前置为已访问并将邻接点加入临时路径 
			visit[v[node][i]] = 1;	 
			tempPath.push_back(v[node][i]);
			dfs(v[node][i], cnt + 1);
			visit[v[node][i]] = 0; //从下一层回溯后，置为未访问（之后可能还要访问的）并将临界点删除 
			tempPath.pop_back();
		}
	}
}
int main() {
	int n, m, k, pre, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { //n条线路 
		scanf("%d%d", &m, &pre);	//每条线路的站点数和第一个站（即每两个站的前一个站） 
		for (int j = 1; j < m; j++) {	//其余m-1个站 
			scanf("%d", &temp);	//读入下一个站 
			v[pre].push_back(temp);	//建图 
			v[temp].push_back(pre);	//建图 
			line[pre*10000+temp] = line[temp*10000+pre] = i + 1;	//这两个站之间的线路为当前线路i+1 
			pre = temp;	//下一个站 当 前一个站 
		}
	}
	scanf("%d", &k);	//k个查询 
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &start, &end1);
		minCnt = 99999, minTransfer = 99999;	
		tempPath.clear();	//每轮循环清空临时路径 
		tempPath.push_back(start);	//根据dfs写法起点是不在路径中的，故先加入路径 
		visit[start] = 1;	//起点置为已访问 
		dfs(start, 0);	//遍历，起点不算在经停站内 
		visit[start] = 0;	//遍历完毕将起点置为未访问，本题的写法除起点之外的所有节点在dfs内就置true并还原了，因此只需还原起点为未访问而不需要重置整个vis 
		printf("%d\n", minCnt);	//输出最小经停站数 
		int preLine = 0, preTransfer = start;	//上一条线路设为0，上一个换乘站设为起点 
		for (int j = 1; j < path.size(); j++) {	//此时path是最优路径，从第二个站点开始 
			if (line[path[j-1]*10000+path[j]] != preLine) {	//若前一个站点和后一个站点之间的路线与上一条不同，说明有换乘，要按规则输出了 
				if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n",preLine, preTransfer, path[j-1]);	//输出上一条线路，上一个换乘站，当前站的前一个站（当前站已经是新线路了） 
				preLine = line[path[j-1]*10000+path[j]];	//更新上一条线路为新线路 
				preTransfer = path[j-1];	//更新上一个换乘站为当前站的前一个站 
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer,end1);	//最后一个换乘站到终点 
	}
	return 0;
}

