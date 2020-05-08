#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct Node{
	int add,data,next;
}node[maxn],ans[maxn];
int main(){
	int s,n,k;
	scanf("%d%d%d",&s,&n,&k);
	for(int i=0;i<n;i++){
		int address;
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].add=address;
	}
	int num=0;
	for(int p=s;p!=-1;p=node[p].next){
		if(node[p].data<0) ans[num++]=node[p];
	}
	for(int p=s;p!=-1;p=node[p].next){
		if(node[p].data>=0&&node[p].data<=k) ans[num++]=node[p];
	}
	for(int p=s;p!=-1;p=node[p].next){
		if(node[p].data>k) ans[num++]=node[p];
	}
	for(int i=0;i<num-1;i++){
		printf("%05d %d %05d\n",ans[i].add,ans[i].data,ans[i+1].add);
	}
	printf("%05d %d -1\n",ans[num-1].add,ans[num-1].data);
	return 0;
}
