#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int heap[maxn],n,path[maxn],maxh,minh;
void DFS(int root,int numnode){
	if(root>n) return;
	if(root*2>n){
		for(int i=0;i<numnode;i++){
			printf("%d",heap[path[i]]);
			if(i!=numnode-1) printf(" ");
			else printf("\n");
		}
		return;
	}
	if(root*2+1<=n){
		int rchild=root*2+1;
		if(heap[root]>heap[rchild]) maxh=1;
		else minh=1;
		path[numnode]=rchild;
		DFS(rchild,numnode+1);
	}
	if(root*2<=n){
		int lchild=root*2;
		if(heap[root]>heap[lchild]) maxh=1;
		else minh=1;
		path[numnode]=lchild;
		DFS(lchild,numnode+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&heap[i]);
	}
	path[0]=1;
	DFS(1,1);
	if(minh==1&&maxh==0) printf("Min Heap");
	else if(minh==0&&maxh==1) printf("Max Heap");
	else printf("Not Heap"); 
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int tree[1010];
vector<int>path;
int n;

bool ismax=true;
bool ismin=true;
void DFS(int index,int numnode){
	if(index>n/2){
		for(int i=0;i<numnode;i++){
			printf("%d",path[i]);
			if(i<numnode-1) printf(" ");
			else printf("\n");
		}
		return;
	}
	if(index*2+1<=n) {
		if(tree[index*2+1]>tree[index]) ismax=false;
		if(tree[index*2+1]<tree[index]) ismin=false;
		path.push_back(tree[index*2+1]);
		DFS(index*2+1,numnode+1);
		path.pop_back();
	}
	if(index*2<=n) {
		if(tree[index*2]<tree[index]) ismin=false;
		if(tree[index*2]>tree[index]) ismax=false;
		path.push_back(tree[index*2]);
		DFS(index*2,numnode+1);
		path.pop_back();
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tree[i]);
	}
	path.push_back(tree[1]);
	DFS(1,1);
	if(ismax==true){
	 printf("Max Heap");
	}
	else if (ismin==true){
	printf("Min Heap");
	}
	else printf("Not Heap");
	return 0;
}*/

