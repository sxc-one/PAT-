#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct Node{
	double data;
	int layer;
	vector<int>child;
}node[maxn];
int n;
double p,r,ans=0;
void DFS(int index,int depth){
	if(node[index].child.size()==0){
		ans+=node[index].data*pow(1+r/100,depth);
		return;
	}
	for(int i=0;i<node[index].child.size();i++){
		DFS(node[index].child[i],depth+1);
			}
}
/*void BFS(int root){
	queue<int>q;
	q.push(root);
	node[root].layer=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(node[now].child.size()==0) ans+=node[now].data*pow(1+r/100,node[now].layer);
		for(int i=0;i<node[now].child.size();i++){
			int child=node[now].child[i];
			node[child].layer=node[now].layer+1;
			q.push(child);
		}
	}
}*/
int main(){
	int child,k;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k==0) scanf("%lf",&node[i].data);
		else{
			for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[i].child.push_back(child);
		}
		}	
	}
	//BFS(0);
	DFS(0,0);
	printf("%.1f",ans*p);
	return 0;
}
