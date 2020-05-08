#include<bits/stdc++.h>
using namespace std;
struct node{
	int data,depth;
	node *lchild,*rchild;
};
vector<int>temp,ans;
int in[40],post[40],n,maxd=-1;
node *create(int inl,int inr,int postl,int postr){
	if(inl>inr) return NULL;
	node *root=new node;
	root->data=post[postr];
	int k;
	for(k=inl;k<=inr;k++){
		if(post[postr]==in[k]){
			break;
		}
	}
	int numleft=k-inl;
	root->lchild=create(inl,k-1,postl,postl+numleft-1);
	root->rchild=create(k+1,inr,postl+numleft,postr-1);
	return root;
}
void BFS(node *root){
	int last=1;
	queue<node*>q;
	root->depth=1;
	q.push(root);
	while(!q.empty()){
		node *now=q.front();
		maxd=max(maxd,now->depth);
		q.pop();
		if(now->depth%2==1){
			temp.push_back(now->data);
		}else{
			if(last%2==1){
				for(int i=temp.size()-1;i>=0;i--){
					ans.push_back(temp[i]);
				}
				temp.clear();
			}
			ans.push_back(now->data);
		}
		
		if(now->depth!=last) last=now->depth;
		if(now->lchild!=NULL) {
			now->lchild->depth=now->depth+1;
			q.push(now->lchild);
		}
		if(now->rchild!=NULL) {
			now->rchild->depth=now->depth+1;
			q.push(now->rchild);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	node *root=create(0,n-1,0,n-1);
	BFS(root);
	if(maxd%2==1){    //如果最后一层是奇数层，temp里的数还没有赋给ans，这里将其赋值 
		for(int i=temp.size()-1;i>=0;i--){
			ans.push_back(temp[i]);
		}
	}
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i!=ans.size()-1) printf(" ");
	}
	return 0;
}
/*
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=40;
int n,m,in[maxn],post[maxn],level[maxn],num=0;
vector<int> temp;
struct node
{
	int data,level;
	node *lchild,*rchild;
};
void BFS(node * root)
{
	queue<node * > q;
	root->level=1;
	int pos=1;
	q.push(root);
	while(q.size())
	{
		node * x=q.front();
		q.pop();
		if(x->level!=pos)
		{
			if(pos%2==1)
				for(int i=temp.size()-1;i>=0;--i)
					level[num++]=temp[i];
			else
				for(int i=0;i<temp.size();++i)
					level[num++]=temp[i];
			temp.clear();
			++pos;
		}
		temp.push_back(x->data);
		if(x->lchild!=NULL)
		{
			x->lchild->level=x->level+1;
			q.push(x->lchild);
		}
		if(x->rchild!=NULL)
		{
			x->rchild->level=x->level+1;
			q.push(x->rchild);
		}
	}
	if(pos%2==1)
		for(int i=temp.size()-1;i>=0;--i)
			level[num++]=temp[i];
	else
		for(int i=0;i<temp.size();++i)
			level[num++]=temp[i];
}
node * create(int inL,int inR,int postL,int postR)
{
	if(inL>inR)
		return NULL;
	int i;
	for(i=inL;i<=inR;++i)
		if(in[i]==post[postR])
			break;
	node * root=new node();
	root->data=post[postR];
	root->lchild=create(inL,i-1,postL,postL+i-1-inL);
	root->rchild=create(i+1,inR,postL+i-inL,postR-1);
	return root;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&in[i]);
	for(int i=0;i<n;++i)
		scanf("%d",&post[i]);
	node * root=create(0,n-1,0,n-1);
	BFS(root);
	for(int i=0;i<n;++i)
		printf("%d%c",level[i],i<n-1?' ':'\n');
	return 0;
}*/
