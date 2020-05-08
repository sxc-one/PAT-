#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *lchild,*rchild;
};
int pre[100010];
//map<int,bool>hasht;
/*void insert(node *&root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(data<root->data) insert(root->lchild,data);
	else insert(root->rchild,data);
}*/
node* create(int preL,int preR){
    if(preL>preR) return NULL;
    node* now = new node;
    now->data = pre[preL];
    int i;
    for(i=preL+1;i<=preR;i++){
        if(pre[i]>=pre[preL]) break;
    }
    now->lchild = create(preL+1,i-1);
    now->rchild = create(i,preR);
    return now;
}
node* lca(node* root,int a,int b){          //¶þ²æËÑË÷Ê÷ÕÒLCA
    if(root->data > max(a,b)) return lca(root->lchild,a,b);
    else if(root->data < min(a,b)) return lca(root->rchild,a,b);
    else return root;
}
/*node *lca(node *root,int u,int v){      //Ò»°ãÊ÷ 
	if(root==NULL) return NULL;
	if(root->data==u||root->data==v) return root;
	node *l=lca(root->lchild,u,v);
	node *r=lca(root->rchild,u,v);
	if(l!=NULL&&r!=NULL) return root;
	return l==NULL?r:l;
}*/
int main(){
	int m,n,data;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	node *root=create(0,n-1);
	while(m--){
		int a,b,pos1=n,pos2=n;
		scanf("%d%d",&a,&b);
		for(int i=0;i<n;i++){
			if(pre[i]==a) pos1=i;
			if(pre[i]==b) pos2=i; 
		}
		if(pos1==n&&pos2==n){
			printf("ERROR: %d and %d are not found.\n",a,b);
		}else if(pos1==n){
			printf("ERROR: %d is not found.\n",a);
		}else if(pos2==n){
			printf("ERROR: %d is not found.\n",b);
		}else{
			node *t=lca(root,a,b);
			if(t->data==a||t->data==b){
				printf("%d is an ancestor of %d.\n",t->data==a?a:b,t->data==a?b:a);
			}else{
				printf("LCA of %d and %d is %d.\n",a,b,t->data);
			}
		}
	}
	return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>

using namespace std;
const int maxn = 10010;
int pre[maxn];
struct node{
    int val;
    node* left;
    node* right;
};
map<int,node*>mp;

node* create(int preL,int preR){
    if(preL>preR) return NULL;
    node* now = new node;
    now->val = pre[preL];
    int i;
    for(i=preL+1;i<=preR;i++){
        if(pre[i]>=pre[preL]) break;
    }
    int numLeft=i-preL-1;
    now->left = create(preL+1,i-1);
    now->right = create(i,preR);
    mp[now->val] = now;
    return now;
}

node* lca(node* root,node* a,node* b){      //Ò»°ã¶þ²æÊ÷ÕÒLCA
    if(root==NULL || root==a || root==b) return root;
    node* L=lca(root->left,a,b);
    node* R=lca(root->right,a,b);
    if(L==NULL) return R;
    if(R==NULL) return L;
    return root;
}

node* lca(node* root,int a,int b){          //¶þ²æËÑË÷Ê÷ÕÒLCA
    if(root->val > max(a,b)) return lca(root->left,a,b);
    else if(root->val < min(a,b)) return lca(root->right,a,b);
    else return root;
}

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&pre[i]);
    }
    node* root=create(0,n-1);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(!mp[a] && !mp[b]) printf("ERROR: %d and %d are not found.\n",a,b);
        else if(!mp[a]) printf("ERROR: %d is not found.\n",a);
        else if(!mp[b]) printf("ERROR: %d is not found.\n",b);
        else{
            node* res=lca(root,a,b);
            if(res->val==a){
                printf("%d is an ancestor of %d.\n",a,b);
            }
            else if(res->val==b){
                printf("%d is an ancestor of %d.\n",b,a);
            }
            else{
                printf("LCA of %d and %d is %d.\n",a,b,res->val);
            }
        }
    }
    return 0;
}*/


