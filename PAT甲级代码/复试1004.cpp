#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m,leaf[maxn],maxd=0;
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
		if(node[now].depth>maxd) maxd=node[now].depth;
		if(node[now].child.size()==0){
			leaf[node[now].depth]++;
		}
		for(int i=0;i<node[now].child.size();i++){
			int child=node[now].child[i];
			node[child].depth=node[now].depth+1;
			q.push(child);
		}
	}
}
int main(){
	int father,chil,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&father,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&chil);
			node[father].child.push_back(chil);
		}
	}
	BFS(1);
	for(int i=1;i<=maxd;i++){
		printf("%d",leaf[i]);
		if(i!=maxd) printf(" ");
	}
	return 0; 
}
/*vector<int>child[maxn];
void DFS(int index,int depth){
	if(child[index].size()==0){
		leaf[depth]++;
	}
	if(depth>maxd) maxd=depth;
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
	for(int i=1;i<=maxd;i++){
		printf("%d",leaf[i]);
		if(i!=maxd) printf(" ");
	}
	return 0; 
}*/
