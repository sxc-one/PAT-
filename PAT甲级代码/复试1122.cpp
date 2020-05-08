#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int path[maxn],G[maxn][maxn];
bool vis[maxn];
int main(){
	int n,m,a,b,q;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		G[a][b]=G[b][a]=1;
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		memset(vis,false,sizeof(vis));
		bool flag=true;
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&path[j]);
			vis[path[j]]=true;
		}
		if(k!=n+1) printf("NO\n");
		else if(k==n+1&&path[0]!=path[k-1]) printf("NO\n");
		else if(k==n+1&&path[0]==path[k-1]){
			for(int j=1;j<=n;j++){
				if(vis[j]==false){
					flag=false;
					break;
				}
			}
			for(int j=0;j<k-1;j++){
				int now=path[j],next=path[j+1];
				if(G[now][next]!=1){
					flag=false;
					break;
				}
			}
		    if(flag)	printf("YES\n");
		    else printf("NO\n");
		} 
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int G[maxn][maxn],n,m;
int table[maxn],Count[maxn];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		G[a][b]=G[b][a]=1;
	}
	int q;
	cin>>q;
	while(q--){
		int k;
		bool flag=true;
		cin>>k;
		memset(Count,0,sizeof(Count));
		for(int i=0;i<k;i++){
			cin>>table[i];
			Count[table[i]]++;
		}
		if(Count[table[0]]!=2||Count[table[k-1]]!=2) flag=false;
		if(table[0]!=table[k-1]) flag=false;
		for(int i=0;i<k-1;i++){
			int j=i+1;
			if(G[table[i]][table[j]]!=1) flag=false;
		}
		for(int i=1;i<=n;i++){
			if(Count[i]==0) flag=false;
		}
		if(!flag){
			printf("NO\n");
		}else{
			printf("YES\n");
		}	
	}
	return 0;
} 
*/
