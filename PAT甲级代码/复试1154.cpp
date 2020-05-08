#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<int>adj[maxn];
int color[maxn];
set<int>num;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int query;
	scanf("%d",&query);
	for(int i=0;i<query;i++){
		bool flag=true;
		num.clear();
		for(int j=0;j<n;j++){
			scanf("%d",&color[j]);
			num.insert(color[j]);
		}
		for(int j=0;j<n;j++){
			for(int u=0;u<adj[j].size();u++){
				if(color[j]==color[adj[j][u]]) {
					flag=false;
					break;
				}
			}
			if(flag==false) break;
		}
		if(flag==false) printf("No\n");
		else{
			printf("%d-coloring\n",num.size());
		}
	}
	return 0;
}
