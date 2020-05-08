#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=210;
int G[maxn][maxn],path[maxn],n,m,q,pos,minans=0x3fffffff;
bool hasht[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b,data;
		scanf("%d%d%d",&a,&b,&data);
		G[a][b]=G[b][a]=data;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		memset(hasht,0,sizeof(hasht));
		int k,naa=0,ans=0,notcycle=0;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&path[j]);
			hasht[path[j]]=true;
		}
		for(int j=0;j<k-1;j++){
			int next=j+1;
			if(G[path[j]][path[next]]==0){
				naa=1;
				break;
			}
		}
		if(naa==1) {
			printf("Path %d: NA (Not a TS cycle)\n",i);
			continue;
		}
		for(int j=0;j<k-1;j++){
			int next=j+1;
			ans+=G[path[j]][path[next]];
		}
		printf("Path %d: %d ",i,ans);
		for(int j=1;j<=n;j++){
			if(hasht[j]==false) {
	            notcycle=1;
				break;
		    }
	    }
		if(path[0]==path[k-1]&&notcycle==0){
			if(ans<minans){
		    		minans=ans;
		    		pos=i;
				}
			if(k==n+1) 	printf("(TS simple cycle)\n");
			else if(k>n+1) 	printf("(TS cycle)\n");
		}else{
			printf("(Not a TS cycle)\n");
		}
	}
		printf("Shortest Dist(%d) = %d\n",pos,minans);
	return 0;
}
