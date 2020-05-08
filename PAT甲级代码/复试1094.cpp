#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int hasht[maxn];
int n,m,num=-1,layer;
struct Node{
	int depth;
	vector<int>child;
}node[maxn];
void BFS(int root){
	queue<int>q;
	node[root].depth=1;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		hasht[node[now].depth]++;
		for(int i=0;i<node[now].child.size();i++){
			int child=node[now].child[i];
			node[child].depth=node[now].depth+1;
			q.push(child);
		}
	}
}
int main(){
	int father,child,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&father,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
		    node[father].child.push_back(child);
		}
	}
	BFS(1);
	for(int i=1;i<=n;i++){
	if(hasht[i]>num){
		num=hasht[i];
		layer=i;
	}
}
	printf("%d %d",num,layer);
	return 0;
}
/*vector<int>child[maxn];
void DFS(int index,int depth){
	hasht[depth]++;
	for(int i=0;i<child[index].size();i++){
		DFS(child[index][i],depth+1);
	}
}
int main(){
	int father,chil,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&father,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&chil);
		    child[father].push_back(chil);
		}
	}
	DFS(1,1);
	for(int i=1;i<=n;i++){
	if(hasht[i]>num){
		num=hasht[i];
		layer=i;
	}
}
	printf("%d %d",num,layer);
	return 0;
}*/
