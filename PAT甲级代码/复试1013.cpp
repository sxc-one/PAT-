#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int father[maxn];
bool vis[maxn];
vector<int>G[maxn];
void init(){
	for(int i=1;i<maxn;i++){
		father[i]=i;
		vis[i]=false;
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
	int n,m,k,c1,c2;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		G[c1].push_back(c2);
		G[c2].push_back(c1);
	}
	int now;
	for(int i=0;i<k;i++){
		init();
		scanf("%d",&now);
		for(int u=1;u<=n;u++){
			for(int j=0;j<G[u].size();j++){
				int v=G[u][j];
				if(u==now||v==now) continue;
				Union(u,v);
			}
		}
		int block=0;
		for(int i=1;i<=n;i++){
			if(i==now) continue;
			if(vis[find(i)]==false){
				vis[find(i)]=true;
				block++;
			}
		}
		printf("%d\n",block-1);
}
return 0;}
/*int G[maxn][maxn];
bool vis[maxn];
int n;
void DFS(int u,int now){
	vis[u]=true;
	for(int i=1;i<=n;i++){
		if(G[u][i]>0&&vis[i]==false&&i!=now){
			DFS(i,now);
		}
	}
}
int main(){
	int m,k,c1,c2;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		G[c1][c2]=G[c2][c1]=1;
	}
	int now,block;
	for(int i=0;i<k;i++){
		memset(vis,false,sizeof(vis));
		block=0;
		scanf("%d",&now);
		for(int j=1;j<=n;j++){
			if(vis[j]==false&&j!=now){
				DFS(j,now);
				block++;
			}
		}
		printf("%d\n",block-1);
	}
}*/
