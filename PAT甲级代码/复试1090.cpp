#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
vector<int>child[maxn];
int n,maxdepth=-1,num;
double p,r;
void DFS(int index,int depth){
	if(child[index].size()==0){
		if(depth>maxdepth){
			maxdepth=depth;
			num=1;
		}else if(depth==maxdepth){
			num++;
		}
		return;
	}
	for(int i=0;i<child[index].size();i++){
		DFS(child[index][i],depth+1);
	}
}
int main(){
	int father,root;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		scanf("%d",&father);
		if(father==-1) root=i;
		else child[father].push_back(i);
	}
	DFS(root,0);
	printf("%.2f %d",pow(1+r/100,maxdepth)*p,num);
	return 0;
}
/*struct Node{
	vector<int>child;
	int layer;
}node[maxn];
int n,maxdepth=-1,num=0;
double p,r;
void BFS(int root){
	queue<int>q;
	q.push(root);
	node[root].layer=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(node[now].layer>maxdepth){
			maxdepth=node[now].layer;
			num=1;
		}else if(node[now].layer==maxdepth){
			num++;
		}
		for(int i=0;i<node[now].child.size();i++){ 
			int child=node[now].child[i];
			node[child].layer=node[now].layer+1;
			q.push(child);
		}
	}
}*/
/*int main(){
	int father,root;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		scanf("%d",&father);
		if(father==-1) root=i;
		else node[father].child.push_back(i);
	}
	BFS(root);
	printf("%.2f %d",pow(1+r/100,maxdepth)*p,num);
	return 0;
}*/
