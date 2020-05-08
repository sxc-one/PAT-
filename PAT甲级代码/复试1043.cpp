#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
struct node{
	int data;
	node *lchild,*rchild;
};
int n,num;
vector<int>pre,post,temp;
void insert1(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(data<root->data) insert1(root->lchild,data);
	else insert1(root->rchild,data);
}
void insert2(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(data>=root->data) insert2(root->lchild,data);
	else insert2(root->rchild,data);
}
void preorder(node* root){
	if(root==NULL) return;
	pre.push_back(root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(node* root){
	if(root==NULL) return;
	postorder(root->lchild);
	postorder(root->rchild);
	post.push_back(root->data);
}
int main(){
	scanf("%d",&n);
	node* root1=NULL;
	node* root2=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		insert1(root1,num);
		insert2(root2,num);
		temp.push_back(num);
	}
	preorder(root1);
	postorder(root1);
	if(pre==temp){
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
		    if(i!=post.size()-1) printf(" "); 
		}
		return 0;	
	}
	pre.clear();
	post.clear();
	preorder(root2);
	postorder(root2);
	if(pre==temp){
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
		    if(i!=post.size()-1) printf(" "); 
		}
		return 0;	
	}
	printf("NO\n");
	return 0;
}
