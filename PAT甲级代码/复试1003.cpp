#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
int G[maxn][maxn],n,m,d[maxn],w[maxn],weight[maxn],num[maxn];
bool vis[maxn];
void Dijk(){
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(d[j]<min&&vis[j]==false){
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				}else if(d[u]+G[u][v]==d[v]){
					if(w[u]+weight[v]>w[v])
					w[v]=w[u]+weight[v];
					num[v]+=num[u];
				}
			}
		}
	}
}
int main(){
	fill(G[0],G[0]+maxn*maxn,INF);
	int a,b,s,e,data;
	scanf("%d%d%d%d",&n,&m,&s,&e);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&data);
		G[a][b]=G[b][a]=data;
	}
	fill(d,d+maxn,INF);
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	Dijk();
	printf("%d ",num[e]);
	printf("%d",w[e]);
	return 0;
}
