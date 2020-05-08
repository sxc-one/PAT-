#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
bool flag[maxn];
vector<int>adj[maxn];
int main(){
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	scanf("%d",&q);
	while(q--){
		memset(flag,false,sizeof(flag));
		int k,num=0;
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			int a;
			scanf("%d",&a);
			flag[a]=true;
			for(int j=0;j<adj[a].size();j++){
				int b=adj[a][j];
				if(flag[b]==false) num++;
			}
		}
		if(num==m) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
