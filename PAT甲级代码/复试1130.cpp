#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
struct Node{
	char str[15];
	int lchild,rchild;
}node[maxn];
bool notroot[maxn];
int root;
void inorder(int x){
	if(x==-1) return;
	if(x!=root&&(node[x].lchild!=-1||node[x].rchild!=-1)) printf("(");//不是根节点并且不是叶节点 
		inorder(node[x].lchild);
	    printf("%s",node[x].str);
	    inorder(node[x].rchild);
	if(x!=root&&(node[x].lchild!=-1||node[x].rchild!=-1)) printf(")");
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s%d%d",node[i].str,&node[i].lchild,&node[i].rchild);
		notroot[node[i].lchild]=notroot[node[i].rchild]=true;
	}
	for(int i=1;i<=n;i++){
		if(notroot[i]==false){
			root=i;
			break;
		}
	} 
	inorder(root);
	return 0;
}
