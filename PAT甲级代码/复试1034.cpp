#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
map<string,int>strtoint;
map<int,string>inttostr;
map<string,int>gang;
int father[maxn],root[maxn],w[maxn],total[maxn];
int n,k,id;
void init(){
	for(int i=0;i<n;i++){
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
	if(w[faa]<w[a]){  //因为又加了一波点权，此时孩子的权值可能超过根节点，则要重新调整，让点权大的当根节点 
		total[a]=total[faa];//把总点权移到新祖先位置下 
		father[a]=a;
		father[faa]=a;
		faa=a;
		
	}
	int fab=find(b);
	if(w[fab]<w[b]){
		total[b]=total[fab];
		father[b]=b;
		father[fab]=b;
		fab=b;
	}
	if(faa!=fab){
		if(w[faa]>w[fab]){
			father[fab]=faa;
		}else father[faa]=fab;
	}
}
int change(string str){
	if(strtoint.count(str)){
		return strtoint[str];
	}else{
		strtoint[str]=id;
		inttostr[id]=str;
		return id++;
	}
}
int main(){
	
	cin>>n>>k;
	init();
	string str1,str2;
	int data;
	for(int i=0;i<n;i++){
		cin>>str1>>str2>>data;
		int id1=change(str1);
		int id2=change(str2);
		w[id1]+=data;
		w[id2]+=data;
		Union(id1,id2);
		total[find(id1)]+=data;
	}
	for(int i=0;i<id;i++){
		root[find(i)]++;
	}
	for(int i=0;i<id;i++){
		if(root[i]>2&&total[i]>k){
			gang[inttostr[i]]=root[i];
		}
	}
	cout<<gang.size()<<endl;
	for(auto it=gang.begin();it!=gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
/* 
int G[maxn][maxn],w[maxn],n,k,head,mnum,id,total;
bool vis[maxn];
map<string,int>strtoint;
map<int,string>inttostr;
map<string,int>gang;
void DFS(int index){
	vis[index]=true;
	mnum++;
	if(w[index]>w[head]){
		head=index;
	}
	for(int i=0;i<id;i++){
		if(G[index][i]>0){
			total+=G[index][i];
			G[index][i]=G[i][index]=0;
			if(vis[i]==false) DFS(i);
		}
	}
}
void DFSall(){
	for(int i=0;i<id;i++){
		if(vis[i]==false){
			head=i,mnum=0,total=0;
			DFS(i);
			if(mnum>2&&total>k){
				gang[inttostr[head]]=mnum;
			}
		}
	}
}
int change(string str){
	if(strtoint.count(str)){
		return strtoint[str];
	}else{
		strtoint[str]=id;
		inttostr[id]=str;
		return id++;
	}
}
int main(){
	cin>>n>>k;
	string str1,str2;
	int data;
	for(int i=0;i<n;i++){
		cin>>str1>>str2>>data;
		int id1=change(str1);
		int id2=change(str2);
		w[id1]+=data;
		w[id2]+=data;
		G[id1][id2]+=data;
		G[id2][id1]+=data;
	}
	DFSall();
	cout<<gang.size()<<endl;
	for(auto it=gang.begin();it!=gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}*/ 
