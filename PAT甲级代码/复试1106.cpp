#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,mindepth=maxn,num;
double p,r;
struct Node{
	int depth;
	vector<int>child;
}node[maxn];
void BFS(int root){
	queue<int>q;
	node[root].depth=0;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(node[now].child.size()==0){
			if(node[now].depth<mindepth){
				mindepth=node[now].depth;
				num=1;
			}else if(node[now].depth==mindepth) num++;
		}
		for(int i=0;i<node[now].child.size();i++){
			int child=node[now].child[i];
			node[child].depth=node[now].depth+1;
			q.push(child);
		}
	}
}
int main(){
	int k,child;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&child);
				node[i].child.push_back(child);
			}
		}
	}
	BFS(0);
	printf("%.4f %d",p*pow(1+r/100,mindepth),num);
	return 0;
}
/*vector<int>child[maxn];
void DFS(int index,int depth){
	if(child[index].size()==0){
		if(depth<mindepth){
			mindepth=depth;
			num=1;
		}else if(depth==mindepth) num++;
		return;
	}
	for(int i=0;i<child[index].size();i++){
		DFS(child[index][i],depth+1);
	}
}
int main(){
	int k,chil;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&chil);
				child[i].push_back(chil);
			}
		}
	}
	DFS(0,0);
	printf("%.4f %d",p*pow(1+r/100,mindepth),num);
	return 0;
}*/
