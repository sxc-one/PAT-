#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
const int INF=0x3fffffff;
struct Fam{
	int id,member;
	double num,area;
	bool flag;
}fam[maxn];
struct Data{
	int id,num,area;
}data[maxn];
int father[maxn],n,cnt=0;
bool vis[maxn];
bool cmp(Fam a,Fam b){
	if(a.area!=b.area) return a.area>b.area;
	else return a.id<b.id;
}
void init(){
	for(int i=0;i<maxn;i++){
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
		if(faa<fab){
		father[fab]=faa;
		}else father[faa]=fab;
	}
}
int main(){
	init();
	cin>>n;
	for(int i=0;i<n;i++){
		int father,mother,k,child,num;
		cin>>data[i].id>>father>>mother>>k;
		vis[data[i].id]=true;
		if(father!=-1){
			Union(data[i].id,father);
			vis[father]=true;
		} 
		if(mother!=-1) {
			Union(data[i].id,mother);
			vis[mother]=true;
		}
		for(int j=0;j<k;j++){
			cin>>child;
			Union(data[i].id,child);
			vis[child]=true;
		}
		cin>>data[i].num>>data[i].area;
	}
	for(int i=0;i<n;i++){  //只检查n个人的根节点即可，因为每个人此时已经与自己的父母孩子共享根节点为同一个 
		int id=find(data[i].id);
		fam[id].id=id;
		fam[id].num+=data[i].num;
		fam[id].area+=data[i].area;
		fam[id].flag=true;
	}
	for(int i=0;i<maxn;i++){
		if(vis[i]){
			fam[find(i)].member++;
		}
		if(fam[i].flag) cnt++;
	}
	for(int i=0;i<maxn;i++){
		if(fam[i].flag){
			fam[i].num=(fam[i].num/fam[i].member);
			fam[i].area=(fam[i].area/fam[i].member);
		}
	}
	sort(fam,fam+maxn,cmp);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%04d %d %.3f %.3f\n",fam[i].id,fam[i].member,fam[i].num,fam[i].area);
	}
	return 0;
} 

