#include<cstdio>
#include<algorithm> 
#include<queue>
using namespace std;
const int maxn=110;
struct Node{
	int data,lchild,rchild;
}node[maxn];
int num[maxn],n,index=0;
void in(int root){
	if(root==-1) return;
	in(node[root].lchild);
	node[root].data=num[index++];
	in(node[root].rchild);
}
void BFS(int root){
	int count=0;
	queue<int>q;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		printf("%d",node[now].data);
		count++;
		if(count!=n) printf(" ");
		if(node[now].lchild!=-1) q.push(node[now].lchild);
		if(node[now].rchild!=-1) q.push(node[now].rchild);
	} 
}
int main(){
	int lchild,rchild;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&lchild,&rchild);
		node[i].lchild=lchild;
		node[i].rchild=rchild;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	sort(num,num+n);
	in(0);
	BFS(0);
	return 0;
}
