#include<bits/stdc++.h>
using namespace std;
int m,n,l,t;
struct Node{
	int x,y,z;
}node;
bool inq[1290][130][61];
int pixel[1290][130][61];
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool judge(int x,int y,int z){
	if(x<0||x>=n||y<0||y>=m||z<0||z>=l) return false;
	if(pixel[x][y][z]==0||inq[x][y][z]==true) return false;
	return true;
}
int BFS(int x,int y,int z){
	int tot=0;
	queue<Node>q;
	node.x=x,node.y=y,node.z=z;
	q.push(node);
	inq[x][y][z]=true;
	while(!q.empty()){
		Node top=q.front();
		q.pop();
		tot++;
		for(int i=0;i<6;i++){
			int newx=top.x+X[i];
			int newy=top.y+Y[i];
			int newz=top.z+Z[i];
			if(judge(newx,newy,newz)){
				node.x=newx,node.y=newy,node.z=newz;
				q.push(node);
				inq[newx][newy][newz]=true;
			}
		}
	}
	if(tot>=t) return tot;
	else return 0;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&l,&t);
	for(int z=0;z<l;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				scanf("%d",&pixel[x][y][z]);
			}
		}
	}
	int ans=0;
	for(int z=0;z<l;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(pixel[x][y][z]==1&&inq[x][y][z]==false){
					ans+=BFS(x,y,z);
				}
			}
	 }
	}
	printf("%d",ans);
	return 0;
}
