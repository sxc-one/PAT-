#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
struct node{
	int data;
	node *lchild,*rchild;
};
map<int,bool>hasht;
vector<int>x,y,temp;
int pre[maxn],in[maxn],tag=0;
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
node *lca(node *root,int u,int v){
	if(root==NULL) return NULL;
	if(root->data==u||root->data==v) return root;
	node *l=lca(root->lchild,u,v);
	node *r=lca(root->rchild,u,v);
	if(l!=NULL&&r!=NULL) return root;
	return l==NULL?r:l;
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
		hasht[in[i]]=true;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	node *root=create(0,n-1,0,n-1);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		bool flag=false;
		if(hasht.count(a)==0&&hasht.count(b)==0){
			printf("ERROR: %d and %d are not found.\n",a,b);
		}else if(hasht.count(a)==0){
			printf("ERROR: %d is not found.\n",a);
		}else if(hasht.count(b)==0){
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
/*void dfs1(node *root,int data){
	if(root==NULL) return;
	if(root->data==data){
		x=temp;
		tag=1;
		return;
	}
	if(root->lchild!=NULL){
		temp.push_back(root->lchild->data);
		dfs1(root->lchild,data);
		temp.pop_back();
		if(tag==1) return;
	} 
	if(root->rchild!=NULL){
		temp.push_back(root->rchild->data);
		dfs1(root->rchild,data);
		temp.pop_back();
		if(tag==1) return;
	} 
} 
void dfs2(node *root,int data){
	if(root==NULL) return;
	if(root->data==data){
		y=temp;
		tag=1;
		return;
	}
	if(root->lchild!=NULL){
		temp.push_back(root->lchild->data);
		dfs2(root->lchild,data);
		temp.pop_back();
		if(tag==1) return;
	} 
	if(root->rchild!=NULL){
		temp.push_back(root->rchild->data);
		dfs2(root->rchild,data);
		temp.pop_back();
		if(tag==1) return;
	} 
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
		hasht[in[i]]=true;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	node *root=create(0,n-1,0,n-1);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		bool flag=false;
		if(hasht.count(a)==0&&hasht.count(b)==0){
			printf("ERROR: %d and %d are not found.\n",a,b);
			continue;
		}else if(hasht.count(a)==0){
			printf("ERROR: %d is not found.\n",a);
			continue;
		}else if(hasht.count(b)==0){
			printf("ERROR: %d is not found.\n",b);
			continue;
		}
		temp.clear();
		tag=0;
		temp[0]=root->data;
		dfs1(root,a);
		temp.clear();
		tag=0;
		temp[0]=root->data;
		dfs2(root,b);
		for(int j=x.size()-1;j>=0;j--){
			for(int k=y.size()-1;k>=0;k--){
				if(x[j]==y[k]){
					if(x[j]==a){
						printf("%d is an ancestor of %d.\n",a,b);
						flag=true;
						break;
					}else if(y[k]==b){
						printf("%d is an ancestor of %d.\n",b,a);
						flag=true;
						break;
					}else{
						printf("LCA of %d and %d is %d.\n",a,b,x[j]);
						flag=true;
					}
				}
			}
			if(flag==true) break;
		}
	}
	return 0;
}*/
