#include<bits/stdc++.h>
using namespace std;
struct node{
	int data,height;
	node *lchild,*rchild;
};
int n;
bool flag=true;
int geth(node* root){
	if(root==NULL) return 0;
	return root->height;
}
void update(node *root){
	root->height=max(geth(root->lchild),geth(root->rchild))+1;
}
int ban(node *root){
	return geth(root->lchild)-geth(root->rchild);
}
void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	update(root);
	update(temp);
	root=temp; 
}
void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	update(root);
	update(temp);
	root=temp;
}
void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->height=1;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(data<root->data){
		insert(root->lchild,data);
		update(root);
		if(ban(root)==2){
			if(ban(root->lchild)==1){
				R(root);
			}else if(ban(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild,data);
		update(root);
		if(ban(root)==-2){
			if(ban(root->rchild)==-1){
				L(root);
			}else if(ban(root->rchild)==1){
				R(root->rchild);
				L(root);
			}
		}
	}
}
void BFS(node *root){
	queue<node*>q;
	q.push(root);
	while(n){
		node *now=q.front();
		q.pop();
		if(now==NULL) flag=false;
		else{
			printf("%d",now->data);
		    n--;
		    if(n!=0) printf(" ");
		    else printf("\n");
		    q.push(now->lchild);
		    q.push(now->rchild);	
		}
		
	}
   	if(flag) printf("YES");
   	else printf("NO");
}
int main(){
	int data;
	scanf("%d",&n);
	node *root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(root,data);
	}
	BFS(root);
	return 0;
} 
/*#include <cstdio>  //方法二：给节点编号判断完全二叉树 
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn=30;
int n,level[maxn],maxnum=-1,num=0,t;
struct node
{
	int data,height,no;
	node * lchild,* rchild;
};
int getHeight(node * root)
{
	if(root==NULL)
		return 0;
	return root->height;
}
void update(node * root)
{
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
void L(node * &root)
{
	node * temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	update(root);
	update(temp);
	root=temp;
}
void R(node * &root)
{
	node * temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	update(root);
	update(temp);
	root=temp;
}
int getBalance(node * root)
{
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void insert(node * &root,int data)
{
	if(root==NULL)
	{
		root=new node();
		root->rchild=root->lchild=NULL;
		root->data=data;
		root->height=1;
		return ;
	}
	if(data<=root->data)
	{
		insert(root->lchild,data);
		update(root);
		if(getBalance(root)==2)
		{
			if(getBalance(root->lchild)==1)
				R(root);
			else if(getBalance(root->lchild)==-1)
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild,data);
		update(root);
		if(getBalance(root)==-2)
		{
			if(getBalance(root->rchild)==-1)
				L(root);
			else if(getBalance(root->rchild)==1)
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}
void BFS(node * root)
{
	queue<node *> q;
	root->no=1;
	maxnum=maxnum>root->no?maxnum:root->no;
	q.push(root);
	while(q.size())
	{
		node *x=q.front();
		level[num++]=x->data;
		q.pop();
		if(x->lchild!=NULL)
		{
			int lev=x->no*2;
			x->lchild->no=lev;
			maxnum=maxnum>lev?maxnum:lev;
			q.push(x->lchild);
		}
		if(x->rchild!=NULL)
		{
			int lev=x->no*2+1;
			x->rchild->no=lev;
			maxnum=maxnum>lev?maxnum:lev;
			q.push(x->rchild);
		}
	}
}
int main()
{
	scanf("%d",&n);
	node *root=NULL;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&t);
		insert(root,t);
	}
	BFS(root);
	for(int i=0;i<n;++i)
		printf("%d%c",level[i],i<n-1?' ':'\n');
	printf("%s",maxnum==n?"YES\n":"NO\n");
	return 0;
}*/
