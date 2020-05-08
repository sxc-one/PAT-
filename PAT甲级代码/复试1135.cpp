#include<bits/stdc++.h>
using namespace std;
int arr[40];
struct node{
	int val;
	node *left,*right;
};
void bulid(node *&root,int v){
	if(root==NULL){
		root=new node;
		root->val=v;
		root->left=root->right=NULL;
		return;
	}else if(abs(v)<=abs(root->val)) bulid(root->left,v);
	else bulid(root->right,v);
}
bool judge1(node *root){
	if(root==NULL) return true;
	if(root->val<0){
		if(root->left!=NULL&&root->left->val<0) return false;
		if(root->right!=NULL&&root->right->val<0) return false;
	}
	return judge1(root->left)&&judge1(root->right);
}
int getNum(node *root){		
	if(root==NULL) return 0;
	int l=getNum(root->left);
	int r=getNum(root->right);
	return root->val>0?max(l,r)+1:max(l,r);
}
bool judge2(node *root){		//这个函数的写法很像lca函数，可对比学习记忆 
	if(root==NULL) return true;
	int l=getNum(root->left);
	int r=getNum(root->right);
	if(l!=r) return false;
	return judge2(root->left)&&judge2(root->right);
}
int main(){
	int k,n;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&n);
		node *root=NULL;
		for(int j=0;j<n;j++){
			scanf("%d",&arr[j]);
			bulid(root,arr[j]);
		}
		if(arr[0]<0||judge1(root)==false||judge2(root)==false) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
/*  以下为自己第二遍做到此题时的冗长的代码，得21分，失分原因不详 
#include<bits/stdc++.h>
using namespace std;
const int maxn=40;
struct node{
	int data;
	node *lchild,*rchild;
};
bool flag;
vector<int>temp;
set<int>st;
void insert(node *&root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(abs(data)<abs(root->data)) insert(root->lchild,data);
	else insert(root->rchild,data);
}
void dfs(node *root){
	if(root==NULL) return;
	if(root->lchild==NULL&&root->rchild==NULL){
		int num=0; 
		for(int i=0;i<temp.size();i++){
			if(temp[i]>0) num++;
		} 
		st.insert(num);
		return;
	}
	if(root->lchild!=NULL)	{
		temp.push_back(root->lchild->data);
		dfs(root->lchild);
		temp.pop_back();
	}
	if(root->rchild!=NULL){
		temp.push_back(root->rchild->data);
		dfs(root->rchild);
		temp.pop_back();
	}	
}
void judge(node *root){
	if(root==NULL) return;
	if(root->data<0){
		if(root->lchild!=NULL){
			if(root->lchild->data<0) flag=false;
		}
		if(root->rchild!=NULL){
			if(root->rchild->data<0) flag=false;
		}
	}
	temp.clear();
	temp.push_back(root->data);
	st.clear();
	dfs(root);
	if(st.size()!=1) flag=false;
	judge(root->lchild);
	judge(root->rchild);
}

int main() {
	int k;
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		node *root=NULL;
		for(int i=0;i<n;i++){
			int data;
			cin>>data;
			insert(root,data);
		}
		flag=true;
		if(root->data<0) flag=false;
		judge(root);
		printf(flag?"Yes\n":"No\n");
	}
	return 0;
}
*/
