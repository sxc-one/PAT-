#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
struct node{
	int data;
	node *lchild,*rchild;
};
int hasht[maxn],maxd=-1;
void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(data<=root->data) insert(root->lchild,data);
	else insert(root->rchild,data);
}
void DFS(node *root,int depth){
	hasht[depth]++;
	if(depth>maxd) maxd=depth;
	if(root->lchild!=NULL) DFS(root->lchild,depth+1);
	if(root->rchild!=NULL) DFS(root->rchild,depth+1);
}
int main(){
	int n,data;
	scanf("%d",&n);
	node *root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(root,data);
	}
	DFS(root,1);
	printf("%d + %d = %d",hasht[maxd],hasht[maxd-1],hasht[maxd]+hasht[maxd-1]);
	return 0;
}

