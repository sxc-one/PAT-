#include<bits/stdc++.h>
using namespace std;
int n,num=0;
struct Node{
	int left,right;
}node[12];
bool notroot[12];
void inorder(int root){
	if(root==-1) return;
	inorder(node[root].left);
	printf("%d",root);
	num++;
	if(num!=n) printf(" ");
	inorder(node[root].right);
}
void BFS(int root){
	queue<int>q;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		printf("%d",now);
		num++;
	    if(num!=n) printf(" ");
	    if(node[now].left!=-1) q.push(node[now].left);
	    if(node[now].right!=-1) q.push(node[now].right);
	}
}
void post(int root){
	if(root==-1) return;
	post(node[root].left);
	post(node[root].right);
	swap(node[root].left,node[root].right);
}
int main(){
	char lchild,rchild;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c %c",&lchild,&rchild);
		if(lchild=='-') node[i].left=-1;
		else{
			node[i].left=lchild-'0';
			notroot[lchild-'0']=true;
		}
		if(rchild=='-') node[i].right=-1;
		else{
			node[i].right=rchild-'0';
			notroot[rchild-'0']=true;
		}
	}
	int root;
	for(int i=0;i<n;i++){
		if(notroot[i]==false) {
			root=i;
			break;
		}
	}
	post(root);
	BFS(root);
	printf("\n");
	num=0;
	inorder(root);
	printf("\n");
	return 0;
}
