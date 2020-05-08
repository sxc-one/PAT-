#include<bits/stdc++.h>
using namespace std;
struct node{
	int data,height;
	node *left,*right;
};
int geth(node* root){
	if(root==NULL) return 0;
	return root->height;
}
void up(node* root){
	root->height=max(geth(root->left),geth(root->right))+1;
}
int ban(node* root){
	return geth(root->left)-geth(root->right);
}
void L(node* &root){
	node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	up(root);
	up(temp);
	root=temp;
}
void R(node* &root){
	node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	up(root);
	up(temp);
	root=temp;
}
void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->height=1;
		root->left=root->right=NULL;
		return;
	}
	if(data<root->data){
		insert(root->left,data);
		up(root);
		if(ban(root)==2){
			if(ban(root->left)==1){
				R(root);
			}else if(ban(root->left)==-1){
				L(root->left);
				R(root);
			}
		}
	}else{
		insert(root->right,data);
		up(root);
		if(ban(root)==-2){
			if(ban(root->right)==-1){
				L(root);
			}else if(ban(root->right)==1){
				R(root->right);
				L(root);
			}
		}
	}
}
int main(){
	int n,data;
	scanf("%d",&n);
	node* root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(root,data);
	}
	printf("%d",root->data);
	return 0;
}

