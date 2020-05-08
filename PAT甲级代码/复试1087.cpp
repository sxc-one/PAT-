#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
const int INF=0x3fffffff;
int G[maxn][maxn],d[maxn],w[maxn],weight[maxn],n,k,num[maxn],ed,pn[maxn],pre[maxn];
bool vis[maxn];
map<string,int>strtoint;
map<int,string>inttostr;
void dijk(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	num[s]=1;
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
					num[v]=num[u];
					w[v]=w[u]+weight[v];
					pre[v]=u;
					pn[v]=pn[u]+1;
					
				}else if(d[u]+G[u][v]==d[v]){
					num[v]+=num[u];
					if(w[u]+weight[v]>w[v]){
						w[v]=w[u]+weight[v];
						pre[v]=u;
						pn[v]=pn[u]+1;
					}else if(w[u]+weight[v]==w[v]){
						int uavg=(w[u]+weight[v])/(pn[u]+1);
						int vavg=w[v]/pn[v];
						if(uavg>vavg){
							pn[v]=pn[u]+1;
							pre[v]=u;
						}
					}
				}
			}
		}
	}
} 
void dfs(int v){
	if(v==0){
		cout<<inttostr[v];
		return;
	}
	dfs(pre[v]);
	cout<<"->"<<inttostr[v];
}
int main(){
	string start,str1,str2;
	cin>>n>>k>>start;
	strtoint[start]=0;
	inttostr[0]=start;
	for(int i=1;i<n;i++){
		cin>>str1>>weight[i];
		strtoint[str1]=i;
		inttostr[i]=str1;
		if(str1=="ROM") ed=i;
	}
	fill(G[0],G[0]+maxn*maxn,INF);
	int data,a,b;
	for(int i=0;i<k;i++){
		cin>>str1>>str2>>data;
		a=strtoint[str1];
		b=strtoint[str2];
		G[a][b]=G[b][a]=data;
	}
	dijk(0);
	printf("%d %d %d %d\n",num[ed],d[ed],w[ed],w[ed]/pn[ed]);
	dfs(ed);
	return 0;
}
/*
int G[maxn][maxn],d[maxn],w[maxn],n,k,num[maxn],ed,totalh=-1,totalavg=-1;
bool vis[maxn];
vector<int>temp,ans,pre[maxn];
map<string,int>strtoint;
map<int,string>inttostr;
void dijk(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	num[s]=1;
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
					num[v]=num[u];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					num[v]+=num[u];
					pre[v].push_back(u);
				}
			}
		}
	}
} 
void dfs(int v){
	if(v==0){
		temp.push_back(v);
		int hap=0,avg=0;
		for(int i=0;i<temp.size();i++){
			hap+=w[temp[i]];
		}
		avg=hap/(temp.size()-1);
		if(hap>totalh){
			totalh=hap;
			totalavg=avg;
			ans=temp;
		}else if(hap==totalh&&avg>totalavg){
			totalavg=avg;
			ans=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		dfs(pre[v][i]);
	}
	temp.pop_back();
}
int main(){
	string start,str1,str2;
	cin>>n>>k>>start;
	strtoint[start]=0;
	inttostr[0]=start;
	for(int i=1;i<n;i++){
		cin>>str1>>w[i];
		strtoint[str1]=i;
		inttostr[i]=str1;
		if(str1=="ROM") ed=i;
	}
	fill(G[0],G[0]+maxn*maxn,INF);
	int data,a,b;
	for(int i=0;i<k;i++){
		cin>>str1>>str2>>data;
		a=strtoint[str1];
		b=strtoint[str2];
		G[a][b]=G[b][a]=data;
	}
	dijk(0);
	dfs(ed);
	printf("%d %d %d %d\n",num[ed],d[ed],totalh,totalavg);
	cout<<start;
	for(int i=ans.size()-2;i>=0;i--){
		cout<<"->"<<inttostr[ans[i]];
	}
	return 0;
}*/
