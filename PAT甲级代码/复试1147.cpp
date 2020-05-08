#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int heap[maxn],n,m,maxh,minh;
vector<int>path; 
void post(int root){
	if(root>n) return;
    if(root*2<=n){
    	if(heap[root]>heap[root*2]) maxh=1;
    	else minh=1;
    	post(root*2);
	}	
	if(root*2+1<=n){
    	if(heap[root]>heap[root*2+1]) maxh=1;
    	else minh=1;
    	post(root*2+1);
	}	
	path.push_back(heap[root]);
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++){
		maxh=0,minh=0;
		path.clear();
		for(int j=1;j<=n;j++){
			scanf("%d",&heap[j]);
		}
		post(1);
		if(maxh==1&&minh==0) printf("Max Heap\n");
		else if(maxh==0&&minh==1) printf("Min Heap\n");
		else printf("Not Heap\n");
		for(int k=0;k<path.size();k++){
			printf("%d",path[k]);
			if(k!=path.size()-1) printf(" ");
			else printf("\n");
		} 
	}
	return 0;
}
