#include<bits/stdc++.h>
using namespace std;
const int maxn=1020;
const int INF=0x3fffffff;
int G[maxn][maxn],d[maxn],n,m,k,ds;
bool vis[maxn];
void dijk(int s){
	fill(d,d+maxn,INF);
	memset(vis,false,sizeof(vis));
	d[s]=0;
	for(int i=0;i<n+m;i++){
		int u=-1,min=INF;
		for(int j=1;j<=n+m;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=1;v<=n+m;v++){
			if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
			} 
		} 
	}
}
int change(char str[]){
	int len=strlen(str),i=0,id=0;
	while(i<len){
		if(str[i]!='G'){
			id=id*10+str[i]-'0';
		}
		i++;
	}
	if(str[0]=='G') return n+id;
	else return id;
}
int main(){
	int loc=-1;
	int maxavg=INF,maxd=-1;
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	char str1[10],str2[10];
	int data,a,b;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<k;i++){
		scanf("%s%s%d",str1,str2,&data);
		a=change(str1);
		b=change(str2);
		G[a][b]=G[b][a]=data;
	}
	for(int i=n+1;i<=n+m;i++){
		dijk(i);
		int mind=INF,avg=0;
		int j;
		for(j=1;j<=n;j++){
			if(d[j]>ds) break;
			avg+=d[j];
			if(d[j]<mind){
				mind=d[j];
			}
		}
		if(j>n&&mind>maxd){
			maxd=mind;
			loc=i;
			maxavg=avg;
		}else if(j>n&&mind==maxd&&avg<maxavg){
			loc=i;
			maxavg=avg;
		}
	}
	if(loc==-1) printf("No Solution\n");
	else{
		printf("G%d\n",loc-n);
		printf("%.1f %.1f",1.0*maxd,1.0*maxavg/n);
	}
	return 0;
}
