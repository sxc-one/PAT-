#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *lchild,*rchild;
};
int post[35],in[35],n;
node *create(int postl,int postr,int inl,int inr){
	if(postl>postr) return NULL;
	node* root=new node;
	root->data=post[postr];
	int k;
	for(k=inl;k<=inr;k++){
		if(in[k]==post[postr]) break;
	}
	int numleft=k-inl;
	root->lchild=create(postl,postl+numleft-1,inl,k-1);
	root->rchild=create(postl+numleft,postr-1,k+1,inr);
	return root;
}
void BFS(node* root){
	int num=0;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node* top=q.front();
		printf("%d",top->data);
		num++;
		if(num!=n) printf(" ");
		q.pop();
		if(top->lchild!=NULL) q.push(top->lchild);
		if(top->rchild!=NULL) q.push(top->rchild);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	node* root=create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}
