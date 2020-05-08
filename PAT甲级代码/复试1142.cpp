#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
vector<int>temp;
int G[maxn][maxn],nv,ne,m,k,num;
bool judge(vector<int> temp){
	for(int i=0;i<temp.size()-1;i++){
		int j=i+1;
		while(j<temp.size()){
			if(G[temp[i]][temp[j]]) j++;
			else return false;
		}
	}
	return true;
}
bool issame(int x,vector<int> temp){
	for(int i=0;i<temp.size();i++){
		if(x==temp[i]) return true;
	}
	return false;
}
int main(){
	scanf("%d%d",&nv,&ne);
	int a,b;
	for(int i=0;i<ne;i++){
		scanf("%d%d",&a,&b);
		G[a][b]=G[b][a]=1;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		temp.clear();
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&num);
			temp.push_back(num);
		}
		bool flag=judge(temp);
		if(flag==false){
			printf("Not a Clique\n");
		}else{
			bool tag=true;
			for(int j=1;j<=nv;j++){
				if(issame(j,temp)==false){
					int u;
					for(u=0;u<temp.size();u++){
						if(G[j][temp[u]]==0) {
							break;
						}
					}
					if(u==temp.size()) tag=false;
				}
				if(tag==false) break;
			}
			if(tag) printf("Yes\n");
			else printf("Not Maximal\n");
		}
	}
	return 0;
} 
