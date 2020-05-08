#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
int G[maxn][maxn],d[maxn],cost[maxn][maxn],c[maxn],n,m,pre[maxn],st,ed,pn[maxn],flag=1;
bool vis[maxn];
vector<int>path1,path2;
void dijk(int s){
	memset(vis,false,sizeof(vis));
	fill(c,c+maxn,INF);
	c[s]=0;
	for(int i=0;i<n;i++){
		pre[i]=i;
	}
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(flag==1){
				if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}}else if(flag==2){
				if(vis[j]==false&&c[j]<min){
				min=c[j];
				u=j;
			}
			}
		}
		if(u==-1) return;
		vis[u]=true;
		if(flag==1){
			for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}else if(d[u]+G[u][v]==d[v]&&c[u]+cost[u][v]<c[v]){
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}
			}
		}
		}
		else if(flag==2){
			for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(c[u]+cost[u][v]<c[v]){
					c[v]=c[u]+cost[u][v];
					pn[v]=pn[u]+1;
					pre[v]=u;
				}else if(c[u]+cost[u][v]==c[v]){
					if(pn[u]+1<pn[v]){
						pre[v]=u;
						pn[v]=pn[u]+1;
					}
					
				}
			}
		}
		}
	}
}
void dfs(int v){
	if(v==st){
		if(flag==1) path1.push_back(v);
		else if(flag==2) path2.push_back(v);
		return;
	}
	dfs(pre[v]);
	if(flag==1) path1.push_back(v);
	else if(flag==2) path2.push_back(v);
}
int main(){
	scanf("%d%d",&n,&m);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		int a,b,tag,x,y;
		scanf("%d%d%d%d%d",&a,&b,&tag,&x,&y);
		if(tag==1){
			G[a][b]=x;
			cost[a][b]=y;
		}else if(tag==0){
			G[a][b]=G[b][a]=x;
			cost[a][b]=cost[b][a]=y;
		}
	}
	scanf("%d%d",&st,&ed);
	fill(d,d+maxn,INF);
	d[st]=0;
	dijk(st);
	dfs(ed);
	flag=2;
	dijk(st);
	dfs(ed);
	if(path1==path2){
		printf("Distance = %d; Time = %d: %d",d[ed],c[ed],st);
		for(int i=1;i<path1.size();i++){
			printf(" -> %d",path1[i]);
		}
	}else{
		printf("Distance = %d: %d",d[ed],st);
		for(int i=1;i<path1.size();i++){
			printf(" -> %d",path1[i]);
		}
		printf("\n");
		printf("Time = %d: %d",c[ed],st);
		for(int i=1;i<path2.size();i++){
			printf(" -> %d",path2[i]);
		}
	}
	return 0;
}
