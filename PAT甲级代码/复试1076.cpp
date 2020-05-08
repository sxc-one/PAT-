#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
struct node{
	int id,layer;
};
vector<node>adj[maxn];
bool inq[maxn];
int BFS(int s,int l){
	int num=0;
	node start;
	start.id=s,start.layer=0;
	queue<node>q;
	q.push(start);
	inq[start.id]=true;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		int u=now.id;
		for(int i=0;i<adj[u].size();i++){
			node next=adj[u][i];
			next.layer=now.layer+1;
			if(inq[next.id]==false&&next.layer<=l){
				q.push(next);
				inq[next.id]=true;
				num++;
			}
		}
	}
	return num;
}
int main(){
	node user;
	int n,l,k,p;
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		user.id=i;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&p);
			adj[p].push_back(user);
		}
	}
	int numq,s;
	scanf("%d",&numq);
	for(int i=0;i<numq;i++){
		memset(inq,false,sizeof(inq));
		scanf("%d",&s);
		int num=BFS(s,l);
		printf("%d\n",num);
	}
	return 0;
}
