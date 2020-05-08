#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct Node{
	int address,data,next;
	int order;
}node[maxn],sec[maxn];
bool hasht[10010];
bool cmp(Node a,Node b){
	return a.order<b.order;
}
int main(){
	for(int i=0;i<maxn;i++){
		node[i].order=maxn;
	}
	int address,begin,n;
	scanf("%d%d",&begin,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int count=0,num=0;
	for(int p=begin;p!=-1;p=node[p].next){
		if(hasht[abs(node[p].data)]){
			sec[num++]=node[p];
			continue;
		}
		hasht[abs(node[p].data)]=true;
		node[p].order=count++;
	}
	sort(node,node+maxn,cmp);
	for(int i=0;i<count-1;i++){
		printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
	}
	printf("%05d %d -1\n",node[count-1].address,node[count-1].data);
	if(num!=0){  //不一定有重复节点，若所有节点都不重复，下面语句应不执行，测试点2不通过就是因为此 
		for(int i=0;i<num-1;i++){
		printf("%05d %d %05d\n",sec[i].address,sec[i].data,sec[i+1].address);
	}
	printf("%05d %d -1\n",sec[num-1].address,sec[num-1].data);
	}
	return 0;
}
