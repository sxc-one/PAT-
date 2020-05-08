#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
vector<int>adj[maxn];
bool vis[maxn];
void dfs(int s){
	vis[s]=true;
	for(int i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false) dfs(adj[s][i]);
	}
}
int main(){
    int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int odd=0;
	for(int i=1;i<=n;i++){
		if(adj[i].size()%2==1) odd++;
		printf("%d",adj[i].size());
		if(i!=n) printf(" ");
		else printf("\n");
	}
	dfs(1);
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			flag=false;
			break;
		}
	}
	if(flag&&odd==0) printf("Eulerian");
	else if(flag&&odd==2) printf("Semi-Eulerian");
	else printf("Non-Eulerian");
	return 0;
}
