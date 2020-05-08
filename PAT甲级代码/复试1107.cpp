#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int father[maxn],root[maxn],course[maxn],n;
void init(){
	for(int i=1;i<=n;i++){
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
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int k,num;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&num);
			if(course[num]==0){
				course[num]=i;
			}else Union(i,course[num]);
		}
	}
	for(int i=1;i<=n;i++){
		root[find(i)]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(root[i]!=0) ans++;
	}
	printf("%d\n",ans);
	sort(root+1,root+n+1,cmp);
	for(int i=1;i<=ans;i++){
		printf("%d",root[i]);
		if(i!=ans) printf(" ");
	}
	return 0;
}
