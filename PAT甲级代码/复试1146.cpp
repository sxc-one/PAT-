#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
vector<int>adj[maxn],ans;
int indeg[maxn],temp[maxn],n,m;
int main(){
	int a,b,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		temp[b]++;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int num;
		bool flag=true;
		for(int i=1;i<=n;i++){
		indeg[i]=temp[i];
	}
		for(int j=0;j<n;j++){
			scanf("%d",&num);
			if(indeg[num]==0){
				for(int x=0;x<adj[num].size();x++){
					int u=adj[num][x];
					indeg[u]--;
				}
	            
			}else flag=false;
		}
		if(flag==false){
			ans.push_back(i);
		}
	}
	for(int i=0;i<ans.size();i++){   //printf("%s%d",space?" ":"",k);   space=true;   另一种处理不知道一共有几个数据时空格的方法，挺巧的 ，开始space为false 
		printf("%d",ans[i]);
		if(i!=ans.size()-1) printf(" ");
	} 
	return 0;
}
