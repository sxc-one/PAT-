#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int father[maxn],root[maxn];
void init(){
	for(int i=1;i<maxn;i++){
		father[i]=i;
	}
}
int find(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void Union(int a,int b){
	int faa=find(a);
	int fab=find(b);
	if(faa!=fab){
		father[faa]=fab;
	}
}
int main(){
	init();
	int n,k,b1,b2,num=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&k,&b1);
		if(b1>num) num=b1;
		for(int j=0;j<k-1;j++){
			scanf("%d",&b2);
			if(b2>num) num=b2;
			Union(b1,b2);
		}
	}
	int tree=0;
	for(int i=1;i<=num;i++){
		root[find(i)]++;
	}
	for(int i=1;i<=num;i++){
		if(root[i]!=0) tree++;
	}
	printf("%d %d\n",tree,num);
	int q,a,b;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&a,&b);
		if(find(a)!=find(b)) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
