#include<bits/stdc++.h>
using namespace std;
const int maxn=50100;
int pre[maxn],in[maxn];
struct node{
	int data;
	node *lchild,*rchild;
};
vector<int>ans;
node *create(int prel,int prer,int inl,int inr){
	if(prel>prer) return NULL;
	node *root=new node;
	root->data=pre[prel];
	int k;
	for(k=inl;k<=inr;k++){
		if(in[k]==pre[prel]) break;
	}
	int numleft=k-inl;
	root->lchild=create(prel+1,prel+numleft,inl,k-1);
	root->rchild=create(prel+numleft+1,prer,k+1,inr);
	return root;
}
void post(node *root){
	if(root==NULL) return;
	post(root->lchild);
	post(root->rchild);
	ans.push_back(root->data);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	node *root=create(0,n-1,0,n-1);
	post(root);
	printf("%d",ans[0]);
	return 0;
}
