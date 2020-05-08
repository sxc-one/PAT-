#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
int G[maxn][maxn],d[maxn],weight[maxn],c,n,sp,m,minremain=INF,minneed=INF;
vector<int>pre[maxn],temp,ans;
bool vis[maxn];
void dijk(){
	fill(d,d+maxn,INF);
	d[0]=0;
	for(int i=0;i<=n;i++){
		int u=-1,min=INF;
		for(int j=0;j<=n;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<=n;v++){
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
	if(v==0){
		temp.push_back(v);
		int need=0,remain=0;
		for(int i=temp.size()-1;i>=0;i--){
			int now=temp[i];
			if(weight[now]>0){
				remain+=weight[now];
			}else{
				if(abs(weight[now])<remain){
					remain-=abs(weight[now]);
				}else{
					need+=abs(weight[now])-remain;
					remain=0;
				}
			}
		}
		if(need<minneed){
			minneed=need;
			minremain=remain;
			ans=temp;
		}else if(need==minneed&&remain<minremain){
			minremain=remain;
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
	scanf("%d%d%d%d",&c,&n,&sp,&m);
	c/=2;
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=c;
	}
	int a,b,data;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&data);
		G[a][b]=G[b][a]=data;
	}
	dijk();
	DFS(sp);
	printf("%d ",minneed);
	for(int i=ans.size()-1;i>=0;i--){
		printf("%d",ans[i]);
		if(i!=0) printf("->");	
	}
	printf(" %d",minremain);
	return 0;
}
