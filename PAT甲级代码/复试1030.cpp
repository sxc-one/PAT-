#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
int G[maxn][maxn],d[maxn],cost[maxn][maxn],n,m,s,e;
int minv=INF;
bool vis[maxn];
vector<int>temp,ans,pre[maxn];
void dijk(int st){
	fill(d,d+maxn,INF);
	d[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v){
	if(v==s){
		temp.push_back(v);
		int value=0;
		for(int i=temp.size()-1;i>0;i--){
			int now=temp[i],next=temp[i-1];
			value+=cost[now][next];
		}
		if(value<minv){
			minv=value;
			ans=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	temp.pop_back();
}
int main(){
	int a,b,x,y;
	scanf("%d%d%d%d",&n,&m,&s,&e);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&x,&y);
		G[a][b]=G[b][a]=x;
		cost[a][b]=cost[b][a]=y;
	}
	dijk(s);
	DFS(e);
	for(int i=ans.size()-1;i>=0;i--){
		printf("%d ",ans[i]);
	}
	printf("%d %d",d[e],minv);
	return 0;
}
/*int G[maxn][maxn],d[maxn],cost[maxn][maxn],c[maxn],pre[maxn],n,m,s,e;
bool vis[maxn];
void dijk(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	fill(c,c+maxn,INF);
	c[s]=0;
	for(int i=0;i<n;i++){
		pre[i]=i;
	}
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
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
}
void DFS(int s,int v){
	if(v==s){
		printf("%d ",s);
		return;
	}
	DFS(s,pre[v]);
	printf("%d ",v);
}
int main(){
	int a,b,x,y;
	scanf("%d%d%d%d",&n,&m,&s,&e);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&x,&y);
		G[a][b]=G[b][a]=x;
		cost[a][b]=cost[b][a]=y;
	}
	dijk(s);
	DFS(s,e);
	printf("%d %d",d[e],c[e]);
	return 0;
}*/
