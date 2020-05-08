#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct Node{
	int next;
	char data;
	bool flag;
}node[maxn];
int main(){
	int s1,s2,n,address;
	scanf("%d%d%d",&s1,&s2,&n);
	for(int i=0;i<n;i++){
		scanf("%d ",&address);
		scanf("%c %d",&node[address].data,&node[address].next);
	}
	int p;
	for(p=s1;p!=-1;p=node[p].next){
		node[p].flag=true;
	}
	for(p=s2;p!=-1;p=node[p].next){
		if(node[p].flag==true){
            break;
		}
	}
	if(p!=-1) printf("%05d",p);
	else printf("-1");
	return 0;
}
