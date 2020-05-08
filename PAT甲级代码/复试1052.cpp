#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct Node{
	int address,data,next;
	bool flag;
}node[maxn];
bool cmp(Node a,Node b){
	if(a.flag!=b.flag) return a.flag>b.flag;
	else return a.data<b.data;
}
int main(){
	int address,n,begin;
	scanf("%d%d",&n,&begin);
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int count=0,p=begin;
	while(p!=-1){
		node[p].flag=true;
		p=node[p].next;
		count++;
	}
	if(count==0) printf("0 -1");
	else{
		sort(node,node+maxn,cmp);
	printf("%d %05d\n",count,node[0].address);
	for(int i=0;i<count-1;i++){
		printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
	}
	printf("%05d %d -1",node[count-1].address,node[count-1].data);
	}
	return 0;
}
